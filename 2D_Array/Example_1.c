#include "2D_array.h"

// Create a 2D array dynamically
int** create_2d_array(int rows, int cols) {
    int** array = (int**)malloc(rows * sizeof(int*)); // Allocate rows
    if (!array) {
        printf("Memory allocation failed for rows.\n");
        exit(1);
    }

    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int)); // Allocate each row
        if (!array[i]) {
            printf("Memory allocation failed for columns in row %d.\n", i);
            exit(1);
        }
    }

    return array;
}

// Initialize the 2D array with a specific value
void initialize_2d_array(int** array, int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = value;
        }
    }
}

// Print the 2D array
void print_2d_array(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Free the memory used by the 2D array
void free_2d_array(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]); // Free each row
    }
    free(array); // Free the array of row pointers
}

int main() {
    int rows = 3, cols = 4;

    // Create a 2D array
    int** array = create_2d_array(rows, cols);

    // Initialize the array with a value (e.g., 7)
    initialize_2d_array(array, rows, cols, 7);

    // Print the array
    printf("2D Array:\n");
    print_2d_array(array, rows, cols);

    // Free the memory used by the array
    free_2d_array(array, rows);

    return 0;
}
