/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:28 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:06:29 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <stdlib.h>
#include "./libft_garage/ft_printf/ft_printf.h"

void	rra(t_decue_addr *p)
{
	t_decue	*temp;

	p->a_bottom->next = p->a_top;
	if (p->a_bottom->previous)
		p->a_bottom->previous->next = NULL;
	temp = p->a_bottom->previous;
	p->a_bottom->previous = NULL;
	p->a_top->previous = p->a_bottom;
	p->a_top = p->a_bottom;
	p->a_bottom = temp;
	ft_printf("rra\n");
}

void	rrb(t_decue_addr *p)
{
	t_decue	*temp;

	p->b_bottom->next = p->b_top;
	if (p->b_bottom->previous)
		p->b_bottom->previous->next = NULL;
	temp = p->b_bottom->previous;
	p->b_bottom->previous = NULL;
	p->b_top->previous = p->b_bottom;
	p->b_top = p->b_bottom;
	p->b_bottom = temp;
	ft_printf("rrb\n");
}

void	rrr(t_decue_addr *p)
{
	rra(p);
	rrb(p);
}
