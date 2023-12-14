#include "monty.h"

/**
 * main - entry point for the Monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: Monty file\n");
		exit(EXIT_FAILURE);
	}

	process_file(argv[1], &stack);

	free_stack(stack);

	return (EXIT_SUCCESS);
}

/**
 * process_file - read and process the bytecode file
 * @filename: the name of the bytecode file
 * @stack: pointer to the stack
 */
void process_file(char *filename, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;

	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		execute_opcode(line, line_number, stack);
	}

	fclose(file);

	free(line);
}

/**
 * execute_opcode - execute the opcode from a line of the bytecode file
 * @line: the line containing the opcode
 * @line_number: the line number in the file
 * @stack: pointer to the stack
 */
void execute_opcode(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode = strtok(line, " \n");

	if (line[0] == '#' || line[0] == '\n')
		return; /* Ignore comments and empty lines */

	if (opcode != NULL)
	{
		instruction_t *instruction = get_instruction(opcode);

		if (instruction != NULL)
		{
			instruction->f(stack, line_number);
			free_instruction(instruction);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * get_instruction - get the instruction corresponding to the opcode
 * @opcode: the opcode
 * Return: a pointer to the dynamically allocated instruction structure
 *         or NULL if not found
 */
instruction_t *get_instruction(char *opcode)
{
	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", f_stack},
		{"queue", f_queue},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instruction_t *result = malloc(sizeof(instruction_t));

			if (result == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}

			*result = instructions[i];
			return (result);
		}
		i++;
	}
	return (NULL);
}
