/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:01:52 by jrobert           #+#    #+#             */
/*   Updated: 2021/07/08 10:18:59 by jrobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_sort_medium(int size, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	if (_seq_len(*stack_a) == size - 1)
		return ;
	else if (_seq_len(*stack_a) * 100 / (size - 1) >= 70)
	{
		_sort_few(size, stack_a, stack_b);
		return ;
	}
	while (i++ < size - 3 && !_is_ordered(*stack_a))
		_pb(stack_a, stack_b);
	_sort_three(stack_a);
	while (*stack_b)
	{
		if (((*stack_b)->content < _min(*stack_a))
			|| (*stack_b)->content > _max(*stack_a))
			_lowtop(stack_a, 'a');
		else
			_slot_lowtop(stack_a, (*stack_b)->content, 'a');
		_pa(stack_a, stack_b);
	}
}
