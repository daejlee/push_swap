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
	if (argc == 3)
		two_args(p);
	else if (argc == 4)
		three_args(p);
}
