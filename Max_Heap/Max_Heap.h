#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h>

// Max Heap structure
typedef struct MaxHeap {
    int* array;      // Pointer to the heap array
    int capacity;    // Maximum capacity of the heap
    int size;        // Current size of the heap
} MaxHeap;

// Function prototypes
MaxHeap* create_max_heap(int capacity);    // Create a new MaxHeap
void insert(MaxHeap* heap, int value);     // Insert a value into the heap
int extract_max(MaxHeap* heap);            // Extract the maximum value
int peek_max(MaxHeap* heap);               // Peek at the maximum value
void print_heap(MaxHeap* heap);            // Print the heap
void free_max_heap(MaxHeap* heap);         // Free memory

#endif // MAX_HEAP_H
