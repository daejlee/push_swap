#include "push_swap.h"
#include "./libft_garage/libft/libft.h"
#include "./libft_garage/ft_printf/ft_printf.h"
#include <stdlib.h>

int	is_int(char **argv)
{
	unsigned int	i;
	char			*temp;

	i = 1;
	while (argv[i])
	{
		temp = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(temp, argv[i], ft_strlen(argv[i])))
		{
			free (temp);
			return (1);
		}
		i++;
		free (temp);
	}
	return (0);
}

int	is_there_dup(char **argv)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strlen(argv[i]) == ft_strlen(argv[j])
				&& !ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_already_sorted(t_decue *head)
{
	while (head && head->next)
	{
		if (head->val > head->next->val)
			return (0);
		else
			head = head->next;
	}
	ft_printf ("\n");
	return (1);
}

static t_decue	*get_a_top(t_decue_addr *p, char *arg)
{
	t_decue	*top;

	top = (t_decue *)malloc(sizeof(t_decue));
	if (!top)
		return (NULL);
	top->previous = NULL;
	top->val = ft_atoi(arg);
	p->a_top = top;
	return (top);
}

void	get_min_max(t_decue_addr *p)
{
	t_decue	*target;

	target = p->a_top;
	p->u_max = p->a_top->val;
	p->min = p->a_top->val;
	while (target->next)
	{
		if (target->next->val > p->u_max)
			p->u_max = target->next->val;
		else if (target->next->val < p->min)
			p->min = target->next->val;
		target = target->next;
	}
	if (p->min < 0)
		p->u_max = p->u_max - p->min;
}

void	set_u_val(t_decue_addr *p)
{
	t_decue	*target;

	target = p->a_top;
	while (target)
	{
		if (p->min < 0)
			target->u_val = target->val - p->min;
		else
			target->u_val = target->val;
		target = target->next;
	}
}

unsigned int	push_args_to_a(char **argv, t_decue_addr *p)
{
	unsigned int	i;
	t_decue			*temp1;
	t_decue			*temp2;

	temp1 = get_a_top(p, argv[1]);
	if (!temp1)
		return (0);
	i = 2;
	while (argv[i])
	{
		temp2 = (t_decue *)malloc(sizeof(t_decue));
		if (!temp2)
			return (purge_lst(p));
		temp1->next = temp2;
		temp2->previous = temp1;
		temp2->val = ft_atoi(argv[i]);
		temp1 = temp2;
		i++;
	}
	temp1->next = NULL;
	p->a_bottom = temp1;
	get_min_max(p);
	set_u_val(p);
	return (--i);
}
