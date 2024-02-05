#include <iostream>
#include <header.hpp>

int main()
{
	void	*mlx_ptr = _nsx_mlx_init();
	void	*win_ptr = _nsx_mlx_new_window(mlx_ptr);
}