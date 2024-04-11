/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:24:18 by cwan              #+#    #+#             */
/*   Updated: 2024/04/12 01:34:04 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a2b(t_stack **a, t_stack **b)
{
	t_stack	*topush;
	t_stack	*tgt;

	topush = cheapest(b, a);
	tgt = tgtb(b, cheapest(b, a));
	if (topush != *a && tgt != *b)
	{
		while ((nodepos(a, topush) < (stacksize(a) / 2)) && \
		 nodepos(b, tgt) < (stacksize(b) / 2))
			rr(a, b);
		while ((nodepos(a, topush) >= (stacksize(a) / 2)) && \
		nodepos(b, tgt) >= (stacksize(b) / 2))
			rrr(a, b);
	}
	while (topush != *a)
	{
		if (nodepos(a, topush) < (stacksize(a) / 2))
			ra(a);
		else
			rra(a);
	}
	while (topush != *b)
	{
		if (tgt == *b)
			pb(a, b);
		else if (nodepos(b, tgt) < (stacksize(b) / 2))
			rb(b);
		else if (nodepos(b, tgt) >= (stacksize(b) / 2))
			rrb(b);
	}
}

void	b2a(t_stack **a, t_stack **b)
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
	{
		if (nodepos(b, topush) < (stacksize(b) / 2))
			rb(b);
		else
			rrb(b);
	}
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
