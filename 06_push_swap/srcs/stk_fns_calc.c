//include stdheader

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

int	countsteps(t_stack **a, t_stack **b, t_stack *tmp)
{
	int		steps;

	steps = 0;
	if (nodepos(a, tgtval(a, tmp)) <= (stacksize(a) / 2))
		steps += nodepos(a, tgtval(a, tmp));
	else
		steps += (stacksize(a) - nodepos(a, tgtval(a, tmp)));
	if (nodepos(b, tmp->nu) <= (stacksize(b) / 2))
		steps += nodepos(b, tmp->nu);
	else
		steps += (stacksize(b) + 1 - nodepos(b, tmp->nu));
	return (steps);
}

int	cheapest(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapo;
	int		lowest;

	tmp = *b;
	cheapo = tmp->nu;
	lowest = 99999;
	while (tmp != *b || lowest == 99999)
	{
		if (countsteps(a, b, tmp) < lowest)
		{
			lowest = countsteps(a, b, tmp);
			cheapo = tmp->nu;
		}
		tmp = tmp->n;
	}
	return (cheapo);
}
