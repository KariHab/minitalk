/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/20 12:21:15 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*make_str(char *str, char c)
{
	int		index;
	int		str_len;
	char	*new_str;

	index = 0;
	if (!str)
	{
		new_str = ft_calloc(sizeof(char), 2);
		new_str[0] = c;
		free(str);
		return (new_str);
	}
	str_len = ft_strlen(str);
	new_str = ft_calloc(sizeof(char), (str_len + 2));
	while (str[index])
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = c;
	free(str);
	return (new_str);
}

static void	ft_bintoa(int sig_num)
{
	static int				bit;
	static unsigned char	letter;
	static char				*str;

	if (sig_num == SIGUSR1)
		letter |= (0x01 << bit);
	bit ++;
	if (bit == 8)
	{
		str = make_str(str, letter);
		if (letter == '\0')
			ft_printf("%s", str);
		letter = 0;
		bit = 0;
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
