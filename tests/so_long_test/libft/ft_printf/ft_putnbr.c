/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:09:01 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/28 16:17:50 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(long int num)
{
	int	c;

	c = 0;
	if (num < 0)
	{
		c += ft_putchar('-');
		num *= -1;
	}
	if (num >= 10)
		c += ft_putnbr(num / 10);
	c += ft_putchar(num % 10 + 48);
	return (c);
}

/*
int main()
{
	ft_putchar('\n');
	ft_putnbr(44568546);
	ft_putchar('\n');
	return(0);
}
*/
