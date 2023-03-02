/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:15 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/02 14:55:15 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bintoa(int sig_num)
{
	static int	bit;
	static int	index;

	if (sig_num == SIGUSR1)
		index |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", index);
		bit = 0;
		index = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	(void) av;
	server_pid = getpid();
	ft_printf("PID: %d\n", server_pid);
	while (ac == 1)
	{
		signal(SIGUSR1, ft_bintoa);
		signal(SIGUSR2, ft_bintoa);
		pause();
	}
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
