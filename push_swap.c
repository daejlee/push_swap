#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

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
			if (ft_strlen(argv[i]) == ft_strlen(argv[j])
				&& !ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	purge_lst(t_decue *top)
{
	t_decue	*temp1;
	t_decue	*temp2;

	temp1 = top;
	while (temp1)
	{
		temp2 = temp1->next;
		temp1->previous = NULL;
		temp1->next = NULL;
		free(temp1);
		temp1 = temp2;
	}
	return (1);
}

int	push_args_to_a(char **argv, t_decue_addr *p)
{
	unsigned int	i;
	t_decue			*temp1;
	t_decue			*temp2;

	temp1 = (t_decue *)malloc(sizeof(t_decue));
	if (!temp1)
		return (1);
	temp1->previous = NULL;
	temp1->val = ft_atoi(argv[1]);
	p->a_top = temp1;
	i = 2;
	while (argv[i])
	{
		temp2 = (t_decue *)malloc(sizeof(t_decue));
		if (!temp2)
			return (purge_lst(p->a_top));
		temp1->next = temp2;
		temp2->previous = temp1;
		temp2->val = ft_atoi(argv[i]);
		temp1 = temp2;
		i++;
	}
	temp1->next = NULL;
	p->a_bottom = temp1;
	return (0);
}

void	print_stack(t_decue_addr p)
{
	t_decue	*head;

	head = p.a_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\na\n");
}

int	main(int argc, char **argv)
{
	t_decue_addr	p;

	if (argc == 1)
		return (1);
	else if (check_arg(argv))
		return (print_err());
	if (push_args_to_a(argv, &p))
		return (1);
	print_stack(p);
	return (0);
}
