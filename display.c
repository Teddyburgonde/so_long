/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/25 16:31:06 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_display(t_vars *vars)
{
	vars->mlx = mlx_init(vars->height * SPRITE_PIXEL,
			vars->width * SPRITE_PIXEL, "Game", true);
	if (!vars->mlx)
		exit(EXIT_FAILURE);
	vars->textures.texture_open_gate = mlx_load_png("./pictures/open_gate.png");
	vars->textures.texture_gate = mlx_load_png("./pictures/gate.png");
	vars->textures.texture_apple = mlx_load_png("./pictures/apple.png");
	vars->textures.texture_ground = mlx_load_png("./pictures/ground.png");
	vars->textures.texture_knight = mlx_load_png("./pictures/knight.png");
	vars->textures.texture_wall = mlx_load_png("./pictures/wall_sprite.png");
	if (!vars->textures.texture_open_gate || !vars->textures.texture_gate || !vars->textures.texture_apple
		|| !vars->textures.texture_ground || !vars->textures.texture_knight
		|| !vars->textures.texture_wall)
	{
		free_struct(vars);
		exit(EXIT_FAILURE);
	}
	vars->images.img_open_gate = mlx_texture_to_image(vars->mlx,
			vars->textures.texture_open_gate);
	vars->images.img_gate = mlx_texture_to_image(vars->mlx, vars->textures.texture_gate);
	vars->images.img_apple = mlx_texture_to_image(vars->mlx, vars->textures.texture_apple);
	vars->images.img_ground = mlx_texture_to_image(vars->mlx, vars->textures.texture_ground);
	vars->images.img_knight = mlx_texture_to_image(vars->mlx, vars->textures.texture_knight);
	vars->images.img_wall = mlx_texture_to_image(vars->mlx, vars->textures.texture_wall);
}

void	init_map(t_vars *vars, char *tmp, char *tab, int fd)
{
	while (tmp)
	{
		tab = ft_strjoin(tab, tmp);
		if (tab == NULL)
		{
			free(vars);
			exit(EXIT_FAILURE);
		}
		free(tmp);
		tmp = get_next_line(fd);
	}
	vars->map = ft_split(tab, '\n');
	if (vars->map == NULL)
	{
		free(vars);
		exit(EXIT_FAILURE);
	}	
	free(tab);
	close(fd);
}



int	parse_map(char *file, t_vars *vars)
{
	char	*tab;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (-1);
	tab = get_next_line(fd);
	if (tab == NULL)
	{
		free(tab);
		close(fd);
		return (-1);
	}
	tmp = get_next_line(fd);
	init_map(vars, tmp, tab, fd);
	// while (tmp)
	// {
	// 	tab = ft_strjoin(tab, tmp);
	// 	if (tab == NULL)
	// 	{
	// 		free(vars);
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	free(tmp);
	// 	tmp = get_next_line(fd);
	// }
	// vars->map = ft_split(tab, '\n');
	// if (vars->map == NULL)
	// {
	// 	free(vars);
	// 	exit(EXIT_FAILURE);
	// }	
	// free(tab);
	// close(fd);
	return (0);
}

void	display_map_elements(t_vars *vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (vars->map[j] != NULL)
	{
		i = 0;
		x = 0;
		while (vars->map[j][i])
		{
			display_element_at_position(vars, vars->map[j][i], x, y);
			x += SPRITE_PIXEL;
			i++;
		}
		y += SPRITE_PIXEL;
		j++;
	}
}

void	display_element_at_position(t_vars *vars, char element, int x, int y)
{
	mlx_image_to_window(vars->mlx, vars->images.img_ground, x, y);
	if (element == 'C')
		mlx_image_to_window(vars->mlx, vars->images.img_apple, x, y);
	else if (element == 'P')
	{
		mlx_image_to_window(vars->mlx, vars->images.img_knight, x, y);
		vars->x = x;
		vars->y = y;
	}
	else if (element == '1')
		mlx_image_to_window(vars->mlx, vars->images.img_wall, x, y);
	else if (element == 'E')
	{
		mlx_image_to_window(vars->mlx, vars->images.img_gate, x, y);
		vars->x_gate = x;
		vars->y_gate = y;
	}
}
