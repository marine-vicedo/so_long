/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:25:49 by mvicedo           #+#    #+#             */
/*   Updated: 2022/11/14 20:39:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
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

//so long


// check args
int		check_args(int argc, char **argv);
int		check_filename_ext(char *file);

// init values
void	init_values(char *file, t_game *game);

// read map
void	read_map(char *file, t_game *game);
int		ft_count_lines(char *file);
char	*fill_map(char *src);

// map valid
int		map_is_valid(t_game *game);
int		check_format(t_game *game);
int		check_matrix(t_game *game, int x, int y);

// map valid utils
int		invalid_character(t_game *game, int x, int y);
int		check_player(t_game *game, int x, int y);
int		check_collect_exit(t_game *game, int x, int y);
int		closed_by_walls(t_game *game, int y);

//pathfinding
void	pathfinding(t_game *game);
char	**init_path(t_game *game, int y);
void	check_valid_path(t_game *game, int x, int y);

// pathfinding utils
int		check_pos_player(t_game *game, int x, int y);
void	move_pos_player(t_game *game, int x, int y);
int		all_items_are_collected(t_game *game, int x, int y);
int		valid_path(t_game *game, int x, int y);

// display
void	display_game(t_game *game);

// display utils
t_tile	images_path(t_game *game);
int		error_images(t_game *game);
void	load_images(t_game *game);
void	update_image_win(t_game *game, int x, int y);

// key press
int		handle_key_press(int key_code, t_game *game);

//moves
void	move_up(t_game *game, int x, int y);
void	move_down(t_game *game, int x, int y);
void	move_left(t_game *game, int x, int y);
void	move_right(t_game *game, int x, int y);

// moves utils
void	find_pos_player(t_game *game);
void	display_moves_cnt(int moves_count);

//exit error
int		exit_error(t_game *game, int error);
int		exit_error_display(t_game *game);
void	free_tab(char **tab);

//exit game
int		exit_game(t_game *game);

//utils
int		ft_strlen(const char *s);
int		ft_strchr(char *s, char c);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	print_tab(char **tab);

//gnl
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_search_newline(char *s);
char	*ft_getline(char *stash);
char	*ft_save_stash(char *tmp);

#endif