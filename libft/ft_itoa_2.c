/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 18:57:54 by bantario          #+#    #+#             */
/*   Updated: 2019/11/28 19:22:11 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa_2(unsigned long long n)
{
	char				*chs;
	int					size;
	unsigned long long	y;

	size = 2;
	y = n;
	while (y /= 10)
		size++;
	if ((chs = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	chs[--size] = '\0';
	while (size--)
	{
		chs[size] = n % 10 + '0';
		n = n / 10;
	}
	return (chs);
}
