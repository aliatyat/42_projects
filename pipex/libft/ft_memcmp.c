/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:06:44 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/27 20:06:47 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*x;
	const unsigned char	*z;

	i = 0;
	x = (const unsigned char *)s1;
	z = (const unsigned char *)s2;
	while (n > i)
	{
		if (x[i] != z[i])
			return (x[i] - z[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[];
	char	s2[];
	int		r;
	int		r1;

	s1[] = "asd";
	s2[] = "asDd";
	
 	r = ft_memcmp(s1, s2, 2);
	printf("%d\n", r);
	r1 = ft_memcmp(s1, s2, 3);
        printf("%d", r1);
return (0);
}
*/
