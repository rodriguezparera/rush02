#include "includes/ft_string.h"

int ft_strlen(char *str)
{
    int n = 0;
    while (*str) {
        n++;
        str++;
    }
    return n;
}

int ft_strcmp(char *s1, char *s2)
{	
	while (*s1 && *s2)
	{
		if ((*s1-*s2) != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char    *ft_strcpy(char *dest, char *src)
{
	char	*ret;

	ret = dest;
	while (*src)
		*dest++ = *src++;
	return (ret);
}


// int		ft_total_len(char **str, int size, char *sep)
// {
// 	int i;
// 	int cat_size;

// 	cat_size = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		cat_size += ft_strlen(str[i]);
// 		i++;
// 	}
// 	cat_size += (size - 1) * ft_strlen(sep) + 1;
// 	return (cat_size);
// }

// char	*ft_strjoin(int size, char **strs, char *sep)
// {
// 	int		i;
// 	char	*concat;

// 	if (size == 0)
// 	{
// 		concat = (char *)malloc(sizeof(char));
// 		*concat = 0;
// 		return (concat);
// 	}
// 	concat = (char *)malloc(sizeof(char) * ft_total_len(strs, size, sep));
// 	if (!concat)
// 		return (NULL);
// 	*concat = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		ft_strcat(concat, strs[i]);
// 		if (i < size - 1)
// 			ft_strcat(concat, sep);
// 		i++;
// 	}
// 	ft_strcat(concat, "\0");
// 	return (concat);
// }

// char	**ft_split(char *str, char *charset)
// {
// 	char	**s;
// 	char	*tmp;
// 	int		num_words;
// 	int		i;

// 	tmp = str;
// 	i = -1;
// 	num_words = count_words(str, charset);
// 	if (!(s = (char **)malloc(sizeof(char *) * (num_words + 1))))
// 		return (0);
// 	if (!(get_strings(s, tmp, charset)))
// 		return (0);
// 	s[num_words] = 0;
// 	return (s);
// }

// int		count_words(char *str, char *cs)
// {
// 	int c;
// 	int i;

// 	i = 0;
// 	c = 0;
// 	while (str[i])
// 	{
// 		while (is_charset(str[i], cs) && str[i])
// 			i++;
// 		if (!str[i])
// 			break ;
// 		while (is_charset(str[i], cs) == 0 && str[i])
// 			i++;
// 		c++;
// 	}
// 	return (c);
// }