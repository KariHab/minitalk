/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:47:37 by khabbout          #+#    #+#             */
/*   Updated: 2023/03/22 15:57:57 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//antoine 
char	*join_char_to_str(char *str, char letter)
{
	size_t	index;
	char	*new_str;
	int		letter_count;

	index = 0;
	new_str = ft_calloc(sizeof(char), ft_strlen(str) + 2);
	if (!new_str)
		return (NULL);
	while (str[index])
	{
		new_str[index] = str[index];
		index++;
	}
	new_str[index] = letter;
	if (str)
		free(str);
	ft_printf("%s\n", new_str);
	return (new_str);
}


// char	*join_char_to_str(char *str, char letter)
// {
// 	size_t			index;
// 	char			*new_str;
// 	int				letter_count;

// 	index = 0;
// 	if (letter)
// 		letter_count++;
// 	new_str = ft_calloc(sizeof(char), letter_count + 1);
// 	if (!new_str)
// 		return (NULL);
// 	if (str)
// 	{
// 		while (str[index])
// 		{
// 			new_str[index] = str[index];
// 			index++;
// 		}
// 	}
// 	new_str[index] = letter;
// 	ft_printf("%s", new_str);
// 	return (new_str);
// }


void	ft_bintoa(int sig_num)
{
	static int	bit;
	static char	letter;
	static char	*str;

	ft_printf("ici\n");
	if (sig_num == SIGUSR1)
		letter |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		str = join_char_to_str(str, letter);
		ft_printf("ici2\n");
		if (letter == 0)
			ft_printf("%s\n", str);
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
