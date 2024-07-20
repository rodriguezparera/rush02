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
void zero(int n, number[n-3], number[n-2], number[n-1]) 
{
   
    int size = (n * 3) -1;  
    char *zeros = malloc(size * sizeof(char));

    if (zeros == NULL) 
    {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1);
    }

    zeros[0] = '1';  
    int i = 1;
    while (i < size - 1) 
    {
        zeros[i] = '0';  
        i++;
    }
    zeros[size - 1] = '\0';  

    write_numbers(zeros, number[n-3], number[n-2], number[n-1])
    free(zeros);  
}


int ft_len(const char *str)
{
    int n = 0;
    while (*str) {
        n++;
        str++;
    }
    return n;
}


#include <stdio.h>
#include <string.h>

void detect_series(char *number, int n) 
{
    int groups = 0;
    

    while (n > 0)
    {
        groups++;
        if (n >= 3) 
        {
            printf("Grupo %d: %c%c%c\n", groups, number[n-3], number[n-2], number[n-1]);
            zero(groups, number[n-3], number[n-2], number[n-1]);
        }   
        else 
        {
            printf("Grupo %d: ", groups);
            int j = 0;
            while (j < n) 
            {
                printf("%c", number[j]);
                j++;
            }
            printf("\n");
        }
        n -= 3;
    }

    printf("Total de grupos de tres: %d\n", groups);
}


int main(int argc, char **argv) 
{
    if (argc != 2) {
        
        fprintf(stderr, "Uso: %s <cadena>\n", argv[0]);
        return 1;
    }

    int n = ft_len(argv[1]);
    detect_series(argv[1], n);
    printf("El número es: %s\n", argv[1]);
    printf("El array tiene: %d dígitos\n", n);



    return 0;
}

