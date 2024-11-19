#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue {
    int *array;        // Pointer to the queue array
    int front;         // Index of the front element
    int rear;          // Index of the rear element
    int capacity;      // Maximum capacity of the queue
    int size;          // Current size of the queue
} Queue;

// Function prototypes
Queue* create_queue(int capacity);        // Create a new Queue
void enqueue(Queue* queue, int value);    // Insert a value into the queue
int dequeue(Queue* queue);                // Remove a value from the queue
int peek_front(Queue* queue);             // Peek at the front element
int is_empty(Queue* queue);               // Check if the queue is empty
int is_full(Queue* queue);                // Check if the queue is full
void print_queue(Queue* queue);           // Print the elements of the queue
void free_queue(Queue* queue);            // Free the queue

#endif // QUEUE_H
