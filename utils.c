#include "push_swap.h"

t_stack	*delete_head(t_stack *root)
{
	t_stack		*temp;

	temp = root->next;
	free(root);
	return (temp);
}

t_stack	*ft_item_new(int number, unsigned int index)
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

void	ft_item_add_back(t_stack **lst, t_stack *new)
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

void	ft_item_add_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}