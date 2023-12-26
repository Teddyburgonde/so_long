/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_error_pathfinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:22:53 by tebandam          #+#    #+#             */
/*   Updated: 2023/12/26 15:05:23 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message_exit_error(char **map)
{
	ft_printf("ERROR the game cannot be completed, %s",
		"exit isn't accessible !");
	ft_free(map);
	exit(EXIT_FAILURE);
}

void	message_collectibles(char **map)
{
	ft_printf(
		"ERROR the game cannot be completed, %s",
		"collectibles isn't accessible !");
	ft_free(map);
	exit(EXIT_FAILURE);
}

void	message_character(char **map)
{
	ft_printf("ERROR the game cannot be completed, player locked !");
	ft_free(map);
	exit(EXIT_FAILURE);
}
