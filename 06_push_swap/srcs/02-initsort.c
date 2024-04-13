/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-initsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:23:31 by cwan              #+#    #+#             */
/*   Updated: 2024/04/13 17:57:11 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrable(t_stack **b, t_stack *topush)
{
	while (topush != *b)
	{
		if (nodepos(b, topush) < (stacksize(b) / 2))
			rb(b);
		else
			rrb(b);
	}
}

void	initall(t_stack **a, t_stack **b)
{
	t_stack	*topush;
	t_stack	*tgt;

	topush = cheapest(a, b);
	tgt = tgta(a, cheapest(a, b));
	if (topush != *b && tgt != *a)
	{
		while ((nodepos(b, topush) < (stacksize(b) / 2)) && \
		nodepos(a, tgt) < (stacksize(a) / 2))
			rr(a, b);
		while ((nodepos(b, topush) >= (stacksize(b) / 2)) && \
		nodepos(a, tgt) >= (stacksize(a) / 2))
			rrr(a, b);
	}
	while (topush != *b)
		rrable(b, topush);
	while (topush != *a)
	{
		if (tgt == *a)
			pa(a, b);
		else if (nodepos(a, tgt) < (stacksize(a) / 2))
			ra(a);
		else if (nodepos(a, tgt) >= (stacksize(a) / 2))
			rra(a);
	}
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
		if (stacksize(b) == 2 && ((*b)->nu < (*b)->n->nu))
			sb(b);
	init3(a);
	while (*b)
	{
		if (((!stacksorted(a) && \
		((*b)->nu < nodemin(a)->nu || (*b)->nu > nodemax(a)->nu)) || \
		((*b)->nu < (*a)->nu && (*b)->nu > (*a)->p->nu)))
			pa(a, b);
		else if (nodepos(a, tgta(a, *b)) < stacksize(a) / 2)
			ra(a);
		else
			rra(a);
	}
}

int	initsort(t_stack **a, t_stack **b)
{
	if (!a || !*a || !b || !stacksorted(a))
		return (1);
	if (stacksize(a) == 5)
		init5(a, b);
	else
	{
		(void)(pb(a, b), pb(a, b));
		while (stacksize(a) > 3)
			pb(a, b);
		init3(a);
		while (*b)
			initall(a, b);
	}
	while (stacksorted(a))
	{
		if (stacksorted(a) && (nodepos(a, nodemin(a)) <= stacksize(a) / 2))
			ra(a);
		else
			rra(a);
	}
	return (0);
}
