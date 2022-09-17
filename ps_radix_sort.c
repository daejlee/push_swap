/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daejlee <daejlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:24:39 by daejlee           #+#    #+#             */
/*   Updated: 2022/09/17 16:24:40 by daejlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./push_swap.h"
#include <stdlib.h>

static unsigned int	get_count(unsigned int *arr, unsigned int div,
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

static void	sort_to_chamber(unsigned int *from_arr, unsigned int *to_arr,
			unsigned int div, t_decue_addr *p)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	pushing_int;
	unsigned int	count;
	int				target;

	pushing_int = 10;
	k = p->size - 1;
	while (pushing_int--)
	{
		count = get_count(from_arr, div, pushing_int, p->size);
		i = p->size - 1;
		while (count)
		{
			target = from_arr[i--];
			if (get_dig(target, div) == pushing_int)
			{
				to_arr[k--] = target;
				count--;
			}
		}
	}
}

static void	cp_stack_to_chamber(unsigned int *arr, t_decue *top)
{
	unsigned int	i;

	i = 0;
	while (top)
	{
		arr[i++] = top->u_val;
		top = top->next;
	}
}

static int	*trim_idx_chamber(unsigned int *temp1, t_decue_addr *p)
{
	unsigned int	i;
	int				*ret;

	i = 0;
	ret = (int *)malloc(sizeof(int) * p->size);
	if (!ret)
		return (NULL);
	if (p->min < 0)
	{
		while (i < p->size)
		{
			ret[i] = temp1[i] + p->min;
			i++;
		}
	}
	else
	{
		while (i < p->size)
		{
			ret[i] = temp1[i];
			i++;
		}
	}
	return (ret);
}

int	*radix_sort(t_decue_addr *p)
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
	return (trim_idx_chamber(temp1, p));
}
