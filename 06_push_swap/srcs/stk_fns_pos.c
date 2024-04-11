/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fns_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:23:30 by cwan              #+#    #+#             */
/*   Updated: 2024/04/10 02:17:22 by cwan42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mintotop(t_stack **a)
{
	while (stacksorted(a))
	{
		if (stacksorted(a) && (nodepos(a, nodemin(a)) <= stacksize(a) / 2))
			ra(a);
		else
			rra(a);
	}
}

int	stacksize(t_stack **a)
{
	t_stack	*ptr;
	int		count;

	ptr = *a;
	count = 1;
	while (ptr->n != *a)
	{
		ptr = ptr->n;
		count++;
	}
	return (count);
}

int	nodepos(t_stack **a, t_stack *node)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
//	LEAVE FOR NORME ERROR, to change to 0 maybe. Now 1 for ez count ref
	i = 1;
	while (tmp->nu != node->nu)
	{
		tmp = tmp->n;
		i++;
	}
	return (i);
}

t_stack	*mediannode(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (i < (stacksize(a) / 2))
	{
		tmp = tmp->n;
		i++;
	}
	return (tmp);
}
