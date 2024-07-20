/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:20:19 by sarodrig          #+#    #+#             */
/*   Updated: 2024/07/20 13:20:23 by sarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DICT_H
#	define DICT_H

#define DEFAULT_DICT_SIZE	41
#define READ_MAX_SIZE		100

typedef struct str_dict
{
	char *key;
	char *value;
} t_dict;

int	load_dict(t_dict *dict, char *filepath);
// int	create_dict(t_dict *dict, int num_elements);
int	get_dict_value(t_dict *dict, char *key, char *value);

#	endif