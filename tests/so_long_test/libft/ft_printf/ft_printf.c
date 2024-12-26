/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:06:54 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 18:51:50 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	ft_format(char v, va_list args)
{
	int	c;

	c = 0;
	if (v == 'd' || v == 'i')
		return (c += ft_putnbr(va_arg(args, int)));
	else if (v == 's')
		return (c += ft_putstr(va_arg(args, char *)));
	else if (v == 'c')
		return (c += ft_putchar(va_arg(args, int)));
	else if (v == 'X')
		return (c += ft_puthex(va_arg(args, unsigned int), 1));
	else if (v == 'x')
		return (c += ft_puthex(va_arg(args, unsigned int), 0));
	else if (v == 'p')
		return (c += ft_print_pointer(va_arg(args, size_t)));
	else if (v == 'u')
		return (c += ft_putunsigned(va_arg(args, unsigned int)));
	else if (v == '%')
		return (c += ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)

{
	va_list		args;
	int			i;
	int			c;

	va_start(args, format);
	i = 0;
	c = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			c += ft_format(format[i], args);
		}
		else
			c += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (c);
}
