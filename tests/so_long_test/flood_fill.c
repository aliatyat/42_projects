/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:12:33 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/23 20:12:36 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_img(t_slong *slong, char tile)
{
	if (tile == '1')
		slong->img = mlx_xpm_file_to_image(slong->mlx, "wall.xpm", &slong->map_width, &slong->map_height);
	else if (tile == '0')
		slong->img1 = mlx_xpm_file_to_image(slong->mlx, "sand.xpm", &slong->map_width, &slong->map_height);
	else if (tile == 'P')
		slong->img2 = mlx_xpm_file_to_image(slong->mlx, "ghost0.xpm", &slong->map_width, &slong->map_height);
	else if (tile == 'C')
		slong->img3 = mlx_xpm_file_to_image(slong->mlx, "pum.xpm", &slong->map_width, &slong->map_height);
	else if (tile == 'E')
		slong->img4 = mlx_xpm_file_to_image(slong->mlx, "door2.xpm", &slong->map_width, &slong->map_height);
}

void	fill(char **map, t_slong size, t_slong cur, char to_fill, t_slong *slong)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || map[cur.y][cur.x] != to_fill)
		return;

	// Render images based on tile type
	if (map[cur.y][cur.x] == '1')
		ft_img(slong, '1');
	else if (map[cur.y][cur.x] == '0')
		ft_img(slong, '0');
	else if (map[cur.y][cur.x] == 'P')
		ft_img(slong, 'P');
	else if (map[cur.y][cur.x] == 'C')
		ft_img(slong, 'C');
	else if (map[cur.y][cur.x] == 'E')
		ft_img(slong, 'E');

	// Mark the tile as filled
	map[cur.y][cur.x] = 'F';

	// Recursive flood fill
	fill(map, size, (t_slong){cur.x - 1, cur.y}, to_fill, slong);
	fill(map, size, (t_slong){cur.x + 1, cur.y}, to_fill, slong);
	fill(map, size, (t_slong){cur.x, cur.y - 1}, to_fill, slong);
	fill(map, size, (t_slong){cur.x, cur.y + 1}, to_fill, slong);
}

void	flood_fill(char **map, t_slong size, t_slong begin, t_slong *slong)
{
	fill(map, size, begin, map[begin.y][begin.x], slong);
}
