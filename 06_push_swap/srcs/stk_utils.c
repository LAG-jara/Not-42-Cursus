/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:43:01 by cwan              #+#    #+#             */
/*   Updated: 2024/04/13 23:09:34 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countsteps(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		alpha;
	int		bravo;

	alpha = nodepos(a, tgta(a, tmp));
	bravo = nodepos(b, tmp);
	if ((alpha < (stacksize(a) / 2)) && (bravo < (stacksize(b) / 2)))
	{
		if (alpha > bravo)
			return (alpha);
		else
			return (bravo);
	}
	else if ((alpha >= (stacksize(a) / 2)) && (bravo >= (stacksize(b) / 2)))
	{
		if ((stacksize(a) - alpha) > (stacksize(b) - bravo))
			return (stacksize(a) - alpha);
		else
			return (stacksize(b) - bravo);
	}
	else if ((alpha < (stacksize(a) / 2)) && (bravo >= (stacksize(b) / 2)))
		return (alpha + (stacksize(b) - bravo));
	else
		return ((stacksize(a) - alpha) + bravo);
}

t_stack	*cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapo;
	int		lowest;

	tmp = *b;
	cheapo = tmp;
	lowest = 99999;
	while (tmp != *b || lowest == 99999)
	{
		if (countsteps(a, b, tmp) < lowest)
		{
			lowest = countsteps(a, b, tmp);
			cheapo = tmp;
		}
		tmp = tmp->n;
	}
	return (cheapo);
}

long	ft_atol(const char *str)
{
	long	i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] || s2[i])
		return (1);
	return (0);
}

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
