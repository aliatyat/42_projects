/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:55:00 by alalauty          #+#    #+#             */
/*   Updated: 2024/08/30 19:33:45 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char n, int fd)
{
	write(fd, &n, 1);
}

/*
int main()
{
	int fd;
    char ch = 'A';

   
    fd = open("fd/output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
 
        write(2, "Error opening file\n", 19);
        return 1;
    }

    ft_putchar(ch, fd);

    close(fd);  

    return 0;
}
*/
