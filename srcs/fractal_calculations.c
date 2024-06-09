#include "../includes/fractol.h"

int ft_calculate_mantlebrot(double real, double imag)
{
	double z_real = 0.0;
	double z_imag = 0.0;
	double z_real_sq = 0.0;
	double z_imag_sq = 0.0;

	int iterations = 0;
	while (iterations < MAX_ITER)
	{
		z_real_sq = z_real * z_real;
		z_imag_sq = z_imag * z_imag;

		if (z_real_sq + z_imag_sq > 4.0)
			break;
		z_imag = 2.0 * z_real * z_imag + imag;
		z_real = z_real_sq - z_imag_sq + real;

		iterations++;
	}
	return iterations;
}