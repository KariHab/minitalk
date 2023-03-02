/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:53 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/02 15:07:30 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#	ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

void	ft_bintoa(int sig_num);
int		ft_atoi(const char *str);
void	ft_atobin(int pid, char c);
void    got_it(int signal);

#endif
