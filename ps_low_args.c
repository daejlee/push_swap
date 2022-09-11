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

static void	two_args(t_decue_addr *p)
{
	if (p->a_top->val > p->a_top->next->val)
		sa(p);
}

static void	three_args(t_decue_addr *p)
{
	while (p->a_bottom->val != p->max)
		ra(p);
	if (p->a_top->val != p->min)
		sa(p);
}

static void	four_args(t_decue_addr *p)
{
	while (p->a_top->val != p->min)
		ra(p);
	while (p->a_bottom->val != p->max)
	{
		rra(p);
		sa(p);
	}
	if (p->a_top->next->val > p->a_bottom->previous->val)
	{
		ra(p);
		sa(p);
		rra(p);
	}
}

void	low_arg_sort(int size, t_decue_addr *p)
{
	if (size == 2)
		two_args(p);
	else if (size == 3)
		three_args(p);
	else if (size == 4)
		four_args(p);
	//else
	//	five_args(p);
}
