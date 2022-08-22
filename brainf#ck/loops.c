#include "bf.h"
/**
 * start_loop - skips the '[]' brackets if the indexed element
 * of the array is zero
 * @str_index: pointer to the index of the string(which contains commands
 * read from the file)
 */
void start_loop(size_t *str_index)
{
	if (bf.array[bf.index] == 0)
	{
		(*str_index)++;
		while (bf.brac_balance != 0 || bf.str[*str_index] != ']')
		{
			if ( bf.str[*str_index] == '[')
			{
				bf.brac_balance++;
			}

			if ( bf.str[*str_index] == ']')
			{
				bf.brac_balance--;
			}
			(*str_index)++;
		}
	}
}
/**
 * end_loop - keeps replaying a sequence of commands until
 * the indexed element becomes zero
 * @str_index: pointer to the index of the string(which contains commands
 * read from the file)
 */
void end_loop(size_t *str_index)
{
	if (bf.array[bf.index] != 0)
	{
		(*str_index)--;
		while (bf.brac_balance != 0 || bf.str[*str_index] != '[')
                {
                        if ( bf.str[*str_index] == ']')
                        {
                                bf.brac_balance++;
                        }

                        if ( bf.str[*str_index] == '[')
                        {
                                bf.brac_balance--;
                        }
                        (*str_index)--;
                }
		(*str_index)--;
	}
}
