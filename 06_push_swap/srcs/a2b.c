/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:24:18 by cwan              #+#    #+#             */
/*   Updated: 2024/04/02 15:34:23 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a2b(t_stack **a, t_stack **b)
{
	t_stack	*tgt;

	tgt = tgtb(b, cheapest(b, a));
	if (tgt == *b)
		pb(a, b);
	else if (tgt->nu >= mediannode(b)->nu)
		rb(b);
	else
		rrb(b);
/*	else if (nodepos(b, tgt) <= (stacksize(b) / 2))
		rb(b);
	else if (nodepos(b, tgt) > (stacksize(b) / 2))
		rrb(b);
	else
		pb(a, b);*/
	printloops(a, b);
	ft_printf("Tgt is %d, Nodeposb is %d\n",tgt->nu, nodepos(b, tgt));
}
