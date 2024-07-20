/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarranz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:31:02 by acarranz          #+#    #+#             */
/*   Updated: 2024/07/20 13:34:46 by acarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int ft_len(const char *str) {
    int n = 0;
    while (*str) {
        n++;
        str++;
    }
    return n;
}


char *str_zeros(const char *str, int n) 
{
    char *new_str = malloc(n + 1); 
   



    for (int i = 0; i < n; i++) {
        new_str[i] = '0'; 
    }
    new_str[n] = '\0'; 

    return new_str;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <cadena>\n", argv[0]);
        return 1;
    }

    int n = ft_len(argv[1]);
    char *copy = str_zeros(argv[1], n); 

    printf("El número es: %s\n", argv[1]);
    printf("El copy es: %s\n", copy);
    printf("El array tiene: %d dígitos\n", n);

    free(copy); 

    return 0;
}
