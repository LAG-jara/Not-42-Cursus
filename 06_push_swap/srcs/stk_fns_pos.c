/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_fns_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:23:30 by cwan              #+#    #+#             */
/*   Updated: 2024/04/02 11:19:17 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
