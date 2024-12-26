/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:12:29 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/30 19:31:38 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	if (n == 0)
	{
		return (0);
	}
	x = 0;
	while (s1[x] && s1[x] == s2[x] && x < n - 1)
	{
		x++;
	}
	if (x == n)
		return (0);
	return ((unsigned char) s1[x] - (unsigned char) s2[x]);
}
/*
int	main(void)
{
	unsigned int	n;
	char			s1[];
	char			s2[];

	
	n = 3;
	s1[] = "asddd";
	s2[] = "asDdD";
	ft_strncmp(s1, s2, n);
	if(ft_strncmp(s1, s2, n) == 0)
	{
		printf("equal");
	} 
	else 
	{
	printf("not equal");
	}
return (0);
}
*/
