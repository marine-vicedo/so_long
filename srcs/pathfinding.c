/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:36 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/11 18:48:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **init_path(t_game *game, int y)
{
	game->path = (char **)malloc(sizeof(char *) * (game->height + 1));
	if (!game->path)
		exit(0);
	while (y < game->height)
	{
		game->path[y] = ft_strdup(game->map[y]);
		y++;
	}
	game->path[y] = NULL;
	return (game->path);
}

void	check_valid_path(t_game *game, int x, int y)
{
	while(check_pos_player(game, x, y) == 1)
		move_pos_player(game, x, y);
	if (valid_path(game, x, y) != 1 && all_items_are_collected(game, x, y) != 1)
		path_error(game);
}

void	path_finding(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->path = init_path(game, y);
	check_valid_path(game, x, y);
	//print_tab(game->path);
}

//trouver la position x , y de notre player
//marquer la position du player a 1 dans notre matrice path et verifier si la position actuelle n'est pas Exit
//appeler recursivement la fonction avec (i + 1, j) et (i, j + 1)
// 



//parcourir la map et trouver 'P'. verifier qu'il n'est pas entoure de murs (boucle)
//si ok on va deplacer P dans la map -> boucle >> des que P rencontre un 0 ou un C (chemin valide), il peut se deplacer (la case est marquee d'un P)
// quand boucle finit, check si P est au niveau de la sortie et verifier qu'il ne reste plus de C
// valider ou invalider la map en fonction du resultat ci dessus
