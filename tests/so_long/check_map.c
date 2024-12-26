/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:34:52 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/26 15:36:58 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
    i -> char[i][]
    j -> char[][j]
*/

void check_map(t_slong *game)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while(game->map_data[i][j])
    {
        if(game->map_data[i][j] == 'E')
        {
            count++;
        }
    }
    if (count != 1)
    {
        exit(EXIT_FAILURE);
    }
}


// 111111 -> char *
// "111111" char ** char[0][0]
// "101000" 