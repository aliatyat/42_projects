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


int ft_strlen_2d(char **map)
{
    int count = 0;

    while (map[count])
        count++;
    return (count);
}



void render_map(t_slong *game)
{
    int y = 0;
    int x;

    while (game->map_data[y])
    {
        x = 0;
        while (game->map_data[y][x])
        {
            ft_img(game, game->map_data[y][x]);
            mlx_put_image_to_window(game->mlx, game->win, game->img, x * 50, y * 50);
            x++;
        }
        y++;
    }
}

int	keys_hook(int keycode, t_slong *param)
{
	if (keycode == XK_Escape)
	{
		mlx_loop_end(param->mlx);
		mlx_destroy_window(param->mlx, param->win);
		return (0);
	}
	if (keycode == XK_w)
		param->y -= 50;
	if (keycode == XK_s)
		param->y += 50;
	if (keycode == XK_d)
		param->x += 50;
	if (keycode == XK_a)
		param->x -= 50;
	mlx_clear_window(param->mlx, param->win);
	render_map(param);
	mlx_put_image_to_window(param->mlx, param->win, param->img2, param->x, param->y); // Player image
	return (0);
}

int	exit_hook(t_slong *param)
{
	mlx_loop_end(param->mlx);
	mlx_destroy_window(param->mlx, param->win);
	return (0);
}

int	main(int ac, char **av)
{
	t_slong	game;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long <map_file>\n");
		exit(EXIT_FAILURE);
	}

	// Initialize game structure
	ft_bzero(&game, sizeof(t_slong));

	// Read the map
	save_for_map(av[1], &game);
	print_map(&game);

	// Initialize MLX
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_printf("Error: MLX initialization failed\n");
		exit(EXIT_FAILURE);
	}

	// Set window size based on map dimensions
	game.map_width = 50 * ft_strlen(game.map_data[0]); // Assuming each tile is 50px
	game.map_height = 50 * ft_strlen_2d(game.map_data); // Custom function to count rows
	game.win = mlx_new_window(game.mlx, game.map_width, game.map_height, "so_long");

	// Load and render map
	render_map(&game);

	// Set event hooks
	mlx_key_hook(game.win, keys_hook, &game);
	mlx_hook(game.win, 17, 0, exit_hook, &game); // Close window with the X button

	mlx_loop(game.mlx);

	return (0);
}

    
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


