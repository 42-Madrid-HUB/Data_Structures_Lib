#ifndef _2D_ARRAY_H
#define _2D_ARRAY_H

#include <stdlib.h>
#include <stdio.h>

// A 2D array in C++ is essentially an array of arrays. It can be visualized as a grid or a table with rows and columns.
// For example, a 2D array with 3 rows and 4 columns can be declared as:
// int array[3][4];
//
// The elements in the 2D array can be accessed using two indices: one for the row and one for the column.
// For example, array[1][2] refers to the element in the second row and third column.
//
// Here's a simple example of how to initialize and access elements in a 2D array:
//
// int array[3][4] = {
//     {1, 2, 3, 4},
//     {5, 6, 7, 8},
//     {9, 10, 11, 12}
// };
//
// To access the element in the second row and third column, you would use:
// int value = array[1][2]; // value would be 7
//
// 2D arrays are useful for representing matrices, grids, and other tabular data structures.

// Function prototypes
int** create_2d_array(int rows, int cols);      // Create a 2D array
void initialize_2d_array(int** array, int rows, int cols, int value); // Initialize with a specific value
void print_2d_array(int** array, int rows, int cols); // Print the 2D array
void free_2d_array(int** array, int rows);      // Free the memory allocated for the 2D array

#endif // _2D_ARRAY_H
