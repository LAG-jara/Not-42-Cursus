//incl stdheader

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

int	nodepos(t_stack **a, int val)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 1;
	while (tmp->nu != val)
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
