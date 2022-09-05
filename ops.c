#include "./push_swap.h"
#include <stdlib.h>
#include "./libft_garage/ft_printf/ft_printf.h"

void	swap(t_decue *top)
{
	int		temp;

	if (top && top->next)
	{
		temp = top->val;
		top->val = top->next->val;
		top->next->val = temp;
	}
}

void	sa(t_decue_addr *p)
{
	swap(p->a_top);
	ft_printf("sa\n");
}

void	sb(t_decue_addr *p)
{
	swap(p->b_top);
	ft_printf("sb\n");
}

void	ss(t_decue_addr *p)
{
	sa(p);
	sb(p);
	ft_printf("ss\n");
}

void	pa(t_decue_addr *p)
{
	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	if (p->a_top)
	{
		p->a_top->previous = p->b_top;
		p->b_top->next = p->a_top;
		p->a_top = p->b_top;
		p->b_top = p->b_top->next;
	}
	else
	{
		p->a_top = p->b_top;
		p->a_top->next = NULL;
		p->b_top = p->b_top->next;
	}
	ft_printf("pa\n");
}

void	pb(t_decue_addr *p)
{
	t_decue	*temp;

	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	if (p->b_top)
	{
		p->b_top->previous = p->a_top;
		temp = p->a_top->next;
		p->a_top->next = p->b_top;
		p->b_top = p->a_top;
		p->a_top = temp;
	}
	else
	{
		p->b_top = p->a_top;
		temp = p->a_top->next;
		p->b_top->next = NULL;
		p->a_top = temp;
	}
	ft_printf("pb\n");
}

void	ra(t_decue_addr *p)
{
	t_decue	*temp;

	p->a_top->previous = p->a_bottom;
	p->a_bottom->next = p->a_top;
	if (p->a_bottom->previous)
		p->a_bottom->previous->next = NULL;
	temp = p->a_bottom->previous;
	p->a_bottom->previous = NULL;
	p->a_top = p->a_bottom;
	p->a_bottom = temp;
	ft_printf("ra\n");
}

void	rb(t_decue_addr *p)
{
	t_decue	*temp;

	p->b_top->previous = p->b_bottom;
	p->b_bottom->next = p->b_top;
	if (p->b_bottom->previous)
		p->b_bottom->previous->next = NULL;
	temp = p->b_bottom->previous;
	p->b_bottom->previous = NULL;
	p->b_top = p->b_bottom;
	p->b_bottom = temp;
	ft_printf("rb\n");
}

void	rr(t_decue_addr *p)
{
	ra(p);
	rb(p);
}

void	rra(t_decue_addr *p)
{
	p->a_top = p->a_bottom;
	p->a_bottom = p->a_bottom->previous;

	p->a_bottom->next = p->a_top;
	p->a_bottom->previous = NULL;
	p->a_top->previous = p->a_bottom;
	ft_printf("rra\n");
}

void	rrb(t_decue_addr *p)
{
	p->b_top = p->b_bottom;
	p->b_bottom = p->b_bottom->previous;

	p->b_bottom->next = p->b_top;
	p->b_bottom->previous = NULL;
	p->b_top->previous = p->b_bottom;
	ft_printf("rrb\n");
}

void	rrr(t_decue_addr *p)
{
	rra(p);
	rrb(p);
}
