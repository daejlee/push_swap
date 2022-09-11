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

static void	three_args(t_decue_addr *p, int max, int min)
{
	while (p->a_bottom->val != max)
		ra(p);
	if (p->a_top->val != min)
		sa(p);
}

static void	four_args(t_decue_addr *p)
{
	int		min;
	t_decue	*targ;

	while (p->a_top->val != p->min)
		ra(p);
	pb(p);
	targ = p->a_top->next;
	min = p->a_top->val;
	while (targ)
	{
		if (targ->val < min)
			min = targ->val;
		targ = targ->next;
	}
	three_args(p, p->max, min);
	pa(p);
}

static void	get_min_max(t_decue_addr *p, int *min, int *max)
{
	t_decue	*targ;

	targ = p->a_top->next;
	*min = p->a_top->val;
	*max = p->a_top->val;
	while (targ)
	{
		if (targ->val < min)
			*min = targ->val;
		if (targ->val > max)
			*max = targ->val;
		targ = targ->next;
	}
}

static void	five_args(t_decue_addr *p)
{
	int		min;
	int		max;
	t_decue	*targ;

	while (p->a_top->val != p->max && p->a_top->val != p->min)
		ra(p);
	pb(p);
	while (p->a_top->val != p->max && p->a_top->val != p->min)
		ra(p);
	pb(p);
	get_min_max(p, &min, &max);
	three_args(p, max, min);
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
		three_args(p, p->max, p->min);
	else if (p->size == 4)
		four_args(p);
	else
		five_args(p);
}
