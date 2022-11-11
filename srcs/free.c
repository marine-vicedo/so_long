/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:29 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:55:40 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creer une fonction generale pour les differentes erreurs
// leaks pour fd = -1, il manque un free

#include "so_long.h"

void	exit_error(t_game *game)
{
	//write(2, "Error\n", 6);
	free_tab(game->map);
	free(game);
	exit(0);
}

void	file_error(t_game *game)
{
	//write(2, "Error\n", 6);
	free(game);
	exit(0);
}

void	path_error(t_game *game)
{
	ft_putstr_fd("Error : invalid path", 2);
	free_tab(game->path);
	free_tab(game->map);
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