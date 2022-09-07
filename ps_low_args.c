#include "push_swap.h"

static void	two_args(t_decue_addr *p)
{
	if (p->a_top->val > p->a_top->next->val)
		sa(p);
}

static void	three_args(t_decue_addr *p)
{
	while (p->a_top->val != p->min)
		ra(p);
	if (p->a_top->next->val > p->a_bottom->val)
	{
		ra(p);
		sa(p);
		rra(p);
	}
}

void	manual_sort(int argc, t_decue_addr *p)
{
	if (argc == 2)
		two_args(p);
	else
		three_args(p);
}
