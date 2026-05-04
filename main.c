#include "libft.h"

int	main(void)
{
	char	c = 'a';
	int		d = -42;
	char	s[] = "hello world";
	char	*p = s;
	int		u = 42;
	int		x = 42;
	int		X = 42;
	float	f = 42.42;

	ft_printf("\n>>>> TESTING FT_PRINTF <<<<\n\n");
	ft_printf("%%c > %c\n", c);
	ft_printf("%%d > %d\n", d);
	ft_printf("%%s > %s\n", s);
	ft_printf("%%p > %p\n", p);
	ft_printf("%%u > %u\n", u);
	ft_printf("%%x > %x\n", x);
	ft_printf("%%X > %X\n", X);
	ft_printf("%%f    > %f\n", f);
	ft_printf("%%.f   > %.f\n", f);
	ft_printf("%%.0f  > %.0f\n", f);
	ft_printf("%%.1f  > %.1f\n", f);
	ft_printf("%%.2f  > %.2f\n", f);
	ft_printf("%%.3f  > %.3f\n", f);
	ft_printf("%%.4f  > %.4f\n", f);
	ft_printf("%%.5f  > %.5f\n", f);
	ft_printf("%%.6f  > %.6f\n", f);
	ft_printf("%%.7f  > %.7f\n", f);
	ft_printf("%%.8f  > %.8f\n", f);
	ft_printf("%%.9f  > %.9f\n", f);
	ft_printf("%%.10f > %.10f\n", f);
	ft_printf("%%.11f > %.10f\n", f);
	ft_printf("%%.12f > %.10f\n", f);
	ft_printf("%%.13f > %.10f\n", f);
	ft_printf("%%.14f > %.10f\n", f);
	ft_printf("%%.15f > %.10f\n", f);
	ft_printf("%%%% > printing a lonely %% sign\n\n");
	return (0);
}
