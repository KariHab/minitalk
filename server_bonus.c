/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:15 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/10 12:44:39 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_bintoa(int sig_num, siginfo_t *info, void *context)
{
	static int	bit;
	static int	index;

	(void)context;
	(void)info;
	if (sig_num == SIGUSR1)
		index |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (index == 0)
			kill(info->si_pid, SIGUSR2);
		ft_printf("%c", index);
		bit = 0;
		index = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t				server_pid;
	struct sigaction	new_act;

	(void) av;
	server_pid = getpid();
	ft_printf("\033[1;36mPID: %d\n", server_pid);
	new_act.sa_sigaction = ft_bintoa;
	sigemptyset(&new_act.sa_mask);
	new_act.sa_flags = 0;
	while (ac == 1)
	{
		sigaction(SIGUSR1, &new_act, NULL);
		sigaction(SIGUSR2, &new_act, NULL);
		pause();
	}
	if (ac != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
