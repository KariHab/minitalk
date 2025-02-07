/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/04/06 10:04:44 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	got_it(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("\033[1;32mSignal has been confirmed by server!\n");
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_atobin(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c &(0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	index;

	index = 0;
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		while (av[2][index])
		{
			ft_atobin(server_pid, av[2][index]);
			index++;
		}
		signal(SIGUSR2, got_it);
		ft_atobin(server_pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
