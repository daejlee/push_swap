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

//./push_swap 1 2 7 11 22 927 731 33

/*static void	swap_b_with_a(t_decue_addr *p)
{
	t_decue	*temp1;

	temp1 = p->a_top;
	p->a_top = p->b_top;
	p->b_top = temp1;
	temp1 = p->a_bottom;
	p->a_bottom = p->b_bottom;
	p->b_bottom = temp1;
}*/

void	print_stack(t_decue_addr *p)
{
	t_decue	*head;

	ft_printf("-------------------------------\n");
	ft_printf("signed val is following.....\n");
	ft_printf("-------------------------------\n");
	head = p->a_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\na\n");
	head = p->b_top;
	while (head)
	{
		ft_printf("%d\n", head->val);
		head = head->next;
	}
	ft_printf("-\nb\n");
	ft_printf("-------------------------------\n");
	ft_printf("unsigned val is following.....\n");
	ft_printf("-------------------------------\n");
	head = p->a_top;
	while (head)
	{
		ft_printf("%u\n", head->u_val);
		head = head->next;
	}
	ft_printf("-\na\n");
	head = p->b_top;
	while (head)
	{
		ft_printf("%u\n", head->u_val);
		head = head->next;
	}
	ft_printf("-\nb\n");
}

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

unsigned int	get_count(unsigned int *arr, unsigned int div,
		unsigned int pushing_int, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;
	unsigned int	target_dig;

	count = 0;
	i = 0;
	while (i < size)
	{
		target_dig = get_dig(arr[i], div);
		if (target_dig == pushing_int)
			count++;
		i++;
	}
	return (count);
}

void	sort_to_chamber(unsigned int *from_arr, unsigned int *to_arr, unsigned int div, t_decue_addr *p)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	pushing_int;
	unsigned int	target_dig;
	unsigned int	count;
	int				target;

	pushing_int = 10;
	k = 0;
	while (pushing_int--)
	{
		count = get_count(from_arr, div, pushing_int, p->size);
		i = 0;
		while (count)
		{
			target = from_arr[i++];
			target_dig = get_dig(target, div);
			if (target_dig == pushing_int)
			{
				to_arr[k++] = target;
				count--;
			}
		}
	}
}

void	cp_stack_to_chamber(unsigned int *arr, t_decue *top)
{
	unsigned int	i;

	i = 0;
	while (top)
	{
		arr[i++] = top->u_val;
		top = top->next;
	}
}

unsigned int	*radix_sort(t_decue_addr *p)
{
	unsigned int	div;
	unsigned int	*temp1;
	unsigned int	*temp2;
	unsigned int	*temp_switch;

	div = 1;
	temp1 = (unsigned int *)malloc(sizeof(unsigned int) * p->size);
	temp2 = (unsigned int *)malloc(sizeof(unsigned int) * p->size);
	if (!temp1 || !temp2)
		return (NULL);
	cp_stack_to_chamber(temp1, p->a_top);
	while (p->u_max / div)
	{
		sort_to_chamber(temp1, temp2, div, p);
		div *= 10;
		temp_switch = temp1;
		temp1 = temp2;
		temp2 = temp_switch;
	}
	free (temp2);
	temp2 = NULL;
	return (temp1);
}

int	main(int argc, char **argv)
{
	t_decue_addr	*p;
	char			**arg_arr;
	unsigned int	*idx_chamber;

	if (argc == 1)
		return (1);
	else if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else
		arg_arr = argv + 1;
	if (is_int(arg_arr) || is_there_dup(arg_arr))
		return (print_err());
	p = init_p();
	p->size = push_args_to_a(arg_arr, p);
	if (!p->size)
		return (1);
	else if (check_already_sorted(p->a_top))
		return (purge_lst(p));
	idx_chamber = radix_sort(p);
	if (!idx_chamber)
		return (purge_lst(p));
	if (p->size < 7)
		low_arg_sort(p);
	else
		matching_stack(p, idx_chamber);
	//print_stack(p);
	return (purge_lst(p));
}
