/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:08 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:06:09 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft_garage/ft_printf/ft_printf.h"

int	pa(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->b_top)
		return (1);
	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	if (p->a_top)
	{
		p->a_top->previous = p->b_top;
		temp = p->b_top->next;
		p->b_top->next = p->a_top;
		p->a_top = p->b_top;
		p->b_top = temp;
		if (!temp)
			p->b_bottom = temp;
	}
	else
	{
		p->a_top = p->b_top;
		p->a_bottom = p->b_top;
		temp = p->b_top->next;
		p->a_top->next = NULL;
		p->b_top = temp;
	}
	return (ft_printf("pa\n") - 2);
}

int	pb(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->a_top)
		return (1);
	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	if (p->b_top)
	{
		p->b_top->previous = p->a_top;
		temp = p->a_top->next;
		p->a_top->next = p->b_top;
		p->b_top = p->a_top;
		p->a_top = temp;
		if (!temp)
			p->a_bottom = temp;
	}
	else
	{
		p->b_top = p->a_top;
		p->b_bottom = p->a_top;
		temp = p->a_top->next;
		p->b_top->next = NULL;
		p->a_top = temp;
	}
	return (ft_printf("pb\n") - 2);
}

int	ra(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->a_top || !p->a_top->next)
		return (1);
	p->a_top->previous = p->a_bottom;
	p->a_bottom->next = p->a_top;
	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	temp = p->a_top->next;
	p->a_top->next = NULL;
	p->a_top = temp;
	p->a_bottom = p->a_bottom->next;
	return (ft_printf("ra\n") - 2);
}

int	rb(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->b_top || !p->b_top->next)
		return (1);
	p->b_top->previous = p->b_bottom;
	p->b_bottom->next = p->b_top;
	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	temp = p->b_top->next;
	p->b_top->next = NULL;
	p->b_top = temp;
	p->b_bottom = p->b_bottom->next;
	return (ft_printf("rb\n") - 2);
}

int	rr(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->a_top || !p->a_top->next || !p->b_top || !p->b_top->next)
		return (1);
	p->a_top->previous = p->a_bottom;
	p->a_bottom->next = p->a_top;
	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	temp = p->a_top->next;
	p->a_top->next = NULL;
	p->a_top = temp;
	p->a_bottom = p->a_bottom->next;
	p->b_top->previous = p->b_bottom;
	p->b_bottom->next = p->b_top;
	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	temp = p->b_top->next;
	p->b_top->next = NULL;
	p->b_top = temp;
	p->b_bottom = p->b_bottom->next;
	return (ft_printf("rr\n") - 2);
}
