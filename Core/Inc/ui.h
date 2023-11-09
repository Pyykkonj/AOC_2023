/*
 * ui.h
 *
 *  Created on: 9.11.2023
 *      Author: juho.pyykkonen
 */

#ifndef INC_UI_H_
#define INC_UI_H_

#include <main.h>
#include <LiquidCrystal.h>
#include <stdbool.h>

// Sprintf
#include <stdio.h>

// Strlen
#include <string.h>

void printStringString(char *str1, char *str2, bool center);

void printStringInt(char *str1, int n, bool center);

void updateSecondRowString(char *str, bool center);

void updateSecondRowInt(int n, bool centers);




#endif /* INC_UI_H_ */
