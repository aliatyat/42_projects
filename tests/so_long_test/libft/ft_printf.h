/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alalauty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:43:37 by alalauty          #+#    #+#             */
/*   Updated: 2024/09/30 18:36:47 by alalauty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *format, ...);
int	ft_putchar(char n);
int	ft_putnbr(long int n);
int	ft_putstr(char *s);
int	ft_puthex(size_t num, int upper);
int	ft_print_pointer(size_t p);
int	ft_putunsigned(unsigned int num);
#endif
