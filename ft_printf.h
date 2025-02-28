/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlaoli <carlaoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:45:33 by carlaoli          #+#    #+#             */
/*   Updated: 2024/11/29 18:01:41 by carlaoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_get_format(char c, va_list args);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printptr(void *ptr);
int	ft_printnbr(int n);
int	ft_print_unsigned_nbr(unsigned int n);
int	ft_print_hex_lower(unsigned long n);
int	ft_print_hex_upper(unsigned long n);

#endif