/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:29 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/17 21:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*le fichier exe doit se normer client - SIGUSR1 pour le client 
prend 2 param le PID et la chaine de str a envoyer
doit l'envoyer au server
get pid pour avoir le pid du client
kill() pour envoyer un signal au server

Pseudocode:
get the server pid in arg
send a char

*/

#include "minitalk.h"
/*bonus part confirm message*/
// void	got_it(int signal)
// {
// 	if (signal == SIGUSR2)
// 		ft_printf("Message received!\n");	
// }

/*convert a char to an int*/
int ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

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

/*convert a to binary*/
void	ft_atobin(int pid, char c)
{
	int bit;
	
	bit = 0;
	while (bit < 8)
	{
		if ((c &(0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
			
	}
}
int main(int ac, char **av)
{
	int server_pid;
	int index;

	index = 0;
	// faut nom du prog - pid - message donc ac 3
	if (ac == 3)
	{
		// get the server pid converted in int with atoi()
		server_pid = ft_atoi(av[1]);
		while (av[2][index])
		{
			ft_atobin(server_pid, av[2][index]);
			index++;
		}
		// //bonus 
		// signal(SIGUSR2, got_it);
		// ft_atobin(pid, '\0');
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
