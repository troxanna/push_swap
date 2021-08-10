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
	printf("\ntest_func\n");
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

int	count_item_true_elements(int **arr, int len)
{
	int	i;
	int j;
	int	*count;
	int	tmp;

	i = -1;
	j = -1;
	count = (int *)malloc(sizeof(int) * len);
	while (arr[++i])
	{
		j = -1;
		count[i] = 0;
		while(++j < len)
			if (arr[i][j])
				count[i] = count[i] + 1;
	}
	i = 0;
	tmp = count[i];
	while (count[++i])
	{
		if (count[i] > count[i - 1])
			tmp = count[i];
		else
			count[i] = count[i - 1];
	}
	return (tmp);
}


// void	check_least_item_elements()

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *ptr;
	int	i;
	int	count;
	int **array;

	i = -1;
	count = argc - 1;
	array = (int **)malloc(sizeof(int *) * (count + 1));
	array[count] = NULL;
	while (++i < count)
	{
		array[i] = (int *)malloc(sizeof(int) * count);
		printf("%d\n", i);
		//array[i][0] = 1;
	}
	i = 1;
	a = ft_elem_new(ft_atoi(argv[i]), 0);
	ptr = a;
	while (++i < argc)
	{
		ft_elem_add_back(&ptr, ft_elem_new(ft_atoi(argv[i]), 0));
	}
	while (ptr)
	{
		write(1, "test\n", 5);
		ptr->index = set_number_index(a, count, ptr->number);
		ptr = ptr->next;
	}
	write(1, "middle_test\n", 13);
	ptr = a;
	i = -1;
	while (ptr)
	{
		write(1, "test\n", 5);
		number_item_markup(count, ptr, a, array[++i]);
		ptr = ptr->next;
	}
	write(1, "final_test\n", 12);
	int test;

	// array = number_item_markup(count, ptr->next, a);
	//printf("array_index: %d\n", array[0]);
	//write(1, "test", 4);
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
	test = count_item_true_elements(array, count);
	printf("max true is: %d\n", test);
	return (1);
}