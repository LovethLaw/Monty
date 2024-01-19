#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
* main - this is the main function entry point.
* @argc: command line argument count.
* @argv: command line argument vector array.
* Return: 0 on success.
*/

int main(int argc, char *argv[]);
int main(int argc, char *argv[])
{
	FILE *filed;

	char *filename;

	char *bufferptr;

	size_t buffsize;

	stack_t *stack = NULL;

	unsigned int linenumber = 0;

	instruction_t instruct[] = {

		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_func},
		{"mul", mul_func},
		{"div", div_func},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	filename = argv[1];

	filed = fopen(filename, "r");


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");

		exit(EXIT_FAILURE);
	}

	if (filed == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);

		exit(EXIT_FAILURE);
	}

	while (getline(&bufferptr, &buffsize, filed) != -1)
	{
		char *opcodetoken;

		linenumber += 1;

		if (bufferptr[0] == '#' || bufferptr[0] == '\n')
		{
			continue;
		}

		opcodetoken = strtok(bufferptr, " \n\t");

		if (opcodetoken != NULL)
		{
			int i = 0;

			while (instruct[i].opcode != NULL)
			{
				if (strcmp(opcodetoken, instruct[i].opcode) == 0)
				{
					instruct[i].f(&stack, linenumber);
					break;
				}
				i += 1;
			}

			if (instruct[i].opcode == NULL)
			{
				char *op = opcodetoken;

				unsigned int ln = linenumber;

				char *msg = "L%u: unknown instruction %s\n";

				fprintf(stderr, msg, ln, op);
				fclose(filed);
				free(bufferptr);
				free_stack(&stack);
				exit(EXIT_FAILURE);
			}
		}
	}

	fclose(filed);
	free(bufferptr);
	free_stack(&stack);
	return (0);
}
