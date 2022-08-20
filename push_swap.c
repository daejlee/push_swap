#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include <unistd.h>

int	print_err(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	return (1);
}

int	check_arg(char **argv)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (argv[i])
	{
		if (ft_strncmp(ft_itoa(ft_atoi(argv[i])), argv[i], ft_strlen(argv[i])))
			return (1);
		i++;
	}
	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j]) &&
					!ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	else if (check_arg(argv))
		return (print_err());
}