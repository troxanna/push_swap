//1. Индексируем: каждое число в стеке помечаем 0 или 1. 
//1.1. Берем любой элемент (вершину, н-р), помечаем ее 1. Смотрим следующий элемент - если он больше текущего - помечаем 1, если меньше - 0.
//Если пометили 0 и не обошли весь стек - сравниваем последнее число с 1 и следующий элемент, пока != 1.
//Проходим весь стека. 
//2. Повторяем шаг один, последовательно меняя вершину стека.
//3. Из проиндексированных стеков выбираем тот, где больше всего 1.
//4. Перемещаем все 0 в стек Б
//5. В стеке Б перебираем все числа и считаем для каждого числа количество команд (ra), которые необходимо будет сделать, чтобы поместить число из стека Б в нужное место в стеке А (между наименьшим и наиболльшим).
//6. Там где наименьшее количество команд - добавляем это число в стек А.
//7. Повторяем шаги 5- 6 для всех элементов стека А.

#include "push_swap.h"

int	set_number_index(t_stack *a, int count, int number)
{	
	int	i;
	t_stack	*ptr;
	int tmp_count;

	ptr = a;
	tmp_count = count - 1;
	i = -1;
	while (++i < count && ptr)
	{
		if (number < ptr->number)
			tmp_count--;
		ptr = ptr->next;
	}
	return (tmp_count);
}


// int	*index_item_markup(int count, t_stack *item, t_stack *head)
// {

// }

void	number_item_markup(int count, t_stack *item, t_stack *head, int *array)
{
	int	*tmp_array;
	t_stack *ptr_head;
	unsigned int item_tmp;
	t_stack *ptr_current;
	int i;

	i = 0;
	ptr_head = head;

	ptr_current = item->next;
	// array = (int *)malloc(sizeof(int) * count);
	array[0] = 1;
	item_tmp = item->index;
	//printf("\n\n%d\n\n", item_tmp);
	while (ptr_current)
	{
		if (item_tmp < ptr_current->index)
		{
			array[++i] = 1;
			item_tmp = ptr_current->index;
		}
		else
			array[++i] = 0; 
		ptr_current = ptr_current->next;
	}
	if (ptr_current && item_tmp < ptr_head->index)
	{
		array[++i] = 1;
		item_tmp = ptr_current->index;
	}
	while (ptr_head->number != item->number)
	{
		if (item_tmp < ptr_head->index)
		{
			array[++i] = 1;
			item_tmp = ptr_head->index;
		}
		else
			array[++i] = 0; 
		ptr_head = ptr_head->next;
	}
}

// int		count_sorted_items()
// {

// }

int	*count_item_true_elements(int **arr, int len, t_stack *head)
{
	int	i;
	int j;
	int	**count;
	int	*tmp;
	t_stack *ptr;

	i = -1;
	j = -1;
	count = (int **)malloc(sizeof(int *) * len + 1);
	tmp = (int *)malloc(sizeof(int) * 2);
	count[len] = NULL;
	ptr = head;
	while (arr[++i] && ptr)
	{
		j = -1;
		count[i] = (int *)malloc(sizeof(int) * 2);
		count[i][0] = 0;
		count[i][1] = ptr->number;
		while(++j < len)
			if (arr[i][j])
				count[i][0] = count[i][0] + 1;
		ptr = ptr->next;
	}
	i = 0;
	tmp[0] = count[i][0];
	tmp[1] = count[i][1];
	while (count[++i])
	{
		if (count[i][0] > count[i - 1][0] || (count[i][0] == tmp[0] && count[i][1] < tmp[1]))
		{
			tmp[0] = count[i][0];
			tmp[1] = count[i][1];
		}
		else
			count[i][0] = count[i - 1][0];
	}
	return (tmp);
}

void	fill_in_stack_b(t_stack *a, int index, int *arr, t_stack *b)
{
	t_stack	*ptr;
	int	i;

	ptr = a;
	i = -1;
	while (ptr)
	{
		if (ptr->index == index)
			break ;
		ptr = ptr->next;
	}
	while (ptr)
	{
		++i;
		printf("%d\n", arr[i]);
		if (arr[i] == 0)
		{
			printf("%s\n", "ttttest");
			b = ft_elem_new(ptr->number, ptr->index);
			ptr = ptr->next;
			break ;
		}
		ptr = ptr->next;
	}
	while (ptr)
	{
		++i;
		printf("%d\n", arr[i]);
		if (!b && arr[i] == 0)
		{
			b = ft_elem_new(ptr->number, ptr->index);
		}
		else if (arr[i] == 0)
			ft_elem_add_back(&b, ft_elem_new(ptr->number, ptr->index));
		ptr = ptr->next;
	}
	ptr = a;
	while (ptr)
	{
		++i;
		printf("%d\n", arr[i]);
		if (ptr->index == index)
			break ;
		if (!b && arr[i] == 0)
		{
			b = ft_elem_new(ptr->number, ptr->index);
		}
		else if (arr[i] == 0)
			ft_elem_add_back(&b, ft_elem_new(ptr->number, ptr->index));
		ptr = ptr->next;
	}
	printf("%d\n", b->number);
}

// void	check_least_item_elements()

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack *ptr;
	int	i;
	int	count;
	int **array;

	i = -1;
	count = argc - 1;
	array = (int **)malloc(sizeof(int *) * (count + 1));
	array[count] = NULL;
	while (++i < count)
		array[i] = (int *)malloc(sizeof(int) * count);
	i = 1;
	a = ft_elem_new(ft_atoi(argv[i]), 0);
	ptr = a;
	while (++i < argc)
		ft_elem_add_back(&ptr, ft_elem_new(ft_atoi(argv[i]), 0));
	while (ptr)
	{
		ptr->index = set_number_index(a, count, ptr->number);
		ptr = ptr->next;
	}
	ptr = a;
	i = -1;
	while (ptr && array[++i])
	{
		number_item_markup(count, ptr, a, array[i]);
		ptr = ptr->next;
	}
	int *result;

	i = -1;
	int j = -1;
	ptr = a;
	while (++i < count && ptr)
	{
		j = -1;
		printf("number is: %d\n", ptr->number);
		while (++j < count)
		{
			printf("array_index: %d\n", array[i][j]);
		}
		ft_putstr_fd("\n\n\n", 1);
		ptr = ptr->next;
	}
	result = count_item_true_elements(array, count, a);
	printf("max true is: %d, %d\n", result[0], result[1]);
	fill_in_stack_b(a, result[1], array[result[0]], b);
	i = -1;
	ptr = b;
	while (ptr)
	{
		printf("stack b, number is: %d\n", ptr->number);
		printf("stack b, index is: %d\n", ptr->index);
		ptr = ptr->next;
	}
	return (1);
}