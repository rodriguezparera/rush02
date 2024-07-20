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

FLAGS =  -Wall -Wextra -Werror


TARGET = rush-02
SRCSDIR = srcs
INCDIR = include
SRCS = $(wildcard $(SRCSdir)/*.c *.c)
OBJS = $(SRCS:.C=O)

all:  $(TARGET)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -I $(INCDIR)


$(TARGET): $(OBJS)
	cc $(FLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all