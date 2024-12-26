/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:42:32 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/27 19:56:43 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	ch = (unsigned char)c;
	while (n > i)
	{
		if (str[i] == ch)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	const char	str[];
	char		*res;

	str[] = "Ali Alautyat";
	res = ft_memchr(str, 'a', 5);
	
	if (res != NULL)
		printf("found: %ld\n", res - str);
	else 
		printf("not found\n");
return (0);
}
*/
