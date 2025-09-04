/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kingstephane <kingstephane@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:52:16 by stkabang          #+#    #+#             */
/*   Updated: 2025/06/23 17:20:25 by kingstephan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		print_hex_maj(va_list args);
int		print_hex(va_list args);
char	*ft_itoa(int n);
int		print_void(va_list args);
int		print_int(va_list args);
int		print_char(va_list args);
int		print_string(va_list args);
int		print_unsigned_int(va_list args);
int		print_percent(void);
char	*ft_uitoa(unsigned int n);
char	*reverse_str(char *str);
int		ft_printf(const char *string, ...);

#endif