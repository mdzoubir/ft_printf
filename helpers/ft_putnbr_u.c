/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:17 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 14:36:18 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_u(unsigned int n, int *failed)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putnbr_u(n / 10, failed);
	ft_putchar(n % 10 + '0', failed);
	return (++len);
}
