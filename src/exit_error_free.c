/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:29 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/15 15:23:29 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creer une fonction generale pour les differentes erreurs
// leaks pour fd = -1, il manque un free

#include "so_long.h"

int	exit_error(t_game *game, int error)
{
	if (error == 0)
		ft_putstr_fd("Error : invalid fd", 2);
	if (error == 1)
		ft_putstr_fd("Error : map is empty", 2);
	if (error == 2)
		free_tab(game->map);
	if (error == 3)
	{
		ft_putstr_fd("Error : no valid path in the map", 2);
		free_tab(game->path);
		free_tab(game->map);
	}
	free(game);
	exit (0);
}

int	exit_error_display(t_game *game)
{
	ft_putstr_fd("Error : can't open the sprites, check your files", 2);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->map);
	free_tab(game->path);
	free(game);
	exit (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
