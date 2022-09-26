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

void		get_next_pivot1(t_decue_addr *p, int pivot, unsigned int range)
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

void		get_next_pivot2(t_decue_addr *p, int pivot, unsigned int range)
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

int	is_skippable(t_decue_addr *p, t_decue *head, unsigned int range)
{
	if (!range)
		return (0);
	range += 1;
	if (head == p->a_top)
	{
		while (range--)
		{
			if (head->val > p->pivot2)
				head = head->next;
			else
				return (0);
		}
	}
	else
	{
		while (range--)
		{
			if (head->val < p->pivot1)
				head = head->next;
			else
				return (0);
		}
	}
	return (1);
}

void	b_to_a_recur(t_decue_addr *p, int pivot, unsigned int range)
{
	unsigned int	pa_count;
	unsigned int	ra_count;
	unsigned int	rb_count;

	// ft_printf("b to a | pivot1: %i, pivot2: %i.\n", p->pivot1, p->pivot2);
	// print_stack(p);
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
			pa(p);
			pa_count++;
			if (p->a_top->val < p->pivot2)
			{
				ra(p);
				ra_count++;
			}
		}
		else
		{
			rb(p);
			rb_count++;
		}
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

	// ft_printf("a to b | pivot1: %i, pivot2: %i.\n", p->pivot1, p->pivot2);
	// print_stack(p);
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
			pb(p);
			pb_count++;
			if (p->b_top->val >= p->pivot1)
			{
				rb(p);
				rb_count++;
			}
		}
//		else if (is_skippable(p, p->a_top, range))
//			break ;
		else
		{
			ra(p);
			ra_count++;
		}
	}
	rewind(p, ra_count, rb_count);
	a_to_b_recur(p, p->pivot2, ra_count);
	b_to_a_recur(p, p->pivot2, rb_count);
	b_to_a_recur(p, p->pivot1, pb_count - rb_count);
}
