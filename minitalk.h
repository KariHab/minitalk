/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:42:41 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/20 12:18:45 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

static void	ft_bintoa(int sig_num);
int			ft_atoi(const char *str);
static void	ft_atobin(int pid, char c);

#endif
