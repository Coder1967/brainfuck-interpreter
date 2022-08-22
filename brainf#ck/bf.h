#ifndef BF_H
#define BF_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * @array: the array used to run the commands
 * @index: index of the current elsement
 * @brac_balance: ensures the square brackets are balanced
 * @str: ariable to store commands read from file
 */
struct bf_s
{
	int *array;
	size_t index;
	int brac_balance;
	char *str;
};
struct bf_s bf;

void _putchar();
void _getchar();
void interpreter();
void free_bf();
void shift_right();
void shift_left();
void increment();
void decrement();
void start_loop(size_t *str_index);
void end_loop(size_t *str_index);
#endif
