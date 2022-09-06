#include "./libft_garage/libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	leaks()
{
	system("leaks push_swap");
}

int	print_err(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	return (1);
}

int	purge_lst(t_decue_addr *p)
{
	t_decue	*temp1;
	t_decue	*temp2;

	temp1 = p->a_top;
	while (temp1)
	{
		temp2 = temp1->next;
		temp1->previous = NULL;
		temp1->next = NULL;
		free(temp1);
		temp1 = temp2;
	}
	temp1 = p->b_top;
	while (temp1)
	{
		temp2 = temp1->next;
		temp1->previous = NULL;
		temp1->next = NULL;
		free(temp1);
		temp1 = temp2;
	}
	if (p->idx_chamber)
		free (p->idx_chamber);
	free (p);
	atexit(leaks);
	return (0);
}
