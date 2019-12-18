/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:29:21 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 18:29:23 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			print_str(va_list ap, t_flags *flags)
{
	char	*str;
	int		size;

	str = va_arg(ap, char*);
	if (!str || str == NULL)
	{
		size = 6;
		display("(null)", size, flags);
		if (flags->width - size > 0)
			return (flags->width);
		else
			return (size);
	}
	else
		size = ft_strlen(str);
	size = (flags->precision == -1) ? 0 : size;
	if (flags->precision > 0 && flags->precision < size && size > 0)
		size = size - (size - flags->precision);
	pad_str(flags, size, str);
	if (!flags->width || !flags->minus)
		display((str) ? str : "(null)", size, flags);
	if (flags->width - size > 0)
		return (size + flags->width - size);
	else
		return (size);
}

int			print_symb(va_list args, t_flags *flags)
{
	int		c;

	c = va_arg(args, int);
	pad_str(flags, 1, &c);
	if (!flags->width || !flags->minus)
		display(&c, 1, flags);
	return ((flags->width) ? flags->width : 1);
}

int			print_procent(va_list args, t_flags *flags)
{
	(void)args;
	pad_str(flags, 1, "%");
	if (!flags->width || !flags->minus)
		display("%", 1, flags);
	return ((flags->width) ? flags->width : 1);
}

int			print_p(va_list args, t_flags *flags)
{
	flags->length_type = TYPE_L;
	flags->hash_key = 1;
	return (print_x(args, flags));
}
