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

static void	redirect_to(const char *str, va_list args, int *len, int *failed)
{
	if (*str == 'c')
		*len += ft_putchar(va_arg(args, int), failed);
	else if (*str == 's')
		*len += ft_putstr(va_arg(args, char *), failed);
	else if (*str == 'd' || *str == 'i')
		*len += ft_putnbr(va_arg(args, int), failed);
	else if (*str == 'u')
		*len += ft_putnbr_u(va_arg(args, int), failed);
	else if (*str == 'p')
		*len += ft_puthexa(va_arg(args, void *), failed);
	else if (*str == 'x' || *str == 'X')
		*len += ft_puthexa_nb(va_arg(args, unsigned int), *str, failed);
	else
		*len += ft_putchar('%', failed);
}

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
		redirect_to(str, args, &len, &failed);
		*is_pers = 0;
	}
	else
		len += ft_putchar(*str, &failed);
	if (failed == -1)
		return (-1);
	return (len);
}

static int	contain_odd_pers(const char *str, int last_index)
{
	int	is_odd;

	is_odd = 1;
	while (str[last_index] && str[last_index] == '%')
	{
		is_odd = -is_odd;
		last_index--;
	}
	return (is_odd);
}

int	ft_printf(const char *str, ...)
{
	int		is_pers;
	int		len;
	int		n;
	int		is_odd;
	va_list	args;

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
	is_odd = contain_odd_pers(str, ft_strlen(str) -1);
	if (is_odd == -1)
		return (-1);
	va_end(args);
	return (len);
}
