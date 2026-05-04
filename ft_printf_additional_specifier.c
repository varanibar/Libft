/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_additional_specifier.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: varaniba <varaniba@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/04/29 14:42:01 by varaniba      #+#    #+#                 */
/*   Updated: 2026/05/04 18:45:54 by varaniba      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	offset(const char *format_str, int *i)
{
	if (*format_str == '.')
	{
		while (*format_str != 'f')
		{
			*i = *i + 1;
			format_str++;
		}
	}
}

int	get_precision(double *nbr, const char *specif, long *multiplier)
{
	int	precision;
	int	i;

	i = 0;
	precision = 0;
	if (*specif == 'f')
		precision = 6;
	else if (*specif == '.' && *(specif + 1) != 'f')
	{
		specif++;
		while (*specif >= '0' && *specif <= '9')
		{
			precision = precision * 10 + *specif - '0';
			specif++;
		}
		if (precision > 15)
			precision = 15;
	}
	while (precision - i++ > 0)
		*multiplier = *multiplier * 10;
	*nbr = *nbr + (0.5 / *multiplier);
	return (precision);
}
#include <stdio.h>

int	ft_print_float(double nbr, const char *specif)
{
	long	multiplier;
	long	decimal_part;
	long	integer_part;
	int		precision;
	int		count;

	multiplier = 1;
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	integer_part = (long)nbr;
	// decimal_part = nbr - integer_part;
	printf("\nnbr before= %f\n", nbr);
	precision = get_precision(&nbr, specif, &multiplier);
	count += ft_putnbr_b(nbr, "0123456789");
	printf("\nnbr after = %f\n", nbr);
	if (precision > 0)
	{
		count += write(1, ".", 1);
		printf("\ninteger_part = %ld\n", integer_part);
		printf("multiplier = %ld\n", multiplier);
		printf("integer_part * multiplier = %ld\n", integer_part * multiplier);
		decimal_part = ((nbr - integer_part) + 0.5) * multiplier;
		printf("\ndecimal_part = %ld\n\n", decimal_part);
		count += ft_putnbr_b(decimal_part, "0123456789");
		if (decimal_part == 0)
			while (--precision > 0)
				count += write(1, "0", 1);
	}
	return (count);
}
