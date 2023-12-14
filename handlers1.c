#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void add(stack_t **stack, unsigned int opcode_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, opcode_line);
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void nop(stack_t **stack, unsigned int opcode_line)
{
	(void)stack;
	(void)opcode_line;
	/* nop does nothing */
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void sub(stack_t **stack, unsigned int opcode_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
}

/**
 * div_op - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void div_op(stack_t **stack, unsigned int opcode_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, opcode_line);
}


/**
 * mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the stack
 * @opcode_line: line number in the file
 */
void mul(stack_t **stack, unsigned int opcode_line)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", opcode_line);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, opcode_line);
}
