#include "Max_Heap.h"

// Create a new MaxHeap
MaxHeap* create_max_heap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) {
        printf("Memory allocation failed for MaxHeap.\n");
        exit(1);
    }
    heap->array = (int*)malloc(capacity * sizeof(int));
    if (!heap->array) {
        printf("Memory allocation failed for heap array.\n");
        free(heap);
        exit(1);
    }
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Helper function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Helper function to heapify up
void heapify_up(MaxHeap* heap, int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap->array[index] > heap->array[parent]) {
        swap(&heap->array[index], &heap->array[parent]);
        heapify_up(heap, parent);
    }
}

// Insert a value into the MaxHeap
void insert(MaxHeap* heap, int value) {
    if (heap->size == heap->capacity) {
        printf("Heap overflow: Could not insert %d.\n", value);
        return;
    }

    heap->array[heap->size] = value;
    heap->size++;
    heapify_up(heap, heap->size - 1);
}

// Helper function to heapify down
void heapify_down(MaxHeap* heap, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->array[left] > heap->array[largest]) {
        largest = left;
    }

    if (right < heap->size && heap->array[right] > heap->array[largest]) {
        largest = right;
    }

    if (largest != index) {
        swap(&heap->array[index], &heap->array[largest]);
        heapify_down(heap, largest);
    }
}

// Extract the maximum value from the MaxHeap
int extract_max(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap underflow: No elements to extract.\n");
        return -1;
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);

    return max;
}

// Peek at the maximum value in the MaxHeap
int peek_max(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    return heap->array[0];
}

// Print the heap elements
void print_heap(MaxHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}

// Free the memory allocated for the MaxHeap
void free_max_heap(MaxHeap* heap) {
    free(heap->array);
    free(heap);
}

int main() {
    MaxHeap* heap = create_max_heap(10);

    // Insert elements
    insert(heap, 20);
    insert(heap, 15);
    insert(heap, 30);
    insert(heap, 10);
    insert(heap, 40);

    printf("Heap elements:\n");
    print_heap(heap);

    // Peek max
    printf("Maximum value: %d\n", peek_max(heap));

    // Extract max
    printf("Extracted max: %d\n", extract_max(heap));
    printf("Heap after extraction:\n");
    print_heap(heap);

    // Free memory
    free_max_heap(heap);

    return 0;
}
