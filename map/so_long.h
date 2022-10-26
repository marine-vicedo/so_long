/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/10/26 19:16:30 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../get_next_line_V2/get_next_line.h"

typedef struct s_game
{
	size_t	width;
	int height;	
}	t_game;

void	exit_error(char	**map);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(char *s, char c);
char	**create_map(char **map, char *file, t_game *game);
int		ft_count_lines(char *file);
char	*fill_map(char *src);
void	free_tab(char **tab);
void	print_tab(char **tab);
int		check_config(char **map, t_game *game);
int		count_tablines(char **tab);
int		check_parameters(int argc, char **argv);

#endif