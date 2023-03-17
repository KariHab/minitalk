/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/17 14:47:23 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	stock_str(char letter)
{
	char *str;

	str = malloc(ft_strlen(str) * sizeof(char));
	str[ft_strlen(str)] = letter;
	if(letter == '\0')
		ft_printf("%s", str);
}
void	ft_bintoa(int sig_num)
{
	static int	bit;
	static int	letter;
	char		*str;
	int index_str;
	int len;

	index_str = 0;
	if (sig_num == SIGUSR1)
		letter |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if(letter == 0)
			stock_str('\0');
		stock_str(letter);
		bit = 0;
		letter = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	(void) av;
	server_pid = getpid();
	ft_printf("\033[1;36mPID: %d\n", server_pid);
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
