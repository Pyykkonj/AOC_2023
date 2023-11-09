/*
 * ui.h
 *
 *  Created on: 9.11.2023
 *      Author: juho.pyykkonen
 */

#include <ui.h>

#define CHARS_PER_ROW 16


void printStringString(char *str1, char *str2, bool center)
{
	char buf1[CHARS_PER_ROW], buf2[CHARS_PER_ROW];

	int strLen1 = strlen(str1);
	int strLen2 = strlen(str2);

	if(center && (strLen1 < CHARS_PER_ROW) && (strLen2 < CHARS_PER_ROW))
	{
		int padding1 = (CHARS_PER_ROW - strLen1) / 2;
		memset(buf1, ' ', padding1);
		sprintf(buf1 + padding1, "%s", str1);

		int padding2 = (CHARS_PER_ROW - strLen2) / 2;
		memset(buf2, ' ', padding2);
		sprintf(buf2 + padding2, "%s", str2);
	}
	else
	{
		sprintf(buf1, "%s", str1);
		sprintf(buf2, "%s", str2);
	}

	clear();
	print(buf1);
	setCursor(0,1);
	print(buf2);
}

void printStringInt(char *str1, int n, bool center)
{
	char str2[CHARS_PER_ROW];
	sprintf(str2, "%d", n);
	printStringString(str1, str2, center);
}

void updateSecondRowString(char *str, bool center)
{
	char buf[CHARS_PER_ROW];

	if(center)
	{
		int padding = (CHARS_PER_ROW - strlen(str)) / 2;
		memset(buf, ' ', padding);
		sprintf(buf + padding, "%s", str);
	}
	else
	{
		sprintf(buf, "%s", str);
	}

	setCursor(0,1);
	print(buf);
}

void updateSecondRowInt(int n, bool center)
{
	char str2[CHARS_PER_ROW];
	sprintf(str2, "%d", n);
	updateSecondRowString(str2, center);
}


