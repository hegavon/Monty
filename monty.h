#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
} bus_t;

/* Getter and setter functions for bus */
bus_t get_bus(void);
void set_bus(bus_t new_bus);

/* Function prototypes */

void push(stack_t **stack, unsigned int opcode_line);
void pall(stack_t **stack, unsigned int opcode_line);
void pint(stack_t **stack, unsigned int opcode_line);
void pop(stack_t **stack, unsigned int opcode_line);
void swap(stack_t **stack, unsigned int opcode_line);
void add(stack_t **stack, unsigned int opcode_line);
void nop(stack_t **stack, unsigned int opcode_line);
void sub(stack_t **stack, unsigned int opcode_line);
void div_op(stack_t **stack, unsigned int opcode_line);
void mul(stack_t **stack, unsigned int opcode_line);
void mod(stack_t **stack, unsigned int opcode_line);
void pchar(stack_t **stack, unsigned int opcode_line);
void pstr(stack_t **stack, unsigned int opcode_line);
void rotl(stack_t **stack, unsigned int opcode_line);
void rotr(stack_t **stack, unsigned int opcode_line);
void f_stack(stack_t **stack, unsigned int opcode_line);
void f_queue(stack_t **stack, unsigned int opcode_line);
void addqueue(stack_t **stack, int n);
void process_file(char *filename, stack_t **stack);
void execute_opcode(char *line, unsigned int line_number, stack_t **stack);
instruction_t *get_instruction(char *opcode);
int is_number(char *str);
void free_stack(stack_t *stack);
void free_instruction(instruction_t *instruction);

#endif /* MONTY_H */
