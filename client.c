/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:29 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/21 13:57:59 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*convert a char to an int*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	if (str == NULL)
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
	int		bit;

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
		if (!av[2])
			return (1);
		while (av[2][index])
		{
			ft_atobin(server_pid, av[2][index]);
			index++;
		}
		if (av[2][index] == '\0')
			ft_atobin(server_pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
