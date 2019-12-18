/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 17:42:33 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 17:42:43 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		define_flags(char **str, t_flags *flags)
{
	if (*(*str) == '-')
		flags->minus = 1;
	else if (*(*str) == '+')
		flags->plus = 1;
	else if (*(*str) == ' ')
		flags->space = 1;
	else if (*(*str) == '0')
		flags->zero = 1;
	else if (*(*str) == '#')
		flags->hash_key = 1;
	else
		return (0);
	(*str)++;
	return (1);
}

int		define_width(char **str, t_flags *flags, va_list args)
{
	int width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
		{
			width = va_arg(args, int);
			if (width < 0)
				flags->minus = 1;
			flags->width = (width < 0 ? width * -1 : width);
			width = 1;
		}
		else
			flags->width = width;
		while (width > 0 && (*str += 1))
			width /= 10;
		return (1);
	}
	return (0);
}

int		define_precision(char **str, t_flags *flags, va_list args)
{
	int precision;

	precision = 0;
	if (**str == '.')
	{
		*str += 1;
		if (!ft_isdigit(**str) && **str != '*')
		{
			flags->precision = -1;
			return (1);
		}
		precision = (**str == '*') ? va_arg(args, int) : ft_atoi(*str);
		flags->precision = (precision == 0 ? -1 : precision);
		if (flags->precision < 0 && flags->precision != -1)
			flags->precision = 0;
		if (**str == '*')
			precision = 1;
		else if (precision == 0)
			*str += 1;
		while (precision > 0 && (*str = *str + 1))
			precision /= 10;
		return (1);
	}
	return (0);
}

int		define_length(char **str, t_flags *flags)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		edit_type(str, flags, TYPE_HH, 2);
	else if (**str == 'h')
		edit_type(str, flags, TYPE_H, 1);
	else if (**str == 'l' && *(*str + 1) == 'l')
		edit_type(str, flags, TYPE_LL, 2);
	else if (**str == 'l')
		edit_type(str, flags, TYPE_L, 1);
	else if (**str == 'j')
		edit_type(str, flags, TYPE_J, 1);
	else if (**str == 'z')
		edit_type(str, flags, TYPE_Z, 1);
	else if (**str == 'L')
		edit_type(str, flags, TYPE_L_UP, 1);
	else
		return (0);
	return (1);
}
