#include "monty.h"

/**
 * check_command - CMonty command validation
 * @command: The command
 * Return: Nothing
 */
void (*check_command(char *command))(stack_t **, unsigned int)
{
	instruction_t ins_t[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue}
	};
	unsigned int i;

	for (i = 0; i < (sizeof(ins_t) / sizeof(instruction_t)); i++)
	{
		if (strcmp(command, ins_t[i].opcode) == 0)
			return (ins_t[i].f);
	}
	return (NULL);
}
