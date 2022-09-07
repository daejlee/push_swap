#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

//./push_swap 1 2 7 11 22 927 731 33

void	print_stack(t_decue_addr *p)
{
	t_decue	*head;

	ft_printf("-------------------------------\n");
	ft_printf("signed val is following.....\n");
	ft_printf("-------------------------------\n");
	head = p->a_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\na\n");
	head = p->b_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\nb\n");
	ft_printf("-------------------------------\n");
	ft_printf("unsigned val is following.....\n");
	ft_printf("-------------------------------\n");
	head = p->a_top;
	while (head)
	{
		ft_printf("%u\n", head->u_val);
		head = head->next;
	}
	ft_printf("-\na\n");
	head = p->b_top;
	while (head)
	{
		ft_printf("%u\n", head->u_val);
		head = head->next;
	}
	ft_printf("-\nb\n");
}

unsigned int	get_dig(unsigned int val, unsigned int div)
{
	if (div == 1)
		return (val % 10);
	else
	{
		div *= 10;
		val %= div;
		div /= 10;
		return (val /= div);
	}
}

unsigned int	get_count(t_decue *target, unsigned int div, unsigned int pushing_int)
{
	unsigned int	count;
	unsigned int	target_dig;

	count = 0;
	while (target)
	{
		target_dig = get_dig(target->u_val, div);
		if (target_dig == pushing_int)
			count++;
		target = target->previous;
	}
	return (count);
}

void	radix_sort(t_decue_addr *p)
{
	unsigned int	div;
	t_decue			*target;

	div = 1;
	target = p->a_top;
	p->idx_chamber = (int *)malloc(sizeof(int) * p->size);
	if (!p->idx_chamber)
	{
		print_err();
		return ;
	}
	while (p->max / div)
	{
		if (target == p->a_top)
		{
			sort_loop_to_b(p, div);
			target = p->b_top;
		}
		else
		{
			sort_loop_to_a(p, div);
			target = p->a_top;
		}
		div *= 10;
	}
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
	radix_sort(p);
	return (purge_lst(p));
}
