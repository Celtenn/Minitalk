#include <signal.h>
#include <unistd.h>
void	ft_putnbr(int n)
{
	char c;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c , 1);
	}
}

void	ft_server(int sig)
{
	static int count;
	static char len_bit;

	if (sig == SIGUSR1)
	{
		len_bit = (len_bit << 1) | 0;
		count++;
	}
	else if (sig == SIGUSR2)
	{
		len_bit = (len_bit << 1) | 1;
		count++;
	}
	if (count == 8)
	{
		write(1, &len_bit, 1);
		count = 0;
		len_bit = 0;
	}
}

int main()
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