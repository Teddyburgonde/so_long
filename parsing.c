/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:05:37 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/24 14:45:49 by tebandam         ###   ########.fr       */
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
		perror("ERROR : There are no collectibles \n");
		return (1);
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
		perror("ERROR : too many doors \n");
		return (1);
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
		perror("ERROR : there is no character \n");
		return (1);
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
		perror("ERROR : there is too mamy characters \n");
		return (1);
	}
	return (0);
}
