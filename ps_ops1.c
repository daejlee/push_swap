/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:06:00 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:06:02 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include "./libft_garage/ft_printf/ft_printf.h"

static void	swap(t_decue *top)
{
	int		temp;

	if (top && top->next)
	{
		temp = top->val;
		top->val = top->next->val;
		top->next->val = temp;
	}
}

void	sa(t_decue_addr *p)
{
	swap(p->a_top);
	ft_printf("sa\n");
}

void	sb(t_decue_addr *p)
{
	swap(p->b_top);
	ft_printf("sb\n");
}

void	ss(t_decue_addr *p)
{
	sa(p);
	sb(p);
	ft_printf("ss\n");
}
