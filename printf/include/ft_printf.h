/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjki <seongjk@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 15:13:28 by seongjki          #+#    #+#             */
/*   Updated: 2021/07/05 14:42:37 by seongjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_info
{
	int		flag;
	int		width;
	int		precision;
	int		precision_size;
	int		type;
	int		negative;
	int		size;
}					t_info;

int					check_flag(char **str);
int					check_precision(char **str);
int					check_type(char **str);
int					check_width(char **str, va_list ap);
void				fill_width(t_info info, char **out);
void				print_str(char *str);
int					ft_printf(const char *str, ...);
int					print_d(t_info *info, va_list ap);
int					print_c(t_info *info, va_list ap);
int					print_s(t_info *info, va_list ap);
int					print_p(t_info *info, va_list ap);
int					print_invalid_type(t_info *info, int value);

#endif
