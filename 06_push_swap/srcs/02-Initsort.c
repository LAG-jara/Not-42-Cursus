/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-Initsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/04/02 15:40:04 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrable(t_stack **a, t_stack **b)
{
	int	alpha;
	int	bravo;

	alpha = tgta(a, cheapest(a, b))->nu;
	bravo = cheapest(a, b)->nu;

	if ((alpha != (*a)->nu && alpha < mediannode(a)->nu) && \
	(bravo != (*b)->nu && bravo > mediannode(b)->nu))
		return(rr(a, b), 1);
	if ((alpha != (*a)->nu && alpha > mediannode(a)->nu) && \
	(bravo != (*b)->nu && bravo < mediannode(b)->nu))
		return(rrr(a, b), -1);
	return (0);
}

void	init3(t_stack **a)
{
	if (stacksize(a) < 3 && (*a)->nu > (*a)->n->nu)
		sa(a);
	else if (stacksize(a) == 3)
	{
		if ((*a)->nu == nodemax(a)->nu)
			ra(a);
		else if ((*a)->n->nu == nodemax(a)->nu)
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
		((*b)->nu < nodemin(a)->nu || (*b)->nu > nodemax(a)->nu)) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if (nodepos(a, tgta(a, *b)) < stacksize(a) / 2)
			ra(a);
		else
			rra(a);
	}
	while (stacksorted(a) && (*a)->nu > nodemin(a)->nu)
		rra(a);
}

void	initall(t_stack **a, t_stack **b)
{
	if (stacksize(a) > 4)
		(void)(pb(a, b), pb(a, b));
	while (stacksize(a) > 3)
//		a2b(a, b);
		pb(a, b);
	init3(a);
	while (*b)
	{
		if (!stepsreq(indexb2a(a, b), a) && ((!stacksorted(a) && \
		((*b)->nu < nodemin(a)->nu || (*b)->nu > nodemax(a)->nu)) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if (nodepos(a, tgta(a, *b)) < stacksize(a) / 2)
			ra(a);
		else
			rra(a);
	}
	while (stacksorted(a) && (*a)->nu > nodemin(a)->nu)
		rra(a);
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
