# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarranz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/20 13:51:44 by acarranz          #+#    #+#              #
#    Updated: 2024/07/20 14:05:12 by acarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#FLAGS =  -Wall -Wextra -Werror


#TARGET = rush-02
#SRCSDIR = srcs
#INCDIR = include
#SRCS = $(wildcard $(SRCSdir)/*.c *.c)
#OBJS = $(SRCS:.C=O)

#all:  $(TARGET)

#%.o: %.c
#cc $(CFLAGS) -c $< -o $@ -I $(INCDIR)


#$(TARGET): $(OBJS)
#cc $(FLAGS) -o $@ $^

#clean:
#rm -f $(OBJS)

#fclean: clean
#rm -f $(TARGET)

#re: fclean all

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c dict.c ft_strings.c
OBJS = $(SRCS:.c=.o)
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re