
/* gcc -Wall -Wextra -I minilibx-linux/ get_window.c -L minilibx-linux -lmlx -lXext -lX11 -lz -lm*/

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"

typedef	struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_image;


t_image		load_image(void *mlx_ptr)
{
	t_image	img;
	int		height;
	int		width;

	height = 500;
	width = 500;

	img.img = mlx_xpm_file_to_image(mlx_ptr, "./sprites/Image0001.xpm", &width, &height);

	/*Gets the memory address of the given image*/
	/*bits_per_pixel : the number of bits to represent a pixel color*/
	/*size_line : Because the pixels of the image are not stored in a 2D table but all in a row in a single array.
	This tells you how many pixels are in each line of your image, and each pixel is represented by 4 chars. Allowing you to get access to every pixel on the image with the following formula: X_position * 4 + Line_size * Y_position, that will give you the first char of the pixel. */
	/*endian : Can be either 0 or 1 depending on the system and it defines how colors are stored. For us in 42 I believe it’s always stored in the same way: the first character is blue, then green, red, and finally the alpha or transparency of the pixel. Each value goes from 0 to 255. */
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);

	return (img);
}


int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;

	/* Initializes the MLX library */
	mlx_ptr = mlx_init();
	
	/*Creates a new window instance */
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Title");


	/*Creates a new MLX compatible image.*/
	//img.img = mlx_new_image(mlx_ptr, 1920, 1080);

	img = load_image(mlx_ptr);

	/*Puts an image to the given window instance at location (x,y)*/
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);

/*mx_loop is an infinite loop that would keep the program running,
 the window open, and would keep detecting the different events (press key, mouse...) and 
calling the functions you’ve hooked to them. */
	mlx_loop(mlx_ptr);
}