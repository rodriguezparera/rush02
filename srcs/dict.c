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

int ft_load_dict(t_dict *dict, char *filepath)
{
	int		file_id;
	char	read_buffer[READ_MAX_SIZE];
	char	*join;
	char	**s2;
	int		size;

	file_id = open(filepath, O_RDWR);
	while (read(file_id, read_buffer, READ_MAX_SIZE))
	{
		size = count_words(buf, charset);
		join = ft_strjoin(size, ft_split(read_buffer, charset), " ");
	}
	s2 = ft_split(join, "\n");
	free(join);
	return (s2);
}

int	ft_create_dict(t_dict *, int num_elements)
{
	t_dict *p_dict;
	int		index;

	index = 0;
	if (!(p_dict = (t_dict *)malloc(sizeof(t_dict) * DEFAULT_DICT_SIZE)))
		return (0);
	while (index < DEFAULT_DICT_SIZE)
	{
		get_key_value(*str, p_dict[index].key, p_dict[index].value);
		index++;
		str++;
	}
	d[i].key = 0;
	d[i].value = 0;
	return (d);
}

int	ft_get_dict_value(t_dict *, char *key, char *value)
{
	int i;
	int j;

	i = 0;
	j = i;
	while (s[i] >= '0' && s[i] <= '9' && s[i])
		i++;
	ft_strcpy(key, s, j, i);
	while ((s[i] < 33 || s[i] == 127 || s[i] == ':') && s[i])
		i++;
	j = i;
	while (s[i] >= 32 && s[i] <= 126 && s[i])
		i++;
	ft_strcpy(value, s, j, i);
}
