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

void	print_stack(t_decue_addr *p)
{
	t_decue	*temp;

	temp = p->a_top;
	ft_printf("-----------------------\n");
	while (temp)
	{
		ft_printf("%i ", temp->val);
		temp = temp->next;
	}
	ft_printf("| a\n");
	temp = p->b_top;
	while (temp)
	{
		ft_printf("%i ", temp->val);
		temp = temp->next;
	}
	ft_printf("| b\n");
	ft_printf("-----------------------\n");
}

void	rewind(t_decue_addr *p, unsigned int ra_count, unsigned int rb_count)
{
	while (ra_count && rb_count)
	{
		rrr(p);
		ra_count--;
		rb_count--;
	}
	while (ra_count--)
		rra(p);
	while (rb_count--)
		rrb(p);
}

void	get_next_pivot1(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	i;

	i = 0;
	while (p->idx_chamber[i] != pivot)
		i++;
	i += range / 3;
	p->pivot1 = p->idx_chamber[i];
	i += range / 3;
	p->pivot2 = p->idx_chamber[i];
}

void	get_next_pivot2(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	i;

	i = 0;
	while (p->idx_chamber[i] != pivot)
		i++;
	i -= range / 3;
	p->pivot2 = p->idx_chamber[i];
	i -= range / 3;
	p->pivot1 = p->idx_chamber[i];
}

void	b_to_a_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pa_count;
	unsigned int	ra_count;
	unsigned int	rb_count;

	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	if (range <= 3)
		return (recur_less_range(p->b_top, range, p));
	get_next_pivot2(p, pivot, range);
	while (range--)
	{
		if (p->b_top->val >= p->pivot1)
		{
			pa_count += pa(p);
			if (p->a_top->val < p->pivot2)
				ra_count += ra(p);
		}
		else
			rb_count += rb(p);
	}
	a_to_b_recur(p, p->pivot2, pa_count - ra_count);
	rewind(p, ra_count, rb_count);
	a_to_b_recur(p, p->pivot1, ra_count);
	b_to_a_recur(p, p->pivot1, rb_count);
}

void	a_to_b_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pb_count;
	unsigned int	ra_count;
	unsigned int	rb_count;

	pb_count = 0;
	ra_count = 0;
	rb_count = 0;
	if (check_already_sorted(p->a_top))
		return ;
	if (range <= 3)
		return (recur_less_range(p->a_top, range, p));
	get_next_pivot1(p, pivot, range);
	while (range--)
	{
		if (p->a_top->val <= p->pivot2)
		{
			pb_count += pb(p);
			if (p->b_top->val >= p->pivot1)
				rb_count += rb(p);
		}
		else
			ra_count += ra(p);
	}
	rewind(p, ra_count, rb_count);
	a_to_b_recur(p, p->pivot2, ra_count);
	b_to_a_recur(p, p->pivot2, rb_count);
	b_to_a_recur(p, p->pivot1, pb_count - rb_count);
}
