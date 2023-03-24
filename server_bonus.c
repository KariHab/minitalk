/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:53:15 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/24 11:55:02 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_bintoa(int sig_num, siginfo_t *info, void *context)
{
	static int				bit;
	static unsigned char	letter;
	static char				*str;
	char					*tmp;

	(void)context;
	if (sig_num == SIGUSR1)
		letter |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		str = make_str(str, letter);
		if (letter == '\0')
		{
			tmp = str;
			kill(info->si_pid, SIGUSR2);
			ft_printf("%s", str);
			free(str);
			str = NULL;
		}
		bit = 0;
		letter = 0;
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
