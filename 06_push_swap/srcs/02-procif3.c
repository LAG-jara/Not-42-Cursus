/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/30 14:26:12 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tgtval(t_stack **a, t_stack *b)
{
	t_stack	*tmp;
	int		low;

	low = numax(a);
	tmp = *a;
	if ((b->nu > numax(a) || b->nu < numin(a)))
		return (numin(a));
	while (tmp->n != *a)
	{
		if (tmp->nu < low && b->nu < tmp->nu)
			low = tmp->nu;
		tmp = tmp->n;
	}
	if (tmp->nu < low && b->nu < tmp->nu)
		low = tmp->nu;
	return (low);
}

int	nodepos(t_stack **a, int val)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 1;
	while (tmp->nu != val)
	{
		tmp = tmp->n;
		i++;
	}
	return (i);
}

int	cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapo;
	int		lowest;
	int		steps;
	int		i;

	tmp = *b;
	cheapo = tmp->nu;
	lowest = 99999;
	i = 0;
	while (i < stacksize(b))
	{
		steps = 0;
		if (nodepos(a, tgtval(a, tmp)) <= (stacksize(a) / 2))
			steps += nodepos(a, tgtval(a, tmp));
		else
			steps += (stacksize(a) - nodepos(a, tgtval(a, tmp)));
		if (nodepos(b, tmp->nu) <= (stacksize(b) / 2))
			steps += nodepos(b, tmp->nu);
		else
			steps += (stacksize(b) + 1 - nodepos(b, tmp->nu));
		if (steps < lowest)
		{
			lowest = steps;
			cheapo = tmp->nu;
		}
		tmp = tmp->n;
		i++;
	}
	return (cheapo);
}

void	init3(t_stack **a)
{
	if (stacksize(a) < 3 && (*a)->nu > (*a)->n->nu)
		sa(a);
	else if (stacksize(a) == 3)
	{
		if ((*a)->nu == numax(a))
			ra(a);
		else if ((*a)->n->nu == numax(a))
			rra(a);
		if ((*a)->nu > (*a)->n->nu)
			sa(a);
	}
}

void	init5(t_stack **a, t_stack **b)
{
	while (stacksize(a) > 3)
		pb(a, b);
	if (*b)
		if (stacksize(b) == 2 && stacksortedrev(b))
			sb(b);
	init3(a);
	while (*b)
	{
		if (!stepsreq(indexb2a(a, b), a) && ((!stacksorted(a) && \
		((*b)->nu < numin(a) || (*b)->nu > numax(a))) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if (nodepos(a, tgtval(a, *b)) < stacksize(a) / 2)
			ra(a);
		else
			rra(a);
	}
	while (stacksorted(a) && (*a)->nu > numin(a))
		rra(a);
}

void	initall(t_stack **a, t_stack **b)
{
	while (stacksize(a) > 3)
		pb(a, b);
	init3(a);
	init5(a, b);
//	ft_printf("Target is %d, nodepos is %d, cheapest is %d\n", tgtval(a, *b), nodepos(a, tgtval(a, *b)), cheapest(a, b));
}

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !stacksorted(a))
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	else
		initall(a, b);
	return (0);
}
