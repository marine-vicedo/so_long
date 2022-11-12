/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:29 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 18:46:42 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// creer une fonction generale pour les differentes erreurs
// leaks pour fd = -1, il manque un free

#include "so_long.h"

void	exit_error(t_game *game, int error)
{
	if (error == 0)
		ft_putstr_fd("Error : invalid fd", 2);
	if (error == 1)
		free_tab(game->map);
	if (error == 2)
	{
		ft_putstr_fd("Error : invalid path", 2);
		free_tab(game->path);
		free_tab(game->map);
	}
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
