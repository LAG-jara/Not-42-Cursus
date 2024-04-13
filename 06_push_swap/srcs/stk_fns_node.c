/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fns_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 06:47:38 by cwan              #+#    #+#             */
/*   Updated: 2024/04/13 18:42:26 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*nodemax(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *a;
	max = (*a)->p;
	while (tmp->n != *a)
	{
		if (tmp->nu > max->nu)
			max = tmp;
		tmp = tmp->n;
	}
	return (max);
}

t_stack	*nodemin(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *a;
	min = (*a)->p;
	while (tmp->n != *a)
	{
		if (tmp->nu < min->nu)
			min = tmp;
		tmp = tmp->n;
	}
	return (min);
}

t_stack	*tgta(t_stack **a, t_stack *b)
{
	t_stack	*tmp;
	t_stack	*tgt;

	tmp = *a;
	tgt = (*a)->p;
	if (b->nu > nodemax(a)->nu || b->nu < nodemin(a)->nu)
		return (nodemin(a));
	while (tmp->n != *a)
	{
		if (b->nu < tmp->nu && b->nu > tmp->p->nu)
			tgt = tmp;
		tmp = tmp->n;
	}
	return (tgt);
}

int	nodepos(t_stack **a, t_stack *node)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp->nu != node->nu)
	{
		tmp = tmp->n;
		i++;
	}
	return (i);
}

int	stacksorted(t_stack	**a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->n != *a)
	{
		if (tmp->nu > tmp->n->nu)
			return (1);
		tmp = tmp->n;
	}
	return (0);
}
