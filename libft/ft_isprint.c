/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:08:27 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/25 16:08:53 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)

{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	printf("%d", ft_isprint(30));
	return (0);
}
*/
