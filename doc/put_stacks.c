#include "push_swap.h"
#include <stdio.h>

void	_put_stacks(t_list *stack_a, t_list *stack_b)
{
	int size_a;
	int size_b;
	int size_ab;
	
	size_a = ft_lstsize(stack_a);
	size_b = ft_lstsize(stack_b);
	size_ab = size_a;
	if (size_b > size_a)
		size_ab = size_b;
	printf("\n\n");
	while (size_ab)
	{
		if (stack_a && size_a == size_ab)
		{
			size_a--;
			printf("[%11d]", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			printf("             ");
		if (stack_b && size_b == size_ab)
		{
			size_b--;
			printf(" [%11d]", stack_b->content);
			stack_b = stack_b->next;
		}
		printf("\n");
		size_ab--;
	}
	printf("------------- -------------\n");
	printf("   STACK A       STACK B   \n");
	printf("\n");
}