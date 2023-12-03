/*
 * day1.c
 *
 *  Created on: Nov 4, 2023
 *      Author: juho.pyykkonen
 */
#include <day.h>
#include <stdbool.h>


const char lettersChars[10][7] = {"zero\0", "one\0", "two\0", "three\0", "four\0", "five\0", "six\0", "seven\0", "eight\0", "nine\0"};
const int charsLen[10] = { 4, 3, 3, 5, 4, 4, 3, 5, 5, 4};

int isLetter(const char *a)
{
	for (int i = 0; i < 10; i++)
	{
		int ret = strncmp(lettersChars[i], a, charsLen[i]);
		if (ret == 0)
		{
			return i;
		}
	}

	return -1;

}

bool isNumber(char a)
{
	if (a >= 48 && a <= 57)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int charToInt(char a)
{
	if(isNumber(a))
	{
		return (int) a - 48;
	}
	else {
		return (int)-1;
	}
}


void extract_calibration_values(char *filebuf)
{


	int firstDigit = -1;
	int lastDigit = -1;

	int sum = 0;

	int count = 0;
	char *previous = NULL;
	char *current = &filebuf[count];

	{

		while(*current != 0)
		{

			if (*previous == '\n')
			{
				printf("New line\r\n");

				char buf[3];
				sprintf(buf, "%d%d", firstDigit, lastDigit);

				if(firstDigit != -1 && lastDigit != -1)
				{
					sum = sum + atoi(buf);
				}

				printf("buf: %s\r\n", buf);
				printf("sum: %d \r\n", sum);

				firstDigit = -1;
				lastDigit = -1;

			}

			{
				if (isNumber(*current))
				{
					if(firstDigit == -1 && lastDigit == -1)
					{
						firstDigit = charToInt(*current);
						lastDigit = charToInt(*current);
					}
					else
					{
						lastDigit = charToInt(*current);
					}
				}
				else
				{
					int ret = isLetter(current);
					//printf("ret: %d \r\n", ret);
					if (ret != -1)
					{
						if(firstDigit == -1 && lastDigit == -1)
						{
							firstDigit = ret;
							lastDigit = ret;
						}
						else
						{
							lastDigit = ret;
						}
					}
				}
			}

			count++;
			previous = current;
			current = &filebuf[count];
		}

		// handle last
		char buf[3];
		sprintf(buf, "%d%d", firstDigit, lastDigit);

		sum = sum + atoi(buf);
		printf("buf: %s\r\n", buf);
		printf("sum: %d \r\n", sum);

		printStringInt("Day 1 sum:", sum, false);

	}

}


void day_1(char *input_filebuf)
{
	printf("Hello from day 1 \r\n");

	printStringString("Day 1", "Calculating...", false);

	extract_calibration_values(input_filebuf);
}
