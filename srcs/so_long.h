/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/12 18:50:44 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../get_next_line_V2/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"

# define X_EVENT_KEY_EXIT	17
# define KEY_ESC			65307
# define KEY_W				119
# define KEY_S				115
# define KEY_A				97
# define KEY_D				100
# define KEY_UP				65362
# define KEY_DOWN			65364
# define KEY_LEFT			65361
# define KEY_RIGHT			65363

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_tile
{
	void	*wall;
	void	*empty;
	void	*player;
	void	*item;
	void	*exit;
}	t_tile;

typedef struct s_game
{
	int		width;
	int		height;
	char	**map;
	char	**path;
	void	*mlx;
	void	*win;
	int		item;
	int		moves_cnt;
	t_tile	img;
	t_pos	player;
}	t_game;

void	exit_error(t_game *game, int error);
int		ft_strchr(char *s, char c);
void	read_map(char *file, t_game *game);
int		ft_count_lines(char *file);
char	*fill_map(char *src);
void	free_tab(char **tab);
void	print_tab(char **tab);
int		map_is_valid(t_game *game);
int		count_tablines(char **tab);
int		check_args(int argc, char **argv);
int		ft_strlen(const char *s);
int		check_format(t_game *game);
int		invalid_character(t_game *game, int x, int y);
int		check_player(t_game *game, int x, int y);
int		check_collect_exit(t_game *game, int x, int y);
int		closed_by_walls(t_game *game, int y);
int		check_matrix(t_game *game, int x, int y);
char	**init_path(t_game *game, int y);
void	check_valid_path(t_game *game, int x, int y);
int		check_pos_player(t_game *game, int x, int y);
void	move_pos_player(t_game *game, int x, int y);
int		all_items_are_collected(t_game *game, int x, int y);
int		valid_path(t_game *game, int x, int y);
void	init_values(char *file, t_game *game);
void	pathfinding(t_game *game);
t_tile	images_path(t_game *game);
void	load_images(t_game *game);
void	display_game(t_game *game);
void	find_pos_player(t_game *game);
int		handle_key_press(int key_code, t_game *game);
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);
void	ft_putstr_fd(char *s, int fd);
void	print_tab2(t_game *game);
char	*ft_strdup(const char *s);
int		exit_game(t_game *game);
void	ft_putnbr_fd(int n, int fd);
void	display_moves_cnt(int moves_count);
void	update_image_win(t_game *game, int x, int y);

#endif