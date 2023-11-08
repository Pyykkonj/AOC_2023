/*
 * data_structures.c
 *
 *  Created on: 8.11.2023
 *      Author: juho.pyykkonen
 */

#include <data_structures.h>

void initDynamicArray(Array *a, size_t initialSize)
{
  a->array = malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element)
{
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void updateArray(Array *a, int element, int index)
{
	if (index > a->used)
	{
		return;
	}
	a->array[index] = element;
}

int getArray(Array *a, int index)
{
	if (index > a->used)
	{
		return -1;
	}
	return a->array[index];
}

int getArraySize(Array *a)
{
	return a->used;
}

void freeArray(Array *a)
{
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortArray(Array *a, bool reverseOrder)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < a->used; i++) {
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < a->used; j++)
            if (a->array[j] < a->array[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        swap(&a->array[min_idx], &a->array[i]);
    }
}

int popArray(Array *a)
{
	int latest = a->used;
	a->used--;

	return latest;
}
