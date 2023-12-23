/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:31:06 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/22 14:32:15 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_display(t_vars *vars)
{
	vars->mlx = mlx_init(vars->height * 64, vars->width * 64, "Game", true);
	vars->texture_open_gate = mlx_load_png("./pictures/open_gate.png");
	vars->texture_gate = mlx_load_png("./pictures/gate.png");
	vars->texture_apple = mlx_load_png("./pictures/apple.png");
	vars->texture_ground = mlx_load_png("./pictures/ground.png");
	vars->texture_knight = mlx_load_png("./pictures/knight.png");
	vars->texture_wall = mlx_load_png("./pictures/wall_sprite.png");
	vars->img_open_gate = mlx_texture_to_image(vars->mlx,
			vars->texture_open_gate);
	vars->img_gate = mlx_texture_to_image(vars->mlx, vars->texture_gate);
	vars->img_apple = mlx_texture_to_image(vars->mlx, vars->texture_apple);
	vars->img_ground = mlx_texture_to_image(vars->mlx, vars->texture_ground);
	vars->img_knight = mlx_texture_to_image(vars->mlx, vars->texture_knight);
	vars->img_wall = mlx_texture_to_image(vars->mlx, vars->texture_wall);
}

int	parse_map(char *file, t_vars *vars)
{
	char	*tab;
	char	*tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	tab = get_next_line(fd);
	if (tab == NULL)
	{
		free(tab);
		return (-1);
	}
	tmp = get_next_line(fd);
	while (tmp)
	{
		tab = ft_strjoin(tab, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	vars->map = ft_split(tab, '\n');
	free(tab);
	close(fd);
	return (0);
}

void    display_map_elements(t_vars *vars)
{
    int i;
    int j;
    int x;
    int y;

    j = 0;
    y = 0;
    while (vars->map[j] != NULL)
    {   
        i = 0;
        x = 0;
        while (vars->map[j][i])
        {   
            display_element_at_position(vars, vars->map[j][i], x , y);
            x += 64;
            i++;
        }
        y += 64;
        j++;
    }
}
void	display_element_at_position(t_vars *vars, char element, int x, int y)
{
	mlx_image_to_window(vars->mlx, vars->img_ground, x, y);
	if (element == 'C')
		mlx_image_to_window(vars->mlx, vars->img_apple, x, y);
	else if (element == 'P')
	{
		mlx_image_to_window(vars->mlx, vars->img_knight, x, y);
		vars->x = x;
		vars->y = y;
	}
	else if (element == '1')
		mlx_image_to_window(vars->mlx, vars->img_wall, x, y);
	else if (element == 'E')
	{
		mlx_image_to_window(vars->mlx, vars->img_gate, x, y);
		vars->x_gate = x;
		vars->y_gate = y;
	}
}
