/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:36:33 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 15:52:35 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putnbr_u(unsigned int n, int *failed);
int		ft_putnbr(int n, int *failed);
int		ft_putstr(char *s, int *failed);
int		ft_putchar(char c, int *failed);
int		ft_printf(const char *str, ...);
int		ft_puthexa(void *s, int *failed);
int		ft_puthexa_nb(unsigned int nb, char c, int *failed);
size_t	ft_strlen(const char *s);

#endif
