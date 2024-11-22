/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:03:25 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/04 18:45:24 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	z;

	i = 0;
	z = 0;
	while (dest[i])
		i++;
	if (size < i)
	{
		while (src[z])
			z++;
		return (size + z);
	}
	while (size > 0 && src[z] && i < size - 1)
	{
		dest[i++] = src[z++];
	}
	dest[i] = '\0';
	while (src[z++])
		i++;
	return (i);
}
/*
int	main(void)
{
	char			src[50];
	unsigned int	size;

	char dest[50]= "fdag";
	src[50] = "";
	size = 6;
	printf("%d\n", ft_strlcat(dest, src, size));
	printf("dest: %s\n src : %s\n", dest, src);
}
*/
