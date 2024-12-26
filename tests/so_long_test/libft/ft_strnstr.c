/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:11:19 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/31 22:23:06 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *book, const char *title, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!title && !book)
		return (NULL);
	if (!title[i] || !title[0])
		return ((char *)book);
	i = 0;
	while (book[i] != '\0' && i < len)
	{
		j = 0;
		while (book[i + j] && title[j]
			&& i + j < len && book[i + j] == title[j])
			j++;
		if (!title[j])
			return ((char *)(book + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{

	char book[] = "";
	char *fin = "li";
	char *res = ft_strnstr(book, fin, 0);

	printf("found it: %s\n", res);
	return (0);
}
*/
