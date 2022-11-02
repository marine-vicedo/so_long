#include <unistd.h>
#include <stdlib.h>

int	check_pos_player(char **game, int x, int y)
{
	int width = 4;
	int height = 6;
	while (y < height)
	{
		while (x < width)
		{
			if (game[y][x] == 'P')
			{
				if (game[y + 1][x] == '0' || game[y + 1][x] == 'C')
					return (1);
				if (game[y - 1][x] == '0' || game[y - 1][x] == 'C')
					return (1);
				if (game[y][x + 1] == '0' || game[y][x + 1] == 'C')
					return (1);
				if (game[y][x - 1] == '0' || game[y][x - 1] == 'C')
					return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

char	**move_pos_player(char **game, int x, int y)
{
	int width = 4;
	int height = 6;
	while (y < height)
	{
		while (x < width)
		{
			if (game[y][x] == 'P')
			{
				if (game[y + 1][x] == '0' || game[y + 1][x] == 'C')
					game[y + 1][x] = 'P';
				if (game[y - 1][x] == '0' || game[y - 1][x] == 'C')
					game[y - 1][x] = 'P';
				if (game[y][x + 1] == '0' || game[y][x + 1] == 'C')
					game[y][x + 1] = 'P';
				if (game[y][x - 1] == '0' || game[y][x - 1] == 'C')
					game[y][x - 1] = 'P';
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (game);
}

static void	ft_print(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		write(1, &tab[i], 1);
		i++;
	}
}

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_print(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	char	**game;
	int x = 0;
	int y = 0;
	game = (char **)malloc(sizeof(char *) * (6));
	if (!game)
		exit(0);
	game[0] = "1111";
	game[1] = "10C1";
	game[2] = "1001";
	game[3] = "1PE1";
	game[4] = "1111";
	game[5] = "NULL";
	print_tab(game);
	//while (check_pos_player(game, x, y) == 1)
	game = move_pos_player(game, x, y);
	print_tab(game);

}