/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eahmeti <eahmeti@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:32:44 by eahmeti           #+#    #+#             */
/*   Updated: 2024/10/12 20:24:03 by eahmeti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_char(int c);
int	ft_str(char *str);
int	ft_pointer(void *ptr);
int	ft_decimal(int c);
int	ft_unsigned_decimal(unsigned int c);
int	ft_hexa(unsigned int nbr, char *base);
int	ft_percent(void);
int	ft_printf(const char *s, ...);

#endif
