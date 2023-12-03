/*
 * advent_of_code.c
 *
 *  Created on: Nov 4, 2023
 *      Author: juho.pyykkonen
 */

#include <stdio.h>
#include <File_Handling.h>
#include <day.h>

/*File handling*/
#include "fatfs.h"
#include "string.h"
#include "stdio.h"
#include "fatfs.h"

/*Character display*/
#include <main.h>
#include <LiquidCrystal.h>
#include <ui.h>

FIL file;
FILINFO f_info;
FRESULT f_result;  // result
UINT f_rb, f_wb;  // File read/write byte count

#define DAY 1

#define DAY_FILE "day.txt"


/**
 * Read file to filebuf
 * @param name
 * @param filebuf
 * @return 0 if success
 */
char *read_file(char *name)
{
	/* Check file exists */
	f_result = f_stat(name, &f_info);
	if (f_result != FR_OK)
	{
		printf("File not found! \r\n");
		return NULL;
	}

	/* Open file to read */
	f_result = f_open(&file, name, FA_READ);
	if (f_result != FR_OK)
	{
		printf("ERROR!!! No. %d in opening file *%s*\n\n", f_result, name);
		return NULL;
	}

	/* Read file */
	char *filebuf = malloc(f_size(&file) + 1);
	f_result = f_read (&file, filebuf, f_size(&file), &f_rb);
	if (f_result != FR_OK)
	{
		free(filebuf);
		printf("ERROR!!! No. %d in reading file *%s*\n\n", f_result, name);
		return NULL;
	}

	filebuf[f_size(&file)] = 0;

	/* Print file */
	//printf("File %s: \r\n", name);
	//printf(filebuf);
	//printf("\r\n");

	/* Close file */
	f_result = f_close(&file);
	if (f_result != FR_OK)
	{
		printf("ERROR!!! No. %d in closing file *%s*\n\n", f_result, name);
	}
	else
	{
		printf("File *%s* CLOSED successfully\r\n", name);
	}

	return filebuf;
}

int read_day_file()
{
	printf("Looking for day file day.txt ...\r\n");

	int day = 0;

	char* filebuf = read_file(DAY_FILE);

	if(filebuf != NULL)
	{
		//printf(filebuf);
		day = atoi(filebuf);

		if (day > 0 && day < 25)
		{
			printf("DAY: %d\r\n", day);
		}
		else
		{
			printf("Illegal day selected! \r\n");
			return -1;
		}

	}

	free(filebuf);

	return day;
}

char *read_input_file(int day)
{

	char *buf = malloc(10*sizeof(char));
	sprintf(buf, "%d.txt", day);

	printf("Looking for input file %s ...\r\n", buf);

	char* filebuf = read_file(buf);
	free(buf);

	if (filebuf != NULL)
	{
		printf("File %s found \r\n", buf);
	}

	//printf(filebuf);
	//printf("\r\n");

	return filebuf;
}

void run_Advent_of_code()
{
	//printf("Hello from day %d \r\n", DAY);

	printf("Mount SD card \r\n");
	Mount_SD("/");

	int day = 0;
	char *input_filebuf = NULL;

	day = read_day_file();
	if(day < 0)
	{
		// TODO
		return;
	}
#if 1
	input_filebuf = read_input_file(day);
	if(input_filebuf == NULL)
	{
		// TODO
		return;
	}
#endif
	Unmount_SD("/");

	printf("\r\n*** Start calculus...*** \r\n");

#if 0
	clear();
	setCursor(0,0);
	print("Start calculus");
#endif

	switch (day)
	{
		case 1:
			day_1(input_filebuf);
			break;
		case 2:
			day_2(input_filebuf);
			break;
		case 3:
			day_3();
			break;

		default:
			printf("Day %d not implemented!\r\n", day);

	}


}




