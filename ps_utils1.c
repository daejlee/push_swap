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
	ft_printf ("stack already sorted. terminating...\n");
	return (1);
}

t_decue_addr	*init_p(void)
{
	t_decue_addr	*ret;

	ret = (t_decue_addr *)malloc(sizeof(t_decue_addr));
	if (!ret)
		return (NULL);
	ret->a_top = NULL;
	ret->a_bottom = NULL;
	ret->b_top = NULL;
	ret->b_bottom = NULL;
	ret->size = 0;
	return (ret);
}

unsigned int	push_args_to_a(char **argv, t_decue_addr *p)
{
	unsigned int	i;
	t_decue			*temp1;
	t_decue			*temp2;

	temp1 = (t_decue *)malloc(sizeof(t_decue));
	if (!temp1)
		return (0);
	temp1->previous = NULL;
	temp1->val = ft_atoi(argv[1]);
	p->max = temp1->val;
	p->a_top = temp1;
	i = 2;
	while (argv[i])
	{
		temp2 = (t_decue *)malloc(sizeof(t_decue));
		if (!temp2)
			return (purge_lst(p));
		temp1->next = temp2;
		temp2->previous = temp1;
		temp2->val = ft_atoi(argv[i]);
		if (p->max < temp2->val)
			p->max = temp2->val;
		temp1 = temp2;
		i++;
	}
	temp1->next = NULL;
	p->a_bottom = temp1;
	i--;
	return (i);
}
