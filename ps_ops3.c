#include "./push_swap.h"
#include <stdlib.h>
#include "./libft_garage/ft_printf/ft_printf.h"

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
