/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:14 by jrobert           #+#    #+#             */
/*   Updated: 2021/06/28 18:01:16 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_fast_rotate(int size, int pos, t_list **stack, char stk)
{
	if (pos <= size / 2)
		while (pos--)
			_r(stack, stk);
	else
		while (pos++ < size)
			_rr(stack, stk);
}

void 	_lowtop(t_list **stack, char stk)
{
	int		size;
	int		pos;
	t_list	*tmp;

	pos = 1;
	tmp = *stack;
	size = ft_lstsize(*stack);
	while (tmp && tmp->next && tmp->content < tmp->next->content)
	{
		pos++;
		tmp = tmp->next;
	}
	_fast_rotate(size, pos, stack, stk);
}

void 	_maxtop(t_list **stack, char stk)
{
	int		size;
	int		pos;
	int		max;
	t_list	*tmp;

	pos = 0;
	tmp = *stack;
	max = _max(*stack);
	size = ft_lstsize(*stack);
	while (tmp && tmp->content != max)
	{
		pos++;
		tmp = tmp->next;
	}
	_fast_rotate(size, pos, stack, stk);
}

void 	_slot_highttop(t_list **stack, int val, char stk)
{
	int		size;
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = *stack;
	size = ft_lstsize(*stack);
	if (val > _max(tmp) || val < _min(tmp))
	{
		_maxtop(stack, 'b');
		return ;
	}
	while (tmp && tmp->next && val > tmp->content
		&& val > ft_lstlast(tmp)->content)
	{
		pos++;
		tmp = tmp->next;
	}
	while (tmp && tmp->next && val < tmp->content)
	{
		pos++;
		tmp = tmp->next;
	}
	_fast_rotate(size, pos, stack, stk);
}

void 	_slot_lowtop(t_list **stack, int val, char stk)
{
	int		size;
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = *stack;
	size = ft_lstsize(*stack);
	while (tmp && tmp->next && val < tmp->content
		&& val < ft_lstlast(tmp)->content)
	{
		pos++;
		tmp = tmp->next;
	}
	while (tmp && tmp->next && val > tmp->content)
	{
		pos++;
		tmp = tmp->next;
	}
	_fast_rotate(size, pos, stack, stk);
}
