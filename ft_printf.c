/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:03:40 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 14:36:56 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_result(const char *str, va_list args, int *is_pers)
{
	int	len;
	int	failed;

	failed = 0;
	len = 0;
	if (*str == '%' && !*is_pers)
		*is_pers = 1;
	else if (*is_pers)
	{
		if (*str == 'c')
			len += ft_putchar(va_arg(args, int), &failed);
		else if (*str == 's')
			len += ft_putstr(va_arg(args, char *), &failed);
		else if (*str == 'd' || *str == 'i')
			len += ft_putnbr(va_arg(args, int), &failed);
		else if (*str == 'u')
			len += ft_putnbr_u(va_arg(args, int), &failed);
		else if (*str == 'p')
			len += ft_puthexa(va_arg(args, void *), &failed);
		else if (*str == 'x' || *str == 'X')
			len += ft_puthexa_nb(va_arg(args, unsigned int), *str, &failed);
		else
			len += ft_putchar(*str, &failed);
		*is_pers = 0;
	}
	else
		len += ft_putchar(*str, &failed);
	if (failed == -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		is_pers;
	int		len;
	int		n;
	int		strlen;
	int		is_odd;

	len = 0;
	va_start(args, str);
	if (!str)
		return (0);
	is_pers = 0;
	while (*str)
	{
		n = print_result(str++, args, &is_pers);
		if (n == -1)
			return (-1);
		len += n;
	}
	// TODO : adding new function handle this ->
	strlen = ft_strlen(str) - 1;
	is_odd = 1;
	while (str[strlen] && str[strlen] == '%')
	{
		is_odd = -is_odd;
		strlen--;
	}
	// the end
	if (is_odd == -1)
		return (-1);
	return (len);
}
