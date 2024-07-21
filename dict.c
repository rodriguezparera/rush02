/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:13:18 by sarodrig          #+#    #+#             */
/*   Updated: 2024/07/20 13:13:27 by sarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/dict.h"
#include "includes/ft_string.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_number(char c_in)
{
	if ((c_in >= '0') && (c_in <= '9'))
		return (1);
	return (0);
}

int load_dict(t_dict **pdict, char *filepath)
{
	int		file_id;
	char    file_char;
	ssize_t	size;
	int		end_of_file;
	int		num_lines;
	t_dict *p_ini_dict;
	t_dict *p_dict;
	char	key[500]="";
	char	*p_key;
	char	value[500]="";
	char	*p_value;

	num_lines = 0;
	end_of_file = 0;
	if ((file_id = open(filepath, O_RDWR)) == -1)
	{
        printf("Dict Error\n");
		end_of_file = 1;
    }
    while (!end_of_file)
	{
		if ((size = read(file_id, &file_char, 1)) > 0)
		{
			if (file_char == '\n')
				num_lines++;
		}
		else
			end_of_file = 1;
	}
	close(file_id);

	if (!(p_dict = (t_dict *)malloc(sizeof(t_dict) * num_lines+10)))
 		return (0);

	end_of_file = 0;
	if ((file_id = open(filepath, O_RDWR)) == -1)
	{
        printf("Dict Error\n");
		end_of_file = 1;
    }
	size = 0;
	p_ini_dict = p_dict;
    while (!end_of_file)
	{
		// ------------ Store begining chars in key
		p_key = key;
		if ((size = read(file_id, &file_char, 1)) > 0)
		{
			if (is_number(file_char))
				*p_key++ = file_char;
		}
		else
			end_of_file = 1;
		if (size == -1)
		{
			printf("Dict Error\n");
			end_of_file = 1;
		}
		if ((!end_of_file) && (file_char != '\n'))
		{
			while ((!end_of_file) && (is_number(file_char)))
			{
				if ((size = read(file_id, &file_char, 1)) > 0) 
				{
					if (is_number(file_char))
						*p_key++ = file_char;
					//printf("%c", file_char);
				}
				else
					end_of_file = 1;
				if (size == -1)
				{
					printf("Dict Error\n");
					end_of_file = 1;
				}
			}
			*p_key = '\0';

			// ------------ Skip chars with ' ' or ':'
			while ((!end_of_file) && ((file_char == ' ') || (file_char == ':')))
			{
				if ((size = read(file_id, &file_char, 1)) > 0)
					end_of_file = 0;
					//printf("%c", file_char);
				else
					end_of_file = 1;
				if (size == -1)
				{
					printf("Dict Error\n");
					end_of_file = 1;
				}
			}

			// ------------ Store remaining chars in value
			p_value = value;
			if ((!end_of_file) && (file_char != '\n'))
				*p_value++ = file_char;
			while ((!end_of_file) && file_char != '\n')
			{
				if ((size = read(file_id, &file_char, 1)) > 0)
				{
					if  (file_char != '\n')
						*p_value++ = file_char;
					//printf("%c", file_char);
				}
				else
					end_of_file = 1;
				if (size == -1)
				{
					printf("Dict Error\n");
					end_of_file = 1;
				}			
			}
			*p_value = '\0';

			if (!(p_dict->key = (char *)malloc(sizeof(char) * ft_strlen(key)+1)))
				return (0);
			ft_strcpy(p_dict->key, key);
			p_dict->key[ft_strlen(key)] = '\0';
			if (!(p_dict->value = (char *)malloc(sizeof(char) * ft_strlen(value)+1)))
				return (0);
			ft_strcpy(p_dict->value, value);
			p_dict->value[ft_strlen(value)] = '\0';
			p_dict++;
		}
	}
	
	key[0] = '\0';
	if (!(p_dict->key = (char *)malloc(sizeof(char) * ft_strlen(key)+1)))
		return (0);
	ft_strcpy(p_dict->key, key);
	p_dict->key[ft_strlen(key)] = '\0';
	value[0] = '\0';
	if (!(p_dict->value = (char *)malloc(sizeof(char) * ft_strlen(value)+1)))
		return (0);
	ft_strcpy(p_dict->value, value);
	p_dict->value[ft_strlen(value)] = '\0';

	*pdict = p_ini_dict;

	close(file_id);
	return (0);
}

int	get_dict_value(t_dict *dict, char *key, char *value)
{
	t_dict *p_dict = dict;

	while (dict->key)
	{
		if (ft_strcmp(key, dict->key) == 0)
		{
			ft_strcpy(value, dict->value);
			value[ft_strlen(dict->value)] = '\0';
			return(1);
		}
		dict++;
	}
	dict = p_dict;
	return (0);
}

void print_dict(t_dict *dict)
{
	printf("\nPrint dicctionary:");
	while (dict->key[0] != '\0')
	{
		printf("\nKey:%s, Value:%s", dict->key, dict->value);
		dict++;
		
	}
}
