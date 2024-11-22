/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:14:59 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/03 23:00:39 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*src;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		reslen = ft_strlen(src) + 1;
	else
		reslen = len + 1;
	res = malloc(reslen * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, reslen);
	return (res);
}

/*
int	main(void)
{
	char			original[];
	unsigned int	start;
	size_t			len;
	char			*substring;

    original[] = "Hello, World!";
    start = 7;
    len = 5;
    
    
    substring = ft_strsub(original, start, len);
    
    if (substring)
    {
        printf("Original: %s\n", original);
        printf("Substring: %s\n", substring);
        free(substring); 
    }
    else
    {
        printf("Failed to extract substring.\n");
    }
    
    return (0);
}
*/
