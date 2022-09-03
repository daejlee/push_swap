#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	print_stack(t_decue_addr *p)
{
	t_decue	*head;

	head = p->a_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\na\n");
}

int	main(int argc, char **argv)
{
	t_decue_addr	*p;

	if (argc == 1)
		return (1);
	else if (is_int(argv) || is_there_dup(argv))
		return (print_err());
	p = init_p();
	p->size = push_args_to_a(argv, p);
	if (!p->size)
		return (1);
	print_stack(p);
	if (check_already_sorted(p->a_top))
		return (purge_lst(p));
	return (purge_lst(p));
}
