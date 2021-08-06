#include "push_swap.h"

t_stack	*ft_elem_new(int number, unsigned int index)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr)
	{
		ptr->number = number;
		ptr->index = index;
		ptr->next = NULL;
		return (ptr);
	}
	return (NULL);
}

void	ft_elem_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*ptr;

	ptr = *lst;
	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new;
		}
	}
}