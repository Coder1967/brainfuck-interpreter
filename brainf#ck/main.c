#include "bf.h"
/**
 * main - driver function
 * @argc: number of passed arguments
 * @argv: an aray of strngs of passed arguments
 */
int main(int argc, char **argv)
{
	char c;
	int i = 0;
	FILE *file;
	size_t file_length;
	bf.index = 0;

	if (argc < 2)
	{
		dprintf(2, "usage: ./bf <file>.bf\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(2, "%s not found\n", argv[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	/* ensuring all the cells are initialized to zero*/
	bf.array = (int *) malloc(65540 * sizeof(int));
	for (i = 0; i < 65540; i++)
	{
		bf.array[i] = 0;
	}
	fseek(file, 0, SEEK_END);
	file_length = ftell(file);
	fseek(file, 0, SEEK_SET);
	bf.str = (char *) malloc((sizeof(char) * file_length)+1);
	if (bf.str == NULL || bf.array == NULL)
	{
		dprintf(2, "not enough memory\n");
		free_bf();
		fclose(file);
		exit(EXIT_FAILURE);
	}
	i = 0;
	
	while ((c = fgetc(file)) != EOF)
	{
		bf.str[i] = c;
		i++;
	}
	bf.str[i] = '\0';
	interpreter();
	free_bf();
	fclose(file);
	return (0);
}
/**
 * interpreter - parses file and runs commands
 */
void interpreter()
{
	size_t str_index = 0;

	while (bf.str[str_index] != '\0')
	{
		switch(bf.str[str_index])
		{
			case '+':
				increment();
				break;
			case '-':
				decrement();
				break;
			case ',':
				_getchar();
				break;
			case '.':
				_putchar();
				break;
			case '>':
				shift_right();
				break;
			case '<':
				shift_left();
				break;
			case '[':
				start_loop(&str_index);
				break;
			case ']':
				end_loop(&str_index);
				break;
		}
		 str_index++;
	}
}
