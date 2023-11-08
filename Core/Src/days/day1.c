/*
 * day1.c
 *
 *  Created on: Nov 4, 2023
 *      Author: juho.pyykkonen
 */
#include <day.h>

void extract_Elf_bags(char *filebuf)
{
	Array elfCalories;

	initDynamicArray(&elfCalories, 10);

	int count = 0;
	char *previous = NULL;
	char *current = &filebuf[count];

	{
		// Handle first
		printf("%d \r\n", atoi(current));
		int sum = atoi(current);

		while(*current != 0)
		{

			if(*current == '\r' && *previous == '\n')
			{
				printf("EMPTY LINE \r\n");
				printf("SUM: %d\r\n", sum);
				insertArray(&elfCalories, sum);
				sum = 0;
			}
			else if (*previous == '\n')
			{
				printf("%d \r\n", atoi(current));
				sum += atoi(current);
			}
			else
			{
				//printf("%c", *current);
			}

			count++;
			previous = current;
			current = &filebuf[count];
		}

		// Handle last
		insertArray(&elfCalories, sum);
	}


	printf("\r\n");

	printf("ELf calories total \r\n");
	int totalElfes = getArraySize(&elfCalories);
	int calories = 0;
	int mostCalories = 0;
	int mostCaloriesElf = 0;
	int i = 0;

	for (i=0 ; i<totalElfes; i++)
	{
		calories = getArray(&elfCalories, i);
		printf("Elf %d, calories: %d \r\n", i, calories);
		if (calories > mostCalories)
		{
			mostCalories = calories;
			mostCaloriesElf = i;
		}
	}

	printf("\r\nElf carrying most calories: %d, elf index: %d\r\n", mostCalories, mostCaloriesElf);

	clear();
	setCursor(0,0);
	print("Most calories:");
	setCursor(0,1);
	char buf[10];
	sprintf(buf, "%d", mostCalories);
	print(buf);

	sortArray(&elfCalories, false);

	printf("Top three: \r\n");
	printf("%d \r\n", getArray(&elfCalories, i-1));
	printf("%d \r\n", getArray(&elfCalories, i-2));
	printf("%d \r\n", getArray(&elfCalories, i-3));

	printf("SUM of top three: %d \r\n",
			getArray(&elfCalories, i-1) +
			getArray(&elfCalories, i-2) +
			getArray(&elfCalories, i-3));
}


void day_1(char *input_filebuf)
{
	printf("Hello from day 1 \r\n");

	clear();
	print("Day 1");
	setCursor(0,1);
	print("Calculating...");

	extract_Elf_bags(input_filebuf);

}
