/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:05:37 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/25 08:36:10 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_collectibles(t_vars *vars, int have_apples)
{
	int	j;
	int	i;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'C')
			{
				vars->apple_count++;
				have_apples = 1;
			}
			i++;
		}
		j++;
	}
	if (!have_apples)
	{
		ft_printf("ERROR : There are no collectibles \n");
		ft_free(vars->map);
		free(vars);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	error_too_many_doors(t_vars *vars, int have_many_doors)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'E')
				have_many_doors++;
			i++;
		}
		j++;
	}
	if (have_many_doors != 1)
	{
		ft_printf("ERROR : too many doors \n");
		ft_free(vars->map);
		free(vars);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	error_no_character(t_vars *vars, int have_character)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'P')
				have_character = 1;
			i++;
		}
		j++;
	}
	if (have_character != 1)
	{
		ft_printf("ERROR : there is no character \n");
		ft_free(vars->map);
		free(vars);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	error_too_many_characters(t_vars *vars, int have_character)
{
	int	i;
	int	j;

	j = 0;
	while (vars->map[j])
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'P')
				have_character++;
			i++;
		}
		j++;
	}
	if (have_character > 1)
	{
		ft_printf("ERROR : there is too mamy characters \n");
		ft_free(vars->map);
		free(vars);
		exit(EXIT_FAILURE);
	}
	return (0);
}
