#ifndef FRACTOL_H
#define FRACTOL_H

#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define ESC_KEY 65307
#define MAX_ITER 25

typedef struct s_app_data
{
	void *mlx_ptr;
	void *mlx_window;
} t_app_data;

void ft_free_app(t_app_data *data);
int ft_key_hook(int keycode, t_app_data *data);

#endif