#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>

// An array in C is a collection of elements of the same data type stored in contiguous memory locations.
// It can be visualized as a series of boxes, each containing a value. The elements in an array are accessed
// using an index, which represents the position of the element in the array.
//
// Function prototypes
int* create_array(int size);                      // Dynamically create an array
void initialize_array(int* array, int size, int value); // Initialize the array with a specific value
void print_array(const int* array, int size);     // Print the array elements
void free_array(int** array);                     // Free the array memory

#endif // ARRAY_H
