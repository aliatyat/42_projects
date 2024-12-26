/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:53:44 by alalauty          #+#    #+#             */
/*   Updated: 2024/10/14 15:53:51 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 234
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
// int		ft_strlen(const char *str);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_substr(const char *s, int start, int len);
// char	*ft_strchar(const char *s, int c);
// char	*ft_strdup(const char *s);

#endif
