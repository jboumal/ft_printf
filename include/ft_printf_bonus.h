/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboumal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:24:04 by jboumal           #+#    #+#             */
/*   Updated: 2022/03/28 14:08:20 by jboumal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	char	fill_char;
	int		number_sign;
	int		space;
	int		plus;
	int		width;
	int		dot;
	int		printed;
	int		size;
	int		tmp;
	int		negative;
	char	format;
}					t_flags;

int		ft_printf(const char *format, ...);
void	set_flags(t_flags *flags, const char *format);
void	write_c(char c, t_flags *flags);
void	write_s(char *s, t_flags *flags);
void	write_p(void *p, t_flags *flags);
void	write_i(int n, t_flags *flags);
void	write_u(unsigned int n, t_flags *flags);
void	write_x(unsigned int n, t_flags *flags);
void	write_upper_x(unsigned int n, t_flags *flags);
void	write_percent(t_flags *flags);
void	field_width(t_flags *flags);
void	precision(t_flags *flags);
void	minus_flag(t_flags *flags);

#endif
