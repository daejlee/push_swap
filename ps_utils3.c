#include "push_swap.h"
#include "./libft_garage/ft_printf/ft_printf.h"

t_decue	*get_bottom_adr(t_decue *top)
{
	while (top->next)
		top = top->next;
	return (top);
}

void	push_and_rev_b(t_decue_addr *p, unsigned int count, unsigned int pushing_int, unsigned int div)
{
	unsigned int	target_dig;

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
}

void	sort_loop_to_b(t_decue_addr *p, unsigned int div)
{
	unsigned int	count;
	unsigned int	pushing_int;

	pushing_int = 0;
	while (p->a_top)
	{
		while (pushing_int < 10)
		{
			count = get_count(p->a_top, div, pushing_int);
			push_and_rev_b(p, count, pushing_int, div);
			pushing_int++;
		}
		p->a_bottom = NULL;
		p->b_bottom = get_bottom_adr(p->b_top);
		ft_printf("-------------------------------\n");
		ft_printf("%i div radix sort's result is...\n", div);
		ft_printf("-------------------------------\n");
		print_stack(p);
	}
}

void	push_and_rev_a(t_decue_addr *p, unsigned int count, unsigned int pushing_int, unsigned int div)
{
	unsigned int	target_dig;

	while (count)
	{
		target_dig = get_dig(p->b_top->val, div);
		if (target_dig == pushing_int)
		{
			pa(p);
			count--;
		}
		else
			rb(p);
	}
}

void	sort_loop_to_a(t_decue_addr *p, unsigned int div)
{
	unsigned int	count;
	unsigned int	pushing_int;

	pushing_int = 0;
	while (p->b_top)
	{
		while (pushing_int < 10)
		{
			count = get_count(p->b_top, div, pushing_int);
			push_and_rev_a(p, count, pushing_int, div);
			pushing_int++;
		}
		p->b_bottom = NULL;
		p->a_bottom = get_bottom_adr(p->a_top);
		ft_printf("-------------------------------\n");
		ft_printf("%i div radix sort's result is...\n", div);
		ft_printf("-------------------------------\n");
		print_stack(p);
	}
}
