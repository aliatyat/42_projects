/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 16:39:20 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/31 19:54:10 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int main()
{
	char ar[10] = "Hello12";
	printf("befor: %s\n", ar);

	ft_bzero(ar, 5);

	printf("after: %s\n", ar);
return (0);
}
*/
