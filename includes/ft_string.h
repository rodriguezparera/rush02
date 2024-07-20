#include "dict.h"

#	ifndef FT_H
#	define FT_H

void		ft_putchar(char c);
void		ft_swap(int *a, int *b);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_putnbr(int nb);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcat(char *dest, char *src);
char		*ft_strjoin(int size, char **strs, char *sep);
char		**ft_split(char *str, char *charset);
int			count_words(char *str, char *cs);
char		*ft_strcpy(char *dest, char *src, int k, int j);

#	endif