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

void	pa(t_decue_addr *p)
{
	t_decue	*temp;

	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	if (p->a_top)
	{
		p->a_top->previous = p->b_top;
		temp = p->b_top->next;
		p->b_top->next = p->a_top;
		p->a_top = p->b_top;
		p->b_top = temp;
	}
	else
	{
		p->a_top = p->b_top;
		temp = p->b_top->next;
		p->a_top->next = NULL;
		p->b_top = temp;
	}
	ft_printf("pa\n");
}

void	pb(t_decue_addr *p)
{
	t_decue	*temp;

	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	if (p->b_top)
	{
		p->b_top->previous = p->a_top;
		temp = p->a_top->next;
		p->a_top->next = p->b_top;
		p->b_top = p->a_top;
		p->a_top = temp;
	}
	else
	{
		p->b_top = p->a_top;
		temp = p->a_top->next;
		p->b_top->next = NULL;
		p->a_top = temp;
	}
	ft_printf("pb\n");
}

void	ra(t_decue_addr *p)
{
	t_decue	*temp;

	p->a_top->previous = p->a_bottom;
	p->a_bottom->next = p->a_top;
	if (p->a_top->next)
		p->a_top->next->previous = NULL;
	temp = p->a_top->next;
	p->a_top->next = NULL;
	p->a_top = temp;
	p->a_bottom = p->a_bottom->next;
	ft_printf("ra\n");
}

void	rb(t_decue_addr *p)
{
	t_decue	*temp;

	p->b_top->previous = p->b_bottom;
	p->b_bottom->next = p->b_top;
	if (p->b_top->next)
		p->b_top->next->previous = NULL;
	temp = p->b_top->next;
	p->b_top->next = NULL;
	p->b_top = temp;
	p->b_bottom = p->b_bottom->next;
	ft_printf("rb\n");
}

void	rr(t_decue_addr *p)
{
	ra(p);
	rb(p);
}
