/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:57:15 by alalauty          #+#    #+#             */
/*   Updated: 2024/10/23 13:58:47 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>  // For open()
# include <unistd.h> // For close()
# include "libft/libft.h"
// Game structure definition
typedef struct s_slong {
	  char **map_data;  
    int map_width;       
    int map_height;  
	void	*mlx;
	void	*win;
	void	*img;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	int		x;
	int		y;
} t_slong;

// Function prototypes
// t_map *read_map(const char *filename);
void *read_map(const char *filename ,t_slong * map) ;
void	ft_img(t_slong *slong, char tile);
int ft_strlen_2d(char **map);
int	keys_hook(int keycode, t_slong *param);
int	exit_hook(t_slong *param);
void    read_for_fd(char *map_file, int *fd, char **tmp);
void    save_for_map(char *map_file, t_slong *game);

#endif

