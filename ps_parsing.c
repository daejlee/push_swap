#include "./libft_garage/libft/libft.h"
#include <stdlib.h>

void	*free_arg(char **ret)
{
	unsigned int	i;

	i = 0;
	if (!ret)
		return (NULL);
	while (ret[i])
		free (ret[i++]);
	free (ret);
	return (NULL);
}

static unsigned int	get_spaces(char *str)
{
	unsigned int	k;
	unsigned int	j;

	k = 0;
	j = 0;
	while (str[j])
	{
		if (str[j++] == ' ')
			k++;
	}
	return (k);
}

static char	**get_slots(char **argv)
{
	char			**ret;
	unsigned int	i;
	unsigned int	k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		if (!argv[i][0])
			return (NULL);
		else if (ft_strchr(argv[i], ' ' ))
			k += get_spaces(argv[i]);
		else
			k++;
		i++;
	}
	ret = (char **)malloc(sizeof (char *) * (k + 2));
	ret[k + 1] = NULL;
	return (ret);
}

static unsigned int	temp(char **temp, char **ret, unsigned int *k)
{
	unsigned int	j;

	if (!temp)
	{
		free_arg(ret);
		return (0);
	}
	j = 0;
	while (temp[j])
		ret[(*k)++] = temp[j++];
	free (temp);
	return (1);
}

char	**parse_arg(char **argv)
{
	unsigned int	i;
	unsigned int	k;
	char			**ret;

	i = 1;
	k = 0;
	ret = get_slots(argv);
	if (!ret)
		return (NULL);
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!temp(ft_split(argv[i], ' '), ret, &k))
				return (NULL);
		}
		else
			ret[k++] = ft_strdup(argv[i]);
		i++;
	}
	return (ret);
}
