/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:09:11 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 15:31:27 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_strlen_int(char *c)
{
	int	x;

	x = 0;
	while (c[x] != '\0')
	{
		x++;
	}
	return (x);
}

int	ft_putstr(char *s)
{
	int	c;

	c = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	c = ft_strlen_int(s);
	write(1, s, c);
	return (c);
}
/*
int main()
{
	char *s;
	ft_putstr(s);
	printf("%s", s);
	return(0);
}
*/
