/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:07:12 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/09 15:07:13 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

unsigned int	get_dig(unsigned int val, unsigned int div)
{
	if (div == 1)
		return (val % 10);
	else
	{
		div *= 10;
		val %= div;
		div /= 10;
		return (val /= div);
	}
}

t_decue_addr	*prep_sort(char **arg_arr)
{
	t_decue_addr	*ret;

	ret = init_p();
	if (!ret)
		return (NULL);
	ret->size = push_args_to_a(arg_arr, ret);
	if (!ret->size)
		return (NULL);
	else if (check_already_sorted(ret->a_top))
	{
		purge_lst(ret);
		return (NULL);
	}
	ret->idx_chamber = radix_sort(ret);
	if (!ret->idx_chamber)
	{
		purge_lst(ret);
		return (NULL);
	}
	return (ret);
}

void	ignite_recur(t_decue_addr *p)
{
	unsigned int	temp;

	a_to_b_recur(p, p->idx_chamber[p->size / 2], p->size);
	temp = p->size;
	while (temp--)
		pb(p);
	while (p->size--)
	{
		ra(p);
		pa(p);
	}
	ra(p);
}

int	main(int argc, char **argv)
{
	t_decue_addr	*p;
	char			**arg_arr;

	if (argc == 1)
		return (1);
	else if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else
		arg_arr = argv + 1;
	if (is_int(arg_arr) || is_there_dup(arg_arr))
		return (print_err());
	p = prep_sort(arg_arr);
	if (p->size < 6)
		low_arg_sort(p);
	else
		ignite_recur(p);
	return (purge_lst(p));
}
