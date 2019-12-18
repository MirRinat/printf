/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 18:11:44 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/15 18:11:46 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(char *format, ...)
{
	t_flags	flags;
	int		bytes;
	va_list	args;
	char	*str;

	bytes = 0;
	flags.bytes = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += parser(&str, args, &flags);
		}
		else
			bytes += display_no_precent(&str, &flags);
	}
	va_end(args);
	if (flags.bytes > 0)
		write(1, flags.buffer, (size_t)flags.bytes);
	return (bytes);
}
