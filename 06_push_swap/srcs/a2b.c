/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:24:18 by cwan              #+#    #+#             */
/*   Updated: 2024/04/04 13:43:29 by cwan42           ###   ########.fr       */
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
		while ((nodepos(a, topush) <= (stacksize(a) / 2)) && \
		 nodepos(b, tgt) <= (stacksize(b) / 2))
			rr(a, b);
		while ((nodepos(a, topush) > (stacksize(a) / 2)) && \
		nodepos(b, tgt) > (stacksize(b) / 2))
			rrr(a, b);
	}
	while (topush != *a)
	{
		if (nodepos(a, topush) <= (stacksize(a) / 2))
			ra(a);
		else
			rra(a);
	}
	while (topush != *b)
	{
		if (tgt == *b)
			pb(a, b);
		else if (nodepos(b, tgt) <= (stacksize(b) / 2))
			rb(b);
		else if (nodepos(b, tgt) > (stacksize(b) / 2))
			rrb(b);
	}
}
