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

#include <stdio.h>

void multiple(int nbr)
{
    int mult = 0;
    int start;
    int temp;
    int n;

    temp = nbr;
    while (nbr >= 1000)
    {
        nbr /= 1000;
        mult++;
    }
    printf("Número de grupos de 1000: %d\n", mult);

    
      

    n = 0;
    while (start > 0)
    {  
        start = nbr % 1000;  
        printf("Grupo %d: %d\n", n, start);
        nbr /= 1000;  
        n++;
    }
}

int main(void)
{
    int nbr = 12341234;
    multiple(nbr);
    
    return 0;
}