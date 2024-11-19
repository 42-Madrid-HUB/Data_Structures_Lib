#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

// Node definition
typedef struct Node {
    int data;              // Value stored in the node
    struct Node* next;     // Pointer to the next node
} Node;

// Function prototypes
Node* create_node(int data);            // Create a new node
void insert_at_head(Node** head, int data);  // Insert a node at the beginning
void print_list(Node* head);            // Print the linked list
void free_list(Node** head);            // Free all memory used by the list

#endif // LINKED_LIST_H
