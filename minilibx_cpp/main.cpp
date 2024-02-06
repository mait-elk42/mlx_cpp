#include <iostream>
#include <header.hpp>

int f(t_mlx *mlx)
{
	(void)mlx;
	return (0);
}

int main()
{
	t_mlx	mlx;
	mlx.mlx_ptr = _nsx_mlx_init();
	mlx.win_ptr = _nsx_mlx_new_window(mlx.mlx_ptr, 1000, 1000, "cpp window");
	
	t_image image;
	_nsx_mlx_png_file_to_image(mlx.mlx_ptr, "../img.jpeg", &image);
	_nsx_mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image, (t_vector2){100, 100});
	_nsx_mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image, (t_vector2){200, 200});
	_nsx_mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image, (t_vector2){300, 300});
	_nsx_mlx_loop_hook(mlx.mlx_ptr, f, &mlx);
	_nsx_mlx_loop(mlx.mlx_ptr);
	return 0;
}