/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:12:50 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/02 17:13:49 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_str(char *dest, const char *src, size_t *index)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[*index] = src[i];
		(*index)++;
		i++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	copy_str(result, s1, &i);
	copy_str(result, s2, &i);
	result[i] = '\0';
	return (result);
}

/*
int main()
{
char *s1 = "Hello ";
char *s2 = "World!";
char *joined = ft_strjoin(s1, s2);

printf("%s\n", joined); 
free(joined);  
return (0);
}
*/
