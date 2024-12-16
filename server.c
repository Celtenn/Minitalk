/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:38:58 by idkahram          #+#    #+#             */
/*   Updated: 2024/12/17 00:31:18 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	ft_server(int sig)
{
	static int	result;
	static int	number = 128;

	if (sig == SIGUSR2)
		result = result + number;
	number = number / 2;
	if (number == 0)
	{
		write(1, &result, 1);
		result = 0;
		number = 128;
	}
}

int	main(void)
{
	int	t;

	signal(SIGUSR2, ft_server);
	signal(SIGUSR1, ft_server);
	t = getpid();
	ft_putnbr(t);
	while (1)
	{
		pause();
	}
}
