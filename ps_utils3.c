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

/*

void	prep_idx(t_decue_addr *p, t_decue *bot, unsigned int div)
{
	unsigned int	i;
	unsigned int	pushing_int;
	unsigned int	target_dig;
	unsigned int	count;
	t_decue			*temp;

	i = 0;
	pushing_int = 10;
	while (pushing_int--)
	{
		temp = bot;
		count = get_count(bot, div, pushing_int, p->size);
		while (count)
		{
			target_dig = get_dig(temp->u_val, div);
			if (target_dig == pushing_int)
			{
				p->idx_chamber[i++] = temp->val;
				count--;
			}
			if (temp->previous)
				temp = temp->previous;
		}
	}
}


void	sort_loop_to_b(t_decue_addr *p, unsigned int div)
{
	unsigned int	i;

	prep_idx(p, p->a_bottom, div);
	i = 0;
	while (i < p->size)
	{
		if (p->a_top->val == p->idx_chamber[i])
		{
			i++;
			pb(p);
		}
		else if (get_stack_idx(p->a_top, p->idx_chamber[i]) < p->size / 2)
			ra(p);
		else
			rra(p);
	}
	p->a_top = NULL;
	p->a_bottom = NULL;
	p->b_bottom = get_bottom_adr(p->b_top);
}

void	sort_loop_to_a(t_decue_addr *p, unsigned int div)
{
	unsigned int	i;

	prep_idx(p, p->b_bottom, div);
	i = 0;
	while (i < p->size)
	{
		if (p->b_top->val == p->idx_chamber[i])
		{
			i++;
			pa(p);
		}
		else if (get_stack_idx(p->b_top, p->idx_chamber[i]) < p->size / 2)
			rb(p);
		else
			rrb(p);
	}
	p->b_top = NULL;
	p->b_bottom = NULL;
	p->a_bottom = get_bottom_adr(p->a_top);
}
*/

t_decue	*get_bottom_adr(t_decue *top)
{
	while (top->next)
		top = top->next;
	return (top);
}

unsigned int	get_stack_idx(t_decue *top, int chamber_val)
{
	unsigned int	idx;

	idx = 0;
	while (top)
	{
		if (top->val == chamber_val)
			return (idx);
		idx++;
		top = top->next;
	}
	return (0);
}

int	get_current_min(t_decue *top)
{
	int	min;

	min = top->val;
	while (top->next)
	{
		top = top->next;
		if (top->val < min)
			min = top->val;
	}
	return (min);
}

int	get_current_max(t_decue *top)
{
	int	max;

	max = top->val;
	while (top->next)
	{
		top = top->next;
		if (top->val > max)
			max = top->val;
	}
	return (max);
}

void	sort_A_to_B(int pivot, t_decue_addr *p)
{
	// if (stack_size < 6)
	// 	low_arg_sort(p);
		while (get_current_max(p->a_top) > pivot)
		{
			if (p->a_top->val > pivot)
				pb(p);
			else
				ra(p);
		}
}

/* void	sort_B_to_A(int pivot, t_decue_addr *p)
{

	 if (stack_size < 5)
	 	low_arg_sort(p);
		while (get_current_max(p->b_top) > pivot)
		{
			if (p->b_top->val > pivot)
				pa(p);
			else
				rb(p);
		}
}*/

unsigned int	get_stack_size(t_decue *top)
{
	unsigned int	ret;

	ret = 0;
	while (top)
	{
		ret++;
		top = top->next;
	}
	return (ret);
}

void	divide_three(t_decue_addr *p, int pivot_1, int pivot_2)
{
	while (get_current_max(p->a_top) > pivot_2)
	{
		if (p->a_top->val > pivot_2)
			pb(p);
		else
			ra(p);
	}
	while (get_current_max(p->a_top) > pivot_1)
	{
		if (p->a_top->val > pivot_1)
			pb(p);
		else
			ra(p);
	}
	while (get_stack_size(p->a_top) > 2)
		pb(p);
}

void	get_pivot(int *pivot_1_adr, int *pivot_2_adr, t_decue *head)
{
	//something;
}

void	matching_stack_recursive(t_decue_addr *p, t_decue *head)
{
	unsigned int	i;
	int				pivot_1;
	int				pivot_2;

	get_pivot(&pivot_1, &pivot_2, head);
	divide_three(p, pivot_1, pivot_2);
	if (get_stack_size(head) > 3)
			matching_stack_recursive(p, p->a_top);
	else
		low_arg_sort(head);
}
