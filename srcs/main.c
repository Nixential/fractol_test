#include "../includes/fractol.h"

int main(int argc, char **argv)
{
	enum Fractal frac = ft_check_params(argc, argv);
	if (frac == NOT_IMP)
	{
		return 1;
	}

	t_app_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return 1;
	data.mlx_window = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Fract-ol");
	if (!data.mlx_window)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return 1;
	}
	mlx_key_hook(data.mlx_window, &ft_key_hook, &data);
	mlx_loop(data.mlx_ptr);
	ft_free_app(&data);
	return (0);
}