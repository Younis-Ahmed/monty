#include "monty.h"



/**
* main - entry point
* @argc: arg count
* @argv: atgs vec
*Return: EXIT SUCCESS
*/
int main(int argc, char **argv)
{
	montystruct_init();
	openfile(argc, argv[1]);
	read_line();
	free_all();
	return (EXIT_SUCCESS);
}
