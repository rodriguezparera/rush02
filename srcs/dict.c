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

#include "../includes/dict.h"
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

int load_dict(t_dict *p_dict, char *filepath)
{
	int		file_id;
	//char	read_buffer[READ_MAX_SIZE] = "Empty File";
	char    file_char;
	// char	*join;
	// char	**s2;
	int		size;
	int		end_of_file;

	if (!(p_dict = (t_dict *)malloc(sizeof(t_dict) * DEFAULT_DICT_SIZE)))
 		return (0);

	if ((file_id = open(filepath, O_RDWR)) == 0)
		return 0;
	size = 0;
	end_of_file = 0;
    while (!end_of_file)
	{
		if ((size = read(file_id, &file_char, 1)) == 1)
		{
			//printf("%c", file_char);
			printf("\nChar Read: %c, size: %d", file_char, size);
			// if (file_char == 'x')
			// 	end_of_file = 1;
		}
		while (!end_of_file && is_number(file_char))
		{
			if ((size = read(file_id, &file_char, 1)) == 0)
			{
				printf("Dict Error\n");
				end_of_file = 1;
			}
			//printf("%c", file_char);
			printf("\nChar Read: %c, size: %d", file_char, size);
			// if (file_char == 'x')
			// 	end_of_file = 1;
		}

		// size = read(file_id, &file_char, 1);
		// printf("%c", file_char);
		// printf("\nChar Read: %c, size: %d", file_char, size);

		// end_of_file = 1;

	}
	close(file_id);
	free(p_dict);
	return (0);
}

// int	create_dict(t_dict *dict, int num_elements)
// {
// 	t_dict *p_dict;
// 	int		index;

// 	index = 0;
// 	if (!(p_dict = (t_dict *)malloc(sizeof(t_dict) * DEFAULT_DICT_SIZE)))
// 		return (0);
// 	while (index < DEFAULT_DICT_SIZE)
// 	{
// 		get_key_value(*str, p_dict[index].key, p_dict[index].value);
// 		index++;
// 		str++;
// 	}
// 	d[i].key = 0;
// 	d[i].value = 0;
// 	return (0);
// }

int	get_dict_value(t_dict *dict, char *key, char *value)
{
	// int i;
	// int j;

	if (key[0] == dict-> key[0])
		value[0] = dict->value[0]; 
	// i = 0;
	// j = i;
	// while (s[i] >= '0' && s[i] <= '9' && s[i])
	// 	i++;
	// ft_strcpy(key, s, j, i);
	// while ((s[i] < 33 || s[i] == 127 || s[i] == ':') && s[i])
	// 	i++;
	// j = i;
	// while (s[i] >= 32 && s[i] <= 126 && s[i])
	// 	i++;
	// ft_strcpy(value, s, j, i);
	return (0);
}
