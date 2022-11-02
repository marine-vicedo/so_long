
/* gcc -Wall -Wextra -I minilibx-linux/ get_window.c -L minilibx-linux -lmlx -lXext -lX11 -lz -lm*/

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

# define X_EVENT_KEY_PRESS 2

typedef	struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

t_image		load_image(void *mlx)
{
	t_image	img;
	int		height;
	int		width;

	height = 500;
	width = 500;

	img.img = mlx_xpm_file_to_image(mlx, "./sprites/Image0001.xpm", &width, &height);

	/*Gets the memory address of the given image*/
	/*bits_per_pixel : the number of bits to represent a pixel color*/
	/*size_line : Because the pixels of the image are not stored in a 2D table but all in a row in a single array.
	This tells you how many pixels are in each line of your image, and each pixel is represented by 4 chars. Allowing you to get access to every pixel on the image with the following formula: X_position * 4 + Line_size * Y_position, that will give you the first char of the pixel. */
	/*endian : Can be either 0 or 1 depending on the system and it defines how colors are stored. For us in 42 I believe it’s always stored in the same way: the first character is blue, then green, red, and finally the alpha or transparency of the pixel. Each value goes from 0 to 255. */
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);

	return (img);
}

int	key_press(int key, t_param *param)
{
	if (key == 65307)
		exit(0);
	printf("%d\n", param->x);
	return (0);
}

int	main()
{
	void	*mlx;
	void	*win;
	t_image	img;
	t_param param;

	/* Initializes the MLX library */
	mlx = mlx_init();
	
	/*Creates a new window instance */
	win = mlx_new_window(mlx, 500, 500, "Title");


	/*Creates a new MLX compatible image. not necessary */
	img.img = mlx_new_image(mlx, 200, 200);

	img = load_image(mlx);

	/*Puts an image to the given window instance at location (x,y)*/
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);

	mlx_hook(win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	//mlx_hook(win, X_EVENT_KEY_EXIT, 0, &key_press, &param);

/*mx_loop is an infinite loop that would keep the program running,
 the window open, and would keep detecting the different events (press key, mouse...) and 
calling the functions you’ve hooked to them. */
	mlx_loop(mlx);
}