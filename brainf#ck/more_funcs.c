#include "bf.h"
/**
 * shift_left - moves the index of the array by one backwards
 */
void shift_left()
{
	if (bf.index == 0)
	{
		bf.index = 65539;
	}
	else
	{
		bf.index--;
	}
}
/**
 * shift_right - moves array index forward by one
 */
void shift_right()
{
	bf.index++;
}
/**
 * increment - increases the value of the indexed element by 0ne
 */
void increment()
{
	bf.array[bf.index]++;
}
/**
 * decrement - decreases the value of the indexed element by 0ne
 */
void decrement()
{
        bf.array[bf.index]--;
}
