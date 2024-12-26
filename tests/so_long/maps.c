/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:13:32 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/23 20:13:35 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
    filename = fd
    map = so_lone
*/
void check_map_empty(t_slong *game, char *tmp, int fd)
{
    if (!tmp || tmp[0] == '\0')
    {
        ft_printf("Error: empty map\n");
        free(tmp);
        close(fd);
        // free_resources(game);
        exit(EXIT_FAILURE);
    }

    game->map_data = ft_split(tmp, '\n');
    free(tmp);
    close(fd);

    if (!game->map_data)
    {
        ft_printf("Error: memory allocation failed\n");
        // free_resources(game);
        exit(EXIT_FAILURE);
    }
}

void read_for_fd(char *map_file, int *fd, char **tmp)
{
    *fd = open(map_file, O_RDONLY);
    if (*fd == -1)
    {
        ft_printf("Error: open() failed\n");
        exit(EXIT_FAILURE);
    }

    *tmp = ft_strdup("");
    if (!*tmp)
    {
        ft_printf("Error: memory allocation failed\n");
        close(*fd);
        exit(EXIT_FAILURE);
    }
}

void save_for_map(char *map_file, t_slong *game)
{
    int fd;
    char *line;
    char *tmp;

    read_for_fd(map_file, &fd, &tmp);

    while ((line = get_next_line(fd)))
    {
        if (line[0] == '\0')
        {
            free(line);
            break;
        }

        char *new_tmp = ft_strjoin(tmp, line);
        free(tmp);
        free(line);

        if (!new_tmp)
        {
            ft_printf("Error: memory allocation failed\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
        tmp = new_tmp;
    }

    check_map_empty(game, tmp, fd);
}
