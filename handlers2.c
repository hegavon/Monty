#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void mod(stack_t **stack, unsigned int opcode_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, opcode_line);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void pchar(stack_t **stack, unsigned int opcode_line)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;

	if (value < 0 || value > 127) /* Check if value is in the ASCII range */
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	putchar(value);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void pstr(stack_t **stack, unsigned int opcode_line)
{
	stack_t *current = *stack;

	(void)opcode_line; /* Unused parameter */

	while (current != NULL && current->n != 0 && current->n >= 0 &&
			current->n <= 127)
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void rotl(stack_t **stack, unsigned int opcode_line)
{
	(void)opcode_line; /* Unused parameter */

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *tmp = *stack;
		stack_t *aux = (*stack)->next;

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}

		tmp->next = *stack;
		(*stack)->next = NULL;
		(*stack)->prev = tmp;

		*stack = aux;
		aux->prev = NULL;
	}
}


/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void rotr(stack_t **stack, unsigned int opcode_line)
{
	(void)opcode_line; /* Unused parameter */

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *last = *stack;
		stack_t *second_last = NULL;

		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}

		second_last->next = NULL;
		last->prev = NULL;

		last->next = *stack;
		(*stack)->prev = last;

		*stack = last;
	}
}
