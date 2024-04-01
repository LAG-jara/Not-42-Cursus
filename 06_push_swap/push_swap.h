/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:49:51 by cwan              #+#    #+#             */
/*   Updated: 2024/03/28 11:17:17 by cwan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nu;
	struct s_stack	*n;
	struct s_stack	*p;
}					t_stack;

//stk_fns.c
t_stack	*ft_stklast(t_stack *lst);
t_stack	*ft_stknew(int value);
void	ft_stkadd_back(t_stack **lst, t_stack *node);
void	ft_freestack(t_stack **lst);

//stk_fns_calc.c
int		tgtval(t_stack **a, t_stack *b);
int		countsteps(t_stack **a, t_stack **b, t_stack *tmp);
int		cheapest(t_stack **a, t_stack **b);

//stk_fns_pos.c
int		stacksize(t_stack **a);
int		nodepos(t_stack **a, int val);
t_stack	*mediannode(t_stack **a);

//stk_utils.c
int		numax(t_stack **a);
int		numin(t_stack **a);
int		stacksorted(t_stack **a);
int		stacksortedrev(t_stack **a);

int		indexb2a(t_stack **a, t_stack **b);
int		indexa2b(t_stack **a, t_stack **b);
int		stepsreq(int pos, t_stack **a);

//ops_push, swap, rotate, rrotate
void	pa(t_stack **heada, t_stack **headb);
void	pb(t_stack **heada, t_stack **headb);
void	sa(t_stack **heada);
void	sb(t_stack **headb);
void	ss(t_stack **heada, t_stack **headb);
void	ra(t_stack **heada);
void	rb(t_stack **headb);
void	rr(t_stack **heada, t_stack **headb);
void	rra(t_stack **heada);
void	rrb(t_stack **headb);
void	rrr(t_stack **heada, t_stack **headb);

//utils.c
long	ft_atol(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **arr);

//01_inputvalidatn.c
int		procargv(char **av, t_stack **stacka);

int		initpri(t_stack **a, t_stack **b);

//temp
void	printloops(t_stack **lista, t_stack **listb);

#endif
