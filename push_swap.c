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

unsigned int	get_dig(int val, unsigned int div)
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

void	radix_sort(t_decue_addr *p)
{
	unsigned int	div;
	unsigned int	count;
	t_decue			*target;
	unsigned int	pushing_int;
	//t_decue			*using_stack;
	unsigned int	target_dig;

	div = 1;
	count = 0;
	pushing_int = 0;
	while (p->a_top)
	{
		while (pushing_int < 10)
		{
			target = p->a_top;
			while (target)
			{
				target_dig = get_dig(target->val, div);
				if (target_dig == pushing_int)
					count++;
				target = target->next;
			}
			while (count)
			{
				target_dig = get_dig(p->a_top->val, div);
				if (target_dig == pushing_int)
				{
					pb(p);
					count--;
				}
				else
					ra(p);
			}
			pushing_int++;
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
