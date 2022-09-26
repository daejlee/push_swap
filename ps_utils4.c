/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:10:17 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/17 15:10:18 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./push_swap.h"

static void	part(t_decue *top, t_decue_addr *p)
{
	if (top->val > top->next->val)
	{
		sa(p);
		ra(p);
		ra(p);
		pb(p);
		rra(p);
		rra(p);
		pa(p);
	}
	else if (top->val < top->next->next->val)
	{
		pb(p);
		sa(p);
		pa(p);
	}
	else
	{
		ra(p);
		ra(p);
		pb(p);
		rra(p);
		rra(p);
		pa(p);
	}
}

static void	recur_three_range(t_decue *top, t_decue_addr *p)
{
	if (top->val < top->next->val
		&& top->next->val < top->next->next->val)
		return ;
	else if (top->next->val > top->next->next->val)
		part(top, p);
	else
	{
		if (top->val > top->next->next->val)
		{
			ra(p);
			pb(p);
			pb(p);
			rra(p);
			pa(p);
			pa(p);
		}
		else
			sa(p);
	}
}

void	recur_less_range(t_decue *top, unsigned int range, t_decue_addr *p)
{
	unsigned int	temp;

	temp = range;
	if (top == p->b_top)
	{
		while (temp--)
			pa(p);
		top = p->a_top;
	}
	if (range == 3)
		recur_three_range(p->a_top, p);
	else if (range == 2)
	{
		if (top->val > top->next->val)
			sa(p);
	}
}
