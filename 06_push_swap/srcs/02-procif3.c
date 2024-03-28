/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-procif3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/03/28 15:23:24 by cwan             ###   ########.fr       */
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
	if (!a || !*a)
		return ;
	if ((*a)->nu < (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		return ;
	if ((*a)->nu < (*a)->n->nu && (*a)->nu < (*a)->p->nu)
		(void)(sa(a),ra(a));
	else if ((*a)->nu > (*a)->n->nu && (*a)->nu < (*a)->p->nu)
		sa(a);
	else if ((*a)->nu < (*a)->n->nu && (*a)->nu > (*a)->p->nu)
		rra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu < (*a)->p->nu)
		ra(a);
	else if ((*a)->nu > (*a)->n->nu && (*a)->n->nu > (*a)->p->nu)
		(void)(sa(a),rra(a));
}
/*	init3 shorter ver
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
}*/

//presort fn to do light sorting for b so is cheaper later, if cur *a can be sorted within size /2 moves, do it.
void	presortb(t_stack **a, t_stack **b)
{
	while (!*b || stacksize(b) < 2)
		pb(a, b);
//	ft_printf("tgtval %d\n", tgtval(b, *a));
	if (((*a)->nu > numax(b) && (*b)->nu == numax(b)) || \
	((*b)->p->nu == tgtval(b, *a)))
		pb(a, b);
	else if (nodepos(b, tgtval(b, *a)) < stacksize(b))
		rb(b);
	else
		rrb(b);
//	printloops(a, b);
}

void	init5(t_stack **a, t_stack **b)
{
	while (stacksize(a) > 3)
		presortb(a, b);
	init3(a);
//	if (stacksortedrev(b))
//		sb(b);
	while (*b)
	{
//	printloops(a, b);
//	ft_printf("Target is %d, nodepos is %d, cheapest is %d\n", tgtval(a, *b), nodepos(a, tgtval(a, *b)), cheapest(a, b));
		while (stepsreq(indexb2a(a, b), a) > 0)
			ra(a);
		while (stepsreq(indexb2a(a, b), a) < 0)
			rra(a);
		if (!stepsreq(indexb2a(a, b), a) && ((!stacksorted(a) && \
		((*b)->nu < numin(a) || (*b)->nu > numax(a))) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if ((*b)->nu > mediannode(a)->nu)
			ra(a);
		else
			rra(a);
	}
//	printloops(a, b);
	while (stacksorted(a) && (*a)->nu > numin(a))
		rra(a);
//	printloops(a, b);
}

int	initpri(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !stacksorted(a))
		return (1);
	if (stacksize(a) < 6)
		init5(a, b);
	else
		init5(a, b);
	return (0);
}
