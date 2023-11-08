/*
 * data_structures.h
 *
 *  Created on: 8.11.2023
 *      Author: juho.pyykkonen
 */

#ifndef INC_DATA_STRUCTURES_H_
#define INC_DATA_STRUCTURES_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;


void initDynamicArray(Array *a, size_t initialSize);
void insertArray(Array *a, int element);
void updateArray(Array *a, int element, int index);
int getArray(Array *a, int index);
int getArraySize(Array *a);
void freeArray(Array *a);
void sortArray(Array *a, bool reverseOrder);
int popArray(Array *a);


#endif /* INC_DATA_STRUCTURES_H_ */
