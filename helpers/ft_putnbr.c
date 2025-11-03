/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:12 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 14:36:13 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n, int *failed)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648", failed));
	if (n < 0)
	{
		ft_putchar('-', failed);
		n = -n;
		len++;
	}
	if (n > 9)
		len += ft_putnbr(n / 10, failed);
	ft_putchar(n % 10 + '0', failed);
	return (++len);
}
