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

void	recur_three_range(t_decue *top, t_decue_addr *p)
{
	if (top->val > top->next->val &&
			top->next->val > top->next->next->val)
		return ;
	else if (top->next->val < top->next->next->val)
	{
		if (top->val < top->next->val)
		{
			sa(p);
			ra(p);
			ra(p);
			pb(p);
			rra(p);
			rra(p);
			pa(p);
		}
		else if (top->val > top->next->next->val)
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
	else
	{
		if (top->val < top->next->next->val)
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
	if (range == 2)
	{
		if (top->val < top->next->val)
				sa(p);
	}
}

void	b_to_a_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pa_count;
	unsigned int	rb_count;

	pa_count = 0;
	rb_count = 0;
	if (range <= 3)
		return (recur_less_range(p->b_top, range, p));
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
	if (range <= 3)
		return (recur_less_range(p->a_top, range, p));
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
