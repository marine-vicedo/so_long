NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src/
OBJ_DIR = obj/

SRC = check_args.c exit_error_free.c init_values.c moves.c \
pathfinding_utils.c display.c exit_game.c map_valid.c \
moves_utils.c read_map.c utils_bis.c display_utils.c \
handle_key_press.c map_valid_utils.c pathfinding.c \
so_long.c utils.c get_next_line.c \
get_next_line_utils.c \


SRCS = = $(addprefix $(SRC_DIR), $(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))
HEADER = -I ./include
MLX = -L ./minilibx-linux -lmlx_Linux
MLXFLAGS = -lmlx -lXext -lX11

all : $(OBJ_DIR) $(NAME) 

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(NAME): $(OBJS)
	$(MAKE) --no-print-directory -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLXFLAGS) -o $(NAME)

clean :
		rm -f $(OBJS)
		rm -rf $(OBJ_DIR)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re