/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <alalauty@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:12:59 by alalauty          #+#    #+#             */
/*   Updated: 2024/12/23 20:13:02 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keys_hook(int keycode, t_slong *param)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(param->mlx);
		mlx_destroy_window(param->mlx, param->win);
		return (0);
	}
	if( keycode == XK_w)
		param->y -= 50;
	if( keycode == XK_s)
		param->y += 50;
	if( keycode == XK_d)
		param->x += 50;
	if( keycode == XK_a)
		param->x -= 50;
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, param->x, param->y);
	return (0);
}

int	exit_hook(t_slong *param)
{
	mlx_loop_end(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	return (0);
}
void print_map(t_slong *game)
{
    int i = 0;
    while (game->map_data[i])
    {
        ft_printf("%s\n", game->map_data[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    t_slong	slong;
    // int width, height;
    if (ac != 2)
    {
        exit(EXIT_FAILURE);
    }
    ft_bzero(&slong ,sizeof(t_slong));
    // Read the map
    save_for_map(av[1]  ,&slong );
    print_map(&slong);






    
    return 0;
    
    // if (!map)
    // {
    //     printf("Failed to load map.\n");
    //     return (1);
    // }

    // slong = calloc(1, sizeof(t_slong));
    // slong.mlx = mlx_init();
    // slong.win = mlx_new_window(slong.mlx, slong.map_width * 100, slong.map_height * 100, "so_long");

    // slong.img = mlx_xpm_file_to_image(slong.mlx, "ghost.xpm", &slong.map_width, &slong.map_height);

    // // Render the map
    // for (int y = 0; y < slong.map_height; y++)
    // {
    //     for (int x = 0; x < slong.map_width; x++)
    //     {
    //         if (slong.map_data[y][x] == '1') 
    //             mlx_put_image_to_window(slong.mlx, slong.win, slong.img, x * 10, y * 10);
    //     }
    // }

    // mlx_hook(slong.win, 2, 1L << 0, keys_hook, &slong);
    // mlx_hook(slong.win, 17, 0, exit_hook, &slong);
    // mlx_loop(slong.mlx);

    // // Free allocated memory
    // for (int i = 0; i < slong.map_height; i++)
    //     free(slong.map_data[i]);
    // free(slong.map_data);
    // // free(&map);

    // free(slong.mlx);
    // // free(&slong);

    // return 0;
}

