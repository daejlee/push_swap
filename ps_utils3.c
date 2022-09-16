/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:41 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:06:41 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft_garage/ft_printf/ft_printf.h"

void	rewind(t_decue_addr *p, unsigned int ra_count, unsigned int rb_count)
{
	while (ra_count--)
		rra(p);
	while (rb_count--)
		rrb(p);
}

int	get_next_pivot(t_decue_addr *p, int pivot, unsigned int p_count)
{
	unsigned int	i;

	i = 0;
	while (p->idx_chamber[i] != pivot)
		i++;
	if (p_count == 1)
		i -= 1;
	else
		i -= p_count / 2;
	return (p->idx_chamber[i]);
}

int	get_bigger_pivot(t_decue_addr *p, int pivot, unsigned int p_count)
{
	unsigned int	i;

	i = 0;
	while (p->idx_chamber[i] != pivot)
		i++;
	if (p_count == 1)
		i += 1;
	else
		i += p_count / 2;
	return (p->idx_chamber[i]);
}

void	b_to_a_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pa_count;
	unsigned int	rb_count;

	pa_count = 0;
	rb_count = 0;
	if (range <= 1)
		return (pa(p));
	pivot = get_bigger_pivot(p, pivot, range);
	while (range--)
	{
		if (p->b_top->val < pivot)
		{
			pa(p);
			pa_count++;
		}
		else
		{
			rb(p);
			rb_count++;
		}
	}
	rewind(p, 0, rb_count);
	a_to_b_recur(p, get_next_pivot(p, pivot, pa_count), pa_count);
	b_to_a_recur(p, pivot, rb_count);
}

void	a_to_b_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pb_count;
	unsigned int	ra_count;

	pb_count = 0;
	ra_count = 0;
	if (range <= 1)
		return ;
	while (range--)
	{
		if (p->a_top->val >= pivot)
		{
			pb(p);
			pb_count++;
		}
		else
		{
			ra(p);
			ra_count++;
		}
	}
	rewind(p, ra_count, 0);
	a_to_b_recur(p, get_next_pivot(p, pivot, pb_count), ra_count);
	b_to_a_recur(p, pivot, pb_count);
}
