/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:36 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/01 18:06:28 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game copy_map_to_game(char **map, t_game game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game.map = (char **)malloc(sizeof(char *) * (game.height + 1));
	if (!game.map)
		exit(0);
	while (map[y])
	{
		game.map[y] = (char *)malloc(sizeof(char) * game.width + 1);
		if (!game.map)
		{
			free_tab(game.map);
			exit(0);
		}
		while(x < game.width)
		{
			game.map[y][x] = map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}

t_game init_path(t_game game, int x, int y)
{
	game.path = (char **)malloc(sizeof(char *) * (game.height + 1));
	if (!game.path)
		exit(0);
	while (y < game.height)
	{
		game.path[y] = (char *)malloc(sizeof(char) * game.width + 1);
		if (!game.path)
		{
			free_tab(game.path);
			exit(0);
		}
		while(x < game.width)
		{
			game.path[y][x] = game.map[y][x];
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}

void	check_valid_path(t_game game, int x, int y)
{
	while(check_pos_player(game, x, y) == 1)
		game = move_pos_player(game, x, y);
	if (valid_path(game, x, y) == 1 && all_items_are_collected(game, x, y) == 1)
		printf("path is valid !");
	else	
		printf("path is wrong");
}

//trouver la position x , y de notre player
//marquer la position du player a 1 dans notre matrice path et verifier si la position actuelle n'est pas Exit
//appeler recursivement la fonction avec (i + 1, j) et (i, j + 1)
// 



//parcourir la map et trouver 'P'. verifier qu'il n'est pas entoure de murs (boucle)
//si ok on va deplacer P dans la map -> boucle >> des que P rencontre un 0 ou un C (chemin valide), il peut se deplacer (la case est marquee d'un P)
// quand boucle finit, check si P est au niveau de la sortie et verifier qu'il ne reste plus de C
// valider ou invalider la map en fonction du resultat ci dessus
