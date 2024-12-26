/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:42:12 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 18:42:07 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunsigned(unsigned int num)
{
	int	c;

	c = 0;
	if (num >= 10)
		c += ft_putunsigned(num / 10);
	c += ft_putchar(num % 10 + 48);
	return (c);
}

/*
int main()
{
	ft_putunsigned(457457564);
	return (0);
}
*/
