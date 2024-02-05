#include <header.h>

int	On_destroy(t_mlx_info *mlx_info)
{
	mlx_destroy_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	exit(0);
}

int	On_key_down(int keycode, t_mlx_info *mlx_info)
{
	if (keycode == KEY_ESC)
		On_destroy(mlx_info);
	printf("%d\n", keycode);
	return (0);
}

void	draw_point(t_mlx_info *mlx_info, t_vector2 pos, t_color color)
{
	mlx_pixel_put(mlx_info->mlx_ptr, mlx_info->win_ptr, pos.x, pos.y, (color.r << 16 | color.g << 8 | color.b));
}

int	On_Update(t_mlx_info *mlx_info)
{
	// mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	int i = 0;
	int j = 0;
	if (mlx_info->tex.data)
	{
		while (mlx_info->tex.height > i)
		{
			j = 0;
			while (mlx_info->tex.width > j)
			{
				unsigned char A;
				unsigned char R = *mlx_info->tex.data++;
				unsigned char G = *mlx_info->tex.data++;
				unsigned char B = *mlx_info->tex.data++;
				if (mlx_info->tex.colorstype >= 4)
					A = *mlx_info->tex.data++;
				draw_point(mlx_info, (t_vector2){j, i}, (t_color){R, G, B});
				j++;
			}
			i++;
		}
		mlx_info->tex.data = 0;
	}
	return (0);
}

int	main()
{
	t_mlx_info	mlx_info;

	mlx_info.mlx_ptr = mlx_init();
	mlx_info.win_ptr = mlx_new_window(mlx_info.mlx_ptr, 1000 ,700, "Calc!");
	mlx_info.tex.data = stbi_load("img.jpeg", &mlx_info.tex.width, &mlx_info.tex.height, &mlx_info.tex.colorstype, 0);

	mlx_hook(mlx_info.win_ptr, ON_DESTROY, 0, On_destroy, &mlx_info);
	mlx_hook(mlx_info.win_ptr, ON_KEYDOWN, 0, On_key_down, &mlx_info);
	mlx_loop_hook(mlx_info.mlx_ptr, On_Update, &mlx_info);
	mlx_loop(mlx_info.mlx_ptr);
}