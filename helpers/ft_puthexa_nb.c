/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:01:52 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 17:01:53 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthexa_nb(unsigned int nb, char c, int *failed)
{
	char	*hexa;
	int		len;

	len = 0;
	if (c == 'x')
		hexa = "0123456789abcdef";
	else
		hexa = "0123456789ABCDEF";
	if (nb >= 16)
		len += ft_puthexa_nb(nb / 16, c, failed);
	ft_putchar(hexa[nb % 16], failed);
	return (++len);
}
