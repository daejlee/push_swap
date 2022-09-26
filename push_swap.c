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

int	main(int argc, char **argv)
{
	t_decue_addr	*p;
	char			**arg_arr;

	if (argc == 1)
		return (1);
	arg_arr = parse_arg(argv);
	if (!arg_arr || is_int(arg_arr) || is_there_dup(arg_arr))
		return (print_err());
	p = prep_sort(arg_arr);
	if (!p)
		return (1);
	if (p->size < 6)
		low_arg_sort(p);
	else
		a_to_b_recur(p, p->idx_chamber[0], p->size);
	return (purge_lst(p));
}
