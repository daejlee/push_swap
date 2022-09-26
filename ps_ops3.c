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

int	rra(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->a_bottom || !p->a_bottom->previous)
		return (0);
	p->a_bottom->next = p->a_top;
	if (p->a_bottom->previous)
		p->a_bottom->previous->next = NULL;
	temp = p->a_bottom->previous;
	p->a_bottom->previous = NULL;
	p->a_top->previous = p->a_bottom;
	p->a_top = p->a_bottom;
	p->a_bottom = temp;
	return (ft_printf("rra\n") - 3);
}

int	rrb(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->b_bottom || !p->b_bottom->previous)
		return (0);
	p->b_bottom->next = p->b_top;
	if (p->b_bottom->previous)
		p->b_bottom->previous->next = NULL;
	temp = p->b_bottom->previous;
	p->b_bottom->previous = NULL;
	p->b_top->previous = p->b_bottom;
	p->b_top = p->b_bottom;
	p->b_bottom = temp;
	return (ft_printf("rrb\n") - 3);
}

int	rrr(t_decue_addr *p)
{
	t_decue	*temp;

	if (!p->a_bottom || !p->a_bottom->previous
		|| !p->b_bottom || !p->b_bottom->previous)
		return (0);
	p->a_bottom->next = p->a_top;
	if (p->a_bottom->previous)
		p->a_bottom->previous->next = NULL;
	temp = p->a_bottom->previous;
	p->a_bottom->previous = NULL;
	p->a_top->previous = p->a_bottom;
	p->a_top = p->a_bottom;
	p->a_bottom = temp;
	p->b_bottom->next = p->b_top;
	if (p->b_bottom->previous)
		p->b_bottom->previous->next = NULL;
	temp = p->b_bottom->previous;
	p->b_bottom->previous = NULL;
	p->b_top->previous = p->b_bottom;
	p->b_top = p->b_bottom;
	p->b_bottom = temp;
	return (ft_printf("rrr\n") - 3);
}
