#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

// Stack structure
typedef struct Stack {
    int *array;        // Array to hold stack elements
    int top;           // Index of the top element
    int capacity;      // Maximum capacity of the stack
} Stack;

// Function prototypes
Stack* create_stack(int capacity);       // Create a new stack
void push(Stack* stack, int value);      // Push a value onto the stack
int pop(Stack* stack);                   // Pop a value from the stack
int peek(Stack* stack);                  // Peek at the top element
int is_empty(Stack* stack);              // Check if the stack is empty
int is_full(Stack* stack);               // Check if the stack is full
void print_stack(Stack* stack);          // Print the elements of the stack
void free_stack(Stack* stack);           // Free the memory allocated for the stack

#endif // STACK_H
