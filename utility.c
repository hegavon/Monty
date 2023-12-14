#include "monty.h"

/**
 * is_number - check if a string is a number
 * @str: the string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i;

	if (str == NULL || *str == '\0')
		return (0);

	i = 0;

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * free_instruction - free the dynamically allocated instruction structure
 * @instruction: pointer to the instruction structure
 */
void free_instruction(instruction_t *instruction)
{
	free(instruction);
}
