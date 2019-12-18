/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:34:37 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 18:34:40 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			pad_nb(t_flags *flags, uintmax_t nb, int *size, char *base)
{
	int			width;
	int			precision;

	if (flags->precision <= 0 && flags->width <= 0)
	{
		if (flags->type == 'p' && *size > 0)
			*size += 2;
		return ;
	}
	width = 0;
	precision = flags->precision - *size;
	*size = (flags->precision > *size) ? flags->precision : *size;
	while (flags->minus && width++ < precision)
		display("0", 1, flags);
	if (flags->minus && flags->precision != -1)
		putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	width = 0;
	while (width++ < flags->width - (*size + (flags->type == 'p' ? 2 : 0)))
		display((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	width = 0;
	while (!flags->minus && width++ < precision)
		display("0", 1, flags);
	if (*size > 0 && flags->type == 'p')
		*size += 2;
}

int				pad_str(t_flags *flags, int size, void *s)
{
	int			width;

	width = 0;
	if (flags->width)
	{
		if (flags->minus)
			display(s, size, flags);
		while (width++ < flags->width - size)
			display((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	}
	return (size + width - 1);
}

int				pad(t_flags *flags, int size)
{
	int			width;

	width = 0;
	while (width++ < flags->width - size)
		display((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	return (size + width - 1);
}

int				display_no_precent(char **format, t_flags *flags)
{
	int			next;

	if (ft_strchr(*format, '%'))
		next = (int)(ft_strchr(*format, '%') - *format);
	else
		next = (int)ft_strlen(*format);
	display(*format, next, flags);
	*format += next;
	return (next);
}

int				display(void *s, int size, t_flags *flags)
{
	int			i;
	char		*str;

	if (flags->bytes + size > BUFF_SIZE)
	{
		write(1, flags->buffer, (size_t)flags->bytes);
		flags->bytes = 0;
		if (size > BUFF_SIZE)
		{
			write(1, s, (size_t)size);
			return (size);
		}
	}
	i = 0;
	str = s;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (size);
	}
	while (i < size)
		flags->buffer[flags->bytes++] = str[i++];
	return (size);
}
