#include <iostream>
#include <header.hpp>

int main()
{
	void	*mlx_ptr = _nsx_mlx_init();
	void	*win_ptr = _nsx_mlx_new_window(mlx_ptr, 1000, 1000, "lib");

	std::cout << "test" << "\n";
	_nsx_mlx_loop(mlx_ptr);
}