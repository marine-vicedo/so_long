/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/27 20:07:06 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../get_next_line_V2/get_next_line.h"

typedef struct s_game
{
	int	width;
	int height;
	int	x;
	int	y;
}	t_game;

void	exit_error(char	**map);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(char *s, char c);
char	**create_map(char **map, char *file, t_game game);
int		ft_count_lines(char *file);
char	*fill_map(char *src);
void	free_tab(char **tab);
void	print_tab(char **tab);
int		check_config(char **map, t_game game);
int		count_tablines(char **tab);
int		check_parameters(int argc, char **argv);
int		ft_strlen(const char *s);
int		check_format(char **map, t_game game);
int		invalid_character(char **map, t_game game);
int		check_player(char **map, t_game game);
int		check_collect_exit(char **map, t_game game);
int		closed_by_walls(char **map, t_game game);
int		check_matrix(char **map, t_game game);


#endif