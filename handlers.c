#include "monty.h"

/**
 * push - push an element to the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 * Return: no return
 */
void push(stack_t **stack, unsigned int opcode_line)
{
	char *arg;
	stack_t *new_node;

	arg = strtok(NULL, " \n");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "L%d: Error: malloc failed\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - print all the values on the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 * Return: no return
 */
void pall(stack_t **stack, unsigned int opcode_line)
{
	stack_t *current;

	(void)opcode_line; /* Unused parameter */

	current = *stack;

	if (current == NULL)
		return;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - print the value at the top of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 * Return; no return
 */
void pint(stack_t **stack, unsigned int opcode_line)
{
	(void)opcode_line; /* Unused parameter */

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - pop an element from the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 * Return: no return
 */
void pop(stack_t **stack, unsigned int opcode_line)
{
	stack_t *temp;

	(void)opcode_line; /* Unused parameter */

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: Stack empty\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = *temp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap - swap the top two elements of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 * Return: return
 */
void swap(stack_t **stack, unsigned int opcode_line)
{
	stack_t *first, *second;

	(void)opcode_line; /* Unused parameter */

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: Stack too short to swap\n");
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = (*stack)->next;

	first->next = second->next;
	first->prev = second;
	second->next = first;

	if (first->next != NULL)
		first->next->prev = first;

	second->prev = NULL;
	*stack = second;
}

