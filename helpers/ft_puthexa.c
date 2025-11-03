/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:36:57 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 15:36:58 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	get_result(size_t d, int *failed)
{
	char	*hexa;
	int		len;

	len = 0;
	hexa = "0123456789abcdef";
	if (d >= 16)
		len += get_result(d / 16, failed);
	ft_putchar(hexa[d % 16], failed);
	return (++len);
}

int	ft_puthexa(void *s, int *failed)
{
	size_t	addr;

	if (!s)
		return (ft_putstr("(nil)", failed));
	addr = (size_t)s;
	return (ft_putstr("0x", failed) + get_result(addr, failed));
}
