/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:08:06 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 15:32:55 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_pointer(size_t p)
{
	int		c;

	c = 0;
	if (!p)
		c += ft_putstr("(nil)");
	else
	{
		c += ft_putchar('0');
		c += ft_putchar('x');
		c += ft_puthex(p, 0);
	}
	return (c);
}

/*
int main()
{
	int a;
	 ft_print_pointer((size_t)&a);
	return(0);
}
*/
