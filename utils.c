#include "push_swap.h"

void	check_stack(t_stack *t)
{
	t_stack *ptr;

	ptr = t;
	while (ptr)
	{
		printf("%d\n", ptr->number);
		ptr = ptr->next;
	}
	printf("%s\n", "check end");
}

t_stack	*delete_head(t_stack *root)
{
	t_stack		*temp;

	if (root->next)
	{
		temp = root->next;
		temp->prev = NULL;
		free(root);
		return (temp);
	}
	free(root);
	return (NULL);
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
		ptr->prev = NULL;
		ptr->flag = NULL;
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
			new->prev = ptr;
		}
	}
}

void	ft_item_add_front(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		(*lst)->prev = new;
		new->next = *lst;
		*lst = new;
	}
}