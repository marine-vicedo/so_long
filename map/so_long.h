/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/02 18:21:19 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../get_next_line_V2/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

typedef struct s_game
{
	int		width;
	int 	height;
	char	**map;
	char	**path;
	void	*mlx;
	void	*win;
	t_image	wall;
}	t_game;

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}	t_image;

void	exit_error(char	**map);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(char *s, char c);
char	**read_map(char **map, char *file, t_game game);
int		ft_count_lines(char *file);
char	*fill_map(char *src);
void	free_tab(char **tab);
void	print_tab(char **tab);
int		check_config(char **map, t_game game);
int		count_tablines(char **tab);
int		check_parameters(int argc, char **argv);
int		ft_strlen(const char *s);
int		check_format(char **map, t_game game);
int		invalid_character(char **map, t_game game, int x, int y);
int		check_player(char **map, t_game game, int x, int y);
int		check_collect_exit(char **map, t_game game, int x, int y);
int		closed_by_walls(char **map, t_game game, int y);
int		check_matrix(char **map, t_game game, int x, int y);
t_game	copy_map_to_game(char **map, t_game game);
t_game 	init_path(t_game game, int x, int y);
void	check_valid_path(t_game game, int x, int y);
int		check_pos_player(t_game game, int x, int y);
t_game	move_pos_player(t_game game, int x, int y);
int		all_items_are_collected(t_game game, int x, int y);
int		valid_path(t_game game, int x, int y);
t_game	map_values(char *file, t_game game);
t_game	path_finding(t_game game);


#endif