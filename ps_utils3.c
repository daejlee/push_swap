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


void	matching_stack(t_decue_addr *p, unsigned int *idx_chamber)
{
	unsigned int	i;

	i = p->size;
	while (i + 1)
	{
		if (p->a_top->u_val == idx_chamber[i])
		{
			i--;
			pb(p);
		}
		else if (get_stack_idx(p->b_top, idx_chamber[i]) < p->size / 2)
			ra(p);
		else
			rra(p);
	}
	while (p->b_top)
		pa(p);
	p->b_top = NULL;
	p->b_bottom = NULL;
	p->a_bottom = get_bottom_adr(p->a_top);
}
