/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:14:19 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/18 14:58:21 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

double			part_int_ten(double n, int *size)
{
	double		mod;

	mod = 1;
	while ((int)(n /= 10) != 0)
	{
		mod = mod * 10;
		(*size)++;
	}
	return (mod);
}

void			int_part(double *n, char **str, double mod, int *i)
{
	char		*s;

	s = *str;
	while ((int)*n != 0)
	{
		s[(*i)++] = (char)((*n / mod) + '0');
		*n -= (int)(*n / mod) * mod;
		mod = mod / 10;
	}
}

void			float_part(double n, char **str, int *i, int rigor)
{
	int			j;
	int			tmp;
	char		*s;

	n = (n - (int)n) * 10;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < rigor)
	{
		if ((int)n == 0)
		{
			s[(*i)++] = '0';
			continue;
		}
		tmp = ((int)n != 9) ? (int)(n + 0.01) : (int)n;
		s[(*i)++] = (char)(tmp + '0');
		n = (n - tmp) * 10;
	}
}

int				float_to_str(double n, char **s, int rigor)
{
	int			i;
	long double mod;
	int			size;
	char		*str;
	int			minus;

	i = 0;
	size = 1;
	minus = 0;
	if (n < 0 && size++ && (minus = 1) == 1)
		n = -n;
	mod = part_int_ten(n, &size);
	size += rigor;
	str = ft_memalloc(sizeof(char) * (size + 1));
	if (minus)
		str[i++] = '-';
	int_part(&n, &str, mod, &i);
	float_part(n, &str, &i, rigor);
	str[--i] = '\0';
	*s = str;
	return (size);
}

int				print_f(va_list args, t_flags *flags)
{
	char		*nb;
	int			size;
	long double n;

	if (flags->length_type == 7)
		n = (long double)va_arg(args, long double);
	else
		n = va_arg(args, double);
	if (flags->precision <= 0)
		flags->precision = 7;
	size = float_to_str(n, &nb, flags->precision + 1);
	display(nb, size, flags);
	free(nb);
	return (size);
}
