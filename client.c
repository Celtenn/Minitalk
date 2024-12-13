#include <signal.h>
#include <unistd.h>
int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while(str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * n);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_kill(int pid, char *str)
{
	int len;
	int bit;
	int i;

	len = ft_strlen(str);
	str[len] = '\n';
	str[len + 1] = '\0';
	i = 0;
	while (str[i] != '\0')
	{
		bit = 7;
		while (bit > -1)
		{
			if ((str[i] >> bit) & 1)
			{
				kill(pid, SIGUSR2);
			}
			else
				kill(pid, SIGUSR1);
			bit--;
			usleep(100);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int nbr;
	char *str;

	if (argc == 3)
	{
		nbr = ft_atoi(argv[1]);
		str = argv[2];
		ft_kill(nbr, str);
	}
}
