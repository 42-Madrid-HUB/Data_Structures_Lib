#include "stack.h"

// Create a new stack
Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Memory allocation failed for Stack.\n");
        exit(1);
    }
    stack->array = (int*)malloc(capacity * sizeof(int));
    if (!stack->array) {
        printf("Memory allocation failed for stack array.\n");
        free(stack);
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;  // Stack is empty initially
    return stack;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack overflow: Could not push %d.\n", value);
        return;
    }
    stack->array[++stack->top] = value;  // Increment top and insert value
}

// Pop a value from the stack
int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow: No elements to pop.\n");
        return -1;  // Return an invalid value when the stack is empty
    }
    return stack->array[stack->top--];  // Return top element and decrement top
}

// Peek at the top element
int peek(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top];  // Return top element
}

// Check if the stack is empty
int is_empty(Stack* stack) {
    return stack->top == -1;
}

// Check if the stack is full
int is_full(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Print the elements of the stack
void print_stack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Free the memory allocated for the stack
void free_stack(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main() {
    Stack* stack = create_stack(5);  // Create a stack with capacity of 5

    // Push elements onto the stack
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    // Print the stack
    printf("Stack elements:\n");
    print_stack(stack);

    // Peek the top element
    printf("Top element: %d\n", peek(stack));

    // Pop an element from the stack
    printf("Popped element: %d\n", pop(stack));
    printf("Stack after pop:\n");
    print_stack(stack);

    // Free memory
    free_stack(stack);

    return 0;
}
