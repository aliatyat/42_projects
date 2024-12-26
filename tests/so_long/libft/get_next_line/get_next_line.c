/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:53:58 by alalauty          #+#    #+#             */
/*   Updated: 2024/10/14 15:54:01 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

static char	*free_and_return(char *buffer, char **remain)
{
	free(buffer);
	free(*remain);
	*remain = NULL;
	return (NULL);
}

static char	*join_remain_and_buffer(char **remain, char *buffer)
{
	char	*temp;

	temp = *remain;
	*remain = ft_strjoin(temp, buffer);
	free(temp);
	if (*remain == NULL)
		return (NULL);
	return (*remain);
}

static char	*read_buffer(int fd, char **remain)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	while (ft_strchr(*remain, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_and_return(buffer, remain));
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (join_remain_and_buffer(remain, buffer) == NULL)
			return (free_and_return(buffer, remain));
	}
	free(buffer);
	return (*remain);
}

static char	*extract_line(char **remain)
{
	char	*newline;
	char	*line;
	char	*temp;
	int		line_len;

	newline = ft_strchr(*remain, '\n');
	if (newline != NULL)
		line_len = newline - *remain + 1;
	else
		line_len = ft_strlen(*remain);
	line = ft_substr(*remain, 0, line_len);
	if (line == NULL)
		return (free_and_return(NULL, remain));
	temp = *remain;
	if (newline != NULL)
		*remain = ft_strdup(newline + 1);
	else
		*remain = NULL;
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remain[fd] == NULL)
		remain[fd] = ft_strdup("");
	if (remain[fd] == NULL)
		return (NULL);
	if (read_buffer(fd, &remain[fd]) == NULL)
		return (NULL);
	return (extract_line(&remain[fd]));
}
