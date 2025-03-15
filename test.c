#include <stdio.h>
#include <unistd.h>
int	ft_atoi(const char *str)
{
	long	sign;
	long	num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	else if (*str == '-' || *str == '+')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * sign) > 2147483647 || (num * sign) <= 0 )
			return (-1);
		str++;
	}
	return (sign * num);
}

int main(void) {
    // printf("Sleeping for 500000 microseconds...\n");
    // usleep(5000000 );
    // printf("Done sleeping.\n");
// 2147483647
	printf("%i\n", ft_atoi("147483"));
    return 0;
}
