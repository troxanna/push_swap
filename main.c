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
	tmp_count = count - 2;
	i = -1;
	while (++i < count && ptr)
	{
		if (number < ptr->number)
			tmp_count--;
		ptr = ptr->next;
	}
	return (tmp_count);
}

void	stack_indexing()
{
	
}

int	*stack_item_markup(int count, t_stack *item, t_stack *head)
{
	int	*tmp_array;
	t_stack *ptr_head;
	unsigned int item_tmp;
	t_stack *ptr_current;
	int i;

	i = 0;
	ptr_head = head;

	ptr_current = item->next;
	tmp_array = (int *)malloc(sizeof(int) * count);
	item_tmp = ptr_current->index;
	while (ptr_current)
	{
		if (item_tmp < ptr_current->index)
		{
			tmp_array[i++] = 1;
			item_tmp = ptr_current->index;
		}
		else
		{
			tmp_array[i++] = 0;
		}
		ptr_current = ptr_current->next;
	}
	// if (ptr_current->index < ptr_head->index)
	// while (ptr_head != item)
	// {

	// }
	return (tmp_array);
}

// int		count_sorted_items()
// {

// }

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *ptr;
	int	i;

	i = 1;
	a = ft_elem_new(ft_atoi(argv[i]), 0);
	ptr = a;
	while (++i < argc)
		ft_elem_add_back(&ptr, ft_elem_new(ft_atoi(argv[i]), 0));
	i = -1;
	while (ptr)
	{
		ptr->index = set_number_index(a, argc, ptr->number);
		ptr = ptr->next;
	}
	ptr = a;
	while (ptr)
	{
		printf("number: %d index: %d\n", ptr->number, ptr->index);
		ptr = ptr->next;
	}
	ptr = a;
	int *array;
	array = stack_item_markup(argc, ptr->next, a);
	//write(1, "test", 4);
	i = -1;
	while (array[++i])
	{
		write(1, "test", 4);
		printf("array_index: %d\n", array[i]);
	}
	return (1);
}