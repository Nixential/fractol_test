#include "../includes/fractol.h"

void ft_free_app(t_app_data *data)
{
	if (data->mlx_window)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
}

int ft_key_hook(int keycode, t_app_data *data)
{
	(void)data;
	if (keycode == ESC_KEY)
		ft_free_app(data);

	return (keycode);
}