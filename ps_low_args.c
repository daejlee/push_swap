/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_low_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:05:52 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:05:54 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_args(t_decue_addr *p)
{
	if (check_already_sorted(p->a_top))
		return ;
	else if (p->a_top->val > p->a_top->next->val)
	{
		if (p->a_top->next->val > p->a_bottom->val)
		{
			sa(p);
			rra(p);
		}
		else if (p->a_top->val < p->a_bottom->val)
			sa(p);
		else
			ra(p);
	}
	else
	{
		if (p->a_top->val < p->a_bottom->val)
		{
			sa(p);
			ra(p);
		}
		else
			rra(p);
	}
}

static void	four_args(t_decue_addr *p)
{
	while (p->a_top->val != p->min)
		ra(p);
	pb(p);
	three_args(p);
	pa(p);
}

static void	five_args(t_decue_addr *p)
{
	while (p->a_top->val != p->max && p->a_top->val != p->min)
		ra(p);
	pb(p);
	while (p->a_top->val != p->max && p->a_top->val != p->min)
		ra(p);
	pb(p);
	three_args(p);
	if (p->b_top->val == p->max)
	{
		pa(p);
		ra(p);
		pa(p);
	}
	else
	{
		pa(p);
		pa(p);
		ra(p);
	}
}

void	low_arg_sort(t_decue_addr *p)
{
	if (p->size == 2)
	{
		if (p->a_top->val > p->a_top->next->val)
			sa(p);
	}
	else if (p->size == 3)
		three_args(p);
	else if (p->size == 4)
		four_args(p);
	else
		five_args(p);
}
