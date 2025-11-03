/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzoubir <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:51:44 by mzoubir           #+#    #+#             */
/*   Updated: 2025/11/03 15:51:45 by mzoubir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    // char *a  = "Hello";

    // int b = -84656565;
    int a = ft_printf("%s", "Hello world");

    if (1 == 1)
        fprintf(stderr, "\nsize: %d\n", a);
	return (0);
}
