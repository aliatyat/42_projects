/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:46:53 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 15:33:28 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(size_t num, int upper)
{
	char	*base;
	int		c;

	c = 0;
	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (num >= 16)
		c += ft_puthex (num / 16, upper);
	c += ft_putchar(base[num % 16]);
	return (c);
}

/*
int main()
{
	ft_putchar('\n');
	ft_puthex(123, 0);
	ft_putchar('\n');
	return (0);
}
*/
