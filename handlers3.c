#include "monty.h"

/**
 * f_stack - prints the top
 * @stack: stack stack
 * @opcode_line: line_number
 * Return: no return
 */
void f_stack(stack_t **stack, unsigned int opcode_line)
{
	bus_t bus;
	(void)stack;
	(void)opcode_line;

	bus = get_bus();
	bus.lifi = 0;
	set_bus(bus);
}

/**
 * f_queue - prints the top
 * @stack: stack stack
 * @opcode_line: line_number
 * Return: no return
 */
void f_queue(stack_t **stack, unsigned int opcode_line)
{
	bus_t bus;
	(void)stack;
	(void)opcode_line;

	bus = get_bus();
	bus.lifi = 1;
	set_bus(bus);
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @stack: stack of the stack
 * Return: no return
 */
void addqueue(stack_t **stack, int n)
{
	stack_t *new_node, *aux;

	aux = *stack;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		return;
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
