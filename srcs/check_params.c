#include "../includes/fractol.h"

enum Fractal ft_check_params(int argc, char **argv)
{
	(void)argv;
	if (argc == 2)
		return MANDLEBROT;
	else
		return NOT_IMP;
}