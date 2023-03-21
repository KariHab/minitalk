/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/21 14:11:28 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*join_char_to_str(char *str, char letter)
{
	size_t			index;
	static char		*new_str;
	int				letter_count;

	index = 0;
	if (letter)
		letter_count++;
	new_str = ft_calloc(sizeof(char), letter_count + 1);
	if (!new_str)
		return (NULL);
	while (letter_count)
	{
		new_str[index] = letter;
		index++;
		letter_count--;
	}
	ft_printf("%s", new_str);
	return (new_str);
}

void	ft_bintoa(int sig_num)
{
	static int	bit;
	static char	letter;
	static char	*str;

	if (sig_num == SIGUSR1)
		letter |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		str = join_char_to_str(str, letter);
		letter = 0;
		bit = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	(void)av;
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
