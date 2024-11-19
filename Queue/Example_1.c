#include "queue.h"

// Create a new Queue
Queue* create_queue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation failed for Queue.\n");
        exit(1);
    }
    queue->array = (int*)malloc(capacity * sizeof(int));
    if (!queue->array) {
        printf("Memory allocation failed for queue array.\n");
        free(queue);
        exit(1);
    }
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

// Insert a value into the Queue (enqueue)
void enqueue(Queue* queue, int value) {
    if (queue->size == queue->capacity) {
        printf("Queue overflow: Could not insert %d.\n", value);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;  // Wrap around the rear index
    queue->array[queue->rear] = value;
    queue->size++;
}

// Remove a value from the Queue (dequeue)
int dequeue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue underflow: No elements to dequeue.\n");
        return -1;  // Return an invalid value when the queue is empty
    }
    int value = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;  // Wrap around the front index
    queue->size--;
    return value;
}

// Peek at the front element
int peek_front(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->array[queue->front];
}

// Check if the Queue is empty
int is_empty(Queue* queue) {
    return queue->size == 0;
}

// Check if the Queue is full
int is_full(Queue* queue) {
    return queue->size == queue->capacity;
}

// Print the elements of the Queue
void print_queue(Queue* queue) {
    if (queue->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    for (int i = 0; i < queue->size; i++) {
        printf("%d ", queue->array[(queue->front + i) % queue->capacity]);
    }
    printf("\n");
}

// Free the memory allocated for the Queue
void free_queue(Queue* queue) {
    free(queue->array);
    free(queue);
}

int main() {
    Queue* queue = create_queue(5);  // Create a queue with a capacity of 5

    // Enqueue elements
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    // Print the queue
    printf("Queue elements:\n");
    print_queue(queue);

    // Peek front element
    printf("Front element: %d\n", peek_front(queue));

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(queue));
    printf("Queue after dequeue:\n");
    print_queue(queue);

    // Free memory
    free_queue(queue);

    return 0;
}

