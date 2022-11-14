NAME = so_long
MLX = ./minilibx-linux

CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11 -lz -lm

SRCS = srcs/check_args.c srcs/exit_error_free.c srcs/init_values.c srcs/moves.c \
srcs/pathfinding_utils.c srcs/display.c srcs/exit_game.c srcs/map_valid.c \
srcs/moves_utils.c srcs/read_map.c srcs/utils_bis.c srcs/display_utils.c \
handle_key_press.c map_valid_utils.c pathfinding.c \
srcs/so_long.c srcs/utils.c srcs/get_next_line.c \
srcs/get_next_line_utils.c \

OBJS = $(:.c=.o)

all : 		$(NAME)

$(NAME) :	 $(OBJS)
				make all -C $(MLX)
				$(CC) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o : 		%.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c .I/includes -o $@ $<

clean :
				rm -f $(OBJS)
				make clean -C $(MLX)

fclean : 	clean
				rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
