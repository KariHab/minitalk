/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:56:07 by khabbout          #+#    #+#             */
/*   Updated: 2023/02/27 13:04:41 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(fd, s, ft_strlen(s)));
}

static int	get_size_int(int long nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	size;

	size = get_size_int(n);
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
	{
		ft_putchar_fd((n + 48), fd);
	}
	return (size);
}
