#include <stdlib.h>

int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
		       char *buff, int buff_size);
char *get_int(int num);
unsigned int _abs(int);

/**
 * get_int - Gets a char ptr to new string having integer
 * @num: Number 2 Convert 2 String
 *
 * Return: Char Ptr to newly created string. NULL if malloc fails.
 */

char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - Gets absolute value of an int
 * @i: Int to get Absolute value of
 *
 * Return: Unsigned Int abs rep of i
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Gets length of Buffer needed for an unsigned integer
 * @num: The number to get length needed
 * @base: A Base of number representation 
 *
 * Return: An int containing length of buffer needed (doesn't contain null bt)
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* All numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Fills Buffer with correct numbers up to base 36
 * @num: The Number to convert to string 
 * @base: the  base of number used in conversion, only works up to base 36
 * @buff: the Buffer to fill with result of conversion
 * @buff_size: Size of Buffer in Bytes
 *
 * Return: Always void.
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}
