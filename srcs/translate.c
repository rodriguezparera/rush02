/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimunoz- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:49:13 by dimunoz-          #+#    #+#             */
/*   Updated: 2024/07/20 13:49:13 by dimunoz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
int getdec(int nb)
{ 
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else  
		return (0);
}
 
int getmult(int nb)
{ 
	if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}



int main(void)
{
	int	x = 1234;
	int d = 4;
	
	return (0);
}