/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:18:52 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/29 17:19:41 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
int main()
{
	char ar[10];
	ft_memset(ar, 42, 10);
	printf("%d %d %d %d %d \n", ar[0], ar[1], ar[2], ar[3], ar[4]);
	return (0);
}
*/
