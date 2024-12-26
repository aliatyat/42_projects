/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:03:22 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/04 18:46:02 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	const char		*last;

	last = NULL;
	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			last = s;
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}
/*
int	main(void)
{
	char	str[];
	char	ch;
	char	*c;

	str[] = "Ali Alautyat";
	ch = 'a';
	c = ft_strrchr(str, ch);
	if (c)
	{
	printf("found: %s\n", c - str);
	}
	return (0);
}
*/
