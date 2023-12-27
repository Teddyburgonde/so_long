/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 08:20:28 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/27 08:19:01 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calcul_height(t_vars *vars)
{
	int		i;
	size_t	save;

	i = 0;
	vars->height = 0;
	vars->width = 0;
	save = ft_strlen(vars->map[i]);
	while (vars->map[i])
	{
		if (save != ft_strlen(vars->map[i]))
		{
			ft_putstr_fd("ERROR\nThe map is not rectangular!", 2);
			if (vars->map != NULL)
				ft_free(vars->map);
			free(vars);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (save > 0)
		vars->height = save;
	i = 0;
	while (vars->map[vars->width])
		vars->width++;
}

int	struct_init(t_vars *vars, char *file)
{
	vars->map = NULL;
	if (parse_map(file, vars) == -1)
		return (1);
	if (check_wall_up(vars) == 1 || check_wall_left(vars) == 1
		|| check_wall_right(vars) == 1 || check_wall_down(vars) == 1)
		return (1);
	if (check_errors(vars) == 1)
		return (1);
	calcul_height(vars);
	if (!is_valid(vars))
		return (1);
	init_display(vars);
	return (0);
}
