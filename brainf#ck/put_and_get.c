#include "bf.h"
/**
 * _getchar - reads a single character from stdin
 */
void _getchar()
{
	read(0, &bf.array[bf.index], 1);
}
/**
 * _putchar - writes a single character to stdout
 */
void _putchar()
{
	write(1, &bf.array[bf.index], 1);
}
