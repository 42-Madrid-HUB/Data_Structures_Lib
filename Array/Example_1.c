#include "Array.h"

// Create a dynamically allocated array
int* create_array(int size) {
    if (size <= 0) {
        printf("Invalid size: %d. Size must be greater than 0.\n", size);
        exit(1);
    }

    int* array = (int*)malloc(size * sizeof(int));
    if (!array) { // Ensure memory allocation succeeded
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return array;
}

// Initialize the array with a specific value
void initialize_array(int* array, int size, int value) {
    for (int i = 0; i < size; i++) {
        array[i] = value;
    }
}

// Print the elements of the array
void print_array(const int* array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Free the allocated memory for the array
void free_array(int** array) {
    if (*array) {
        free(*array);
        *array = NULL; // Avoid dangling pointers
    }
}

int main() {
    int size = 5;
    int value = 7;

    // Create an array
    int* array = create_array(size);

    // Initialize the array with a value
    initialize_array(array, size, value);

    // Print the array
    printf("Array contents: ");
    print_array(array, size);

    // Free the memory used by the array
    free_array(&array);

    return 0;
}
