/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:25 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 14:36:25 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *s, int *failed)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!s)
		return (ft_putstr("(null)", failed));
	while (s[i])
		len += ft_putchar(s[i++], failed);
	return (len);
}
