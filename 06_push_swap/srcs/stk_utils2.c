/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan42 <cwan42@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 06:42:52 by cwan42            #+#    #+#             */
/*   Updated: 2024/04/02 10:45:26 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexb2a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	if ((*b)->nu > nodemax(a)->nu || (*b)->nu < nodemin(a)->nu)
		return (0);
	while ((*b)->nu > tmp->nu)
	{
		if ((*b)->nu > tmp->p->nu && (*b)->nu < tmp->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	while ((*b)->nu < tmp->nu)
	{
		if ((*b)->nu < tmp->nu && (*b)->nu > tmp->p->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (i);
}

int	indexa2b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	tmp = *b;
	i = 0;
	if ((*a)->nu > nodemax(b)->nu || (*a)->nu < nodemin(b)->nu)
		return (0);
	while ((*a)->nu < tmp->nu)
	{
		if ((*a)->nu < tmp->p->nu && (*a)->nu > tmp->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	while ((*a)->nu > tmp->nu)
	{
		if ((*a)->nu > tmp->nu && (*a)->nu < tmp->p->nu)
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (i);
}

int	stepsreq(int pos, t_stack **a)
{
	int	halfsize;

	halfsize = stacksize(a) / 2;
	if (pos <= halfsize)
		return (pos);
	else
		return (pos - halfsize);
}
