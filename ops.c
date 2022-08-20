#include "./push_swap.h"
#include <stdlib.h>
#include "./libft_garage/ft_printf/ft_printf.h"

void	swap(t_decue **top_adr)
{
	t_decue	*top;
	int		temp;

	top = *top_adr;
	if (top && top->next)
	{
		temp = top->val;
		top->val = top->next->val;
		top->next->val = temp;
	}
}

void	sa(t_decue **a_top_adr)
{
	swap(a_top_adr);
	ft_printf("sa\n");
}

void	sb(t_decue **b_top_adr)
{
	swap(b_top_adr);
	ft_printf("sb\n");
}

void	ss(t_decue **a_top_adr, t_decue **b_top_adr)
{
	sa(a_top_adr);
	sb(b_top_adr);
	ft_printf("ss\n");
}

void	pa(t_decue **a_top_adr, t_decue **b_top_adr)
{
	t_decue	*a_top;
	t_decue	*b_top;

	a_top = *a_top_adr;
	b_top = *b_top_adr;
	if (!b_top)
		return ;
	*a_top_adr = b_top;
	*b_top_adr = b_top->next;

	b_top->next->previous = NULL;
	b_top->next = a_top;
	a_top->previous = b_top;
	ft_printf("pa\n");
}

void	pb(t_decue **a_top_adr, t_decue **b_top_adr)
{
	t_decue	*a_top;
	t_decue	*b_top;

	a_top = *a_top_adr;
	b_top = *b_top_adr;
	if (!a_top)
		return ;
	*b_top_adr = a_top;
	*a_top_adr = b_top->next;

	a_top->next->previous = NULL;
	a_top->next = b_top;
	b_top->previous = a_top;
	ft_printf("pb\n");
}

void	rotate(t_decue **top_adr, t_decue **bottom_adr)
{
	t_decue	*top;
	t_decue	*bottom;

	top = *top_adr;
	bottom = *bottom_adr;
	*top_adr = top->next;
	*bottom_adr = top;

	bottom->next = top;
	top->previous = bottom;
	top->next = NULL;
}

void	ra(t_decue **a_top_adr, t_decue **a_bottom_adr)
{
	rotate(a_top_adr, a_bottom_adr);
	ft_printf("ra\n");
}

void	rb(t_decue **b_top_adr, t_decue **b_bottom_adr)
{
	rotate(b_top_adr, b_bottom_adr);
	ft_printf("rb\n");
}

void	rr(t_decue_addr **p_adr)
{
	t_decue_addr	*p;

	p = *p_adr;
	ra(&p->a_top, &p->a_bottom);
	rb(&p->b_top, &p->b_bottom);
}

void	reverse_rotate(t_decue **top_adr, t_decue **bottom_adr)
{
	t_decue	*top;
	t_decue	*bottom;

	top = *top_adr;
	bottom = *bottom_adr;
	*top_adr = bottom;
	*bottom_adr = bottom->previous;

	bottom->next = top;
	bottom->previous = NULL;
	top->previous = bottom;
}

void	rra(t_decue **a_top_adr, t_decue **a_bottom_adr)
{
	reverse_rotate(a_top_adr, a_bottom_adr);
	ft_printf("rra\n");
}

void	rrb(t_decue **b_top_adr, t_decue **b_bottom_adr)
{
	reverse_rotate(b_top_adr, b_bottom_adr);
	ft_printf("rrb\n");
}

void	rrr(t_decue_addr **p_adr)
{
	t_decue_addr	*p;

	p = *p_adr;
	rra(&p->a_top, &p->a_bottom);
	rrb(&p->b_top, &p->b_bottom);
}
