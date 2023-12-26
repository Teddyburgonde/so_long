/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:55:59 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 11:41:47 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H 
# define SO_LONG_H

# include "MLX42/MLX42_Int.h"
# include "MLX42/MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# define SPRITE_PIXEL 64

typedef struct s_textures{
	mlx_texture_t	*texture_knight;
	mlx_texture_t	*texture_gate;
	mlx_texture_t	*texture_wall;
	mlx_texture_t	*texture_ground;
	mlx_texture_t	*texture_apple;
	mlx_texture_t	*texture_open_gate;
}	t_textures;

typedef struct s_images{
	mlx_image_t		*img_gate;
	mlx_image_t		*img_knight;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_ground;
	mlx_image_t		*img_apple;
	mlx_image_t		*img_open_gate;	
}	t_images;

typedef struct s_vars{
	mlx_t			*mlx;
	t_textures		textures;
	t_images		images;
	char			**map;
	int				x;
	int				y;
	size_t			height;
	size_t			width;
	int				apple_count;
	int				move_count;
	int				x_gate;
	int				y_gate;
	int				have_apples;
	int				have_many_doors;
	int				have_character;
}	t_vars;

int		ft_printf(char *str, ...);
void	display_map_elements(t_vars *vars);
void	display_element_at_position(t_vars *vars, char element, int x, int y);
int		parse_map(char *file, t_vars *vars);
int		check_wall_up(t_vars *vars);
int		check_wall_left(t_vars *vars);
int		check_wall_right(t_vars *vars);
int		check_wall_down(t_vars *vars);
int		error_collectibles(t_vars *vars, int have_apples);
int		error_too_many_doors(t_vars *vars, int have_many_doors);
int		error_no_character(t_vars *vars, int have_character);
int		error_too_many_characters(t_vars *vars, int have_character);
void	init_display(t_vars *vars);
void	collectible_capture(t_vars *vars);
void	move_up_down(t_vars *vars, int movement);
void	move_left_right(t_vars *vars, int movement);
void	key_press(mlx_key_data_t keydata, void *param);
void	find_player(t_vars *vars);
char	**copy_map(t_vars *vars);
char	**pathfinder(int x, int y, char **map);
void	free_struct(t_vars *vars);
void	free_texture(t_vars *vars);
void	ft_free(char **tab);
int		struct_init(t_vars *vars, char *file);
int		check_errors(t_vars *vars);
void	calcul_height(t_vars *vars);
int		is_valid(t_vars *vars);

#endif