/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idkahram <idkahram@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:36:05 by idkahram          #+#    #+#             */
/*   Updated: 2025/01/27 19:59:36 by idkahram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_bit_sender(char f, int pid)
{
	int	bit;

	bit = 7;
	while (bit > -1)
	{
		if ((f >> bit) & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(500);
	}
}

void	ft_kill(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_bit_sender(str[i], pid);
		i++;
	}
	ft_bit_sender('\n', pid);
}

int	main(int argc, char **argv)
{
	int		nbr;
	char	*str;

	if (argc == 3)
	{
		nbr = ft_atoi(argv[1]);
		str = argv[2];
		if (nbr <= 0)
			return (-1);
		ft_kill(nbr, str);
	}
}
