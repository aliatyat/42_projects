/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:00:53 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/26 15:30:11 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *des, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (srclen);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (srclen);
}
/*
int	main(void)
{
	char		des[];
	const char	src[];
	size_t		size;

	des[] = "sd";
	src[] = "23";
	ft_strlcpy(des, src, size);
	printf("%ld", size);
	return (0);
}
*/
