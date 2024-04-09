/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fns_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:19:59 by cwan              #+#    #+#             */
/*   Updated: 2024/04/10 02:06:02 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countsteps(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		steps;
	steps = 0;
	if (nodepos(a, tgta(a, tmp)) <= (stacksize(a) / 2))
		steps += nodepos(a, tgta(a, tmp));
	else
		steps += (stacksize(a) - nodepos(a, tgta(a, tmp)));
	if (nodepos(b, tmp) <= (stacksize(b) / 2))
		steps += nodepos(b, tmp);
	else
		steps += (stacksize(b) + 1 - nodepos(b, tmp));
	return (steps);
}

int	countstepsb2a(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		steps;
	steps = 0;
	if (nodepos(b, tgtb(b, tmp)) <= (stacksize(b) / 2))
		steps += nodepos(b, tgtb(b, tmp));
	else
		steps += (stacksize(b) - nodepos(b, tgtb(b, tmp)));
	if (nodepos(a, tmp) <= (stacksize(a) / 2))
		steps += nodepos(a, tmp);
	else
		steps += (stacksize(a) + 1 - nodepos(a, tmp));
	return (steps);
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

t_stack	*cheapestb2a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*cheapo;
	int		lowest;

	tmp = *b;
	cheapo = tmp;
	lowest = 99999;
	while (tmp != *b || lowest == 99999)
	{
		if (countstepsb2a(a, b, tmp) < lowest)
		{
			lowest = countstepsb2a(a, b, tmp);
			cheapo = tmp;
		}
		tmp = tmp->n;
	}
	return (cheapo);
}
