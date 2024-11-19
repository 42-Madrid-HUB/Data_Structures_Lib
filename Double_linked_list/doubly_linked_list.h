#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
typedef struct Node {
    int data;               // Data of the node
    struct Node* next;      // Pointer to the next node
    struct Node* prev;      // Pointer to the previous node
} Node;

// Function prototypes
Node* create_node(int data);          // Create a new node
void insert_at_end(Node** head, int data); // Insert at the end of the list
void insert_at_beginning(Node** head, int data); // Insert at the beginning of the list
void delete_node(Node** head, int key);         // Delete a node by value
void print_list(Node* head);                  // Print the list
void free_list(Node* head);                   // Free the entire list

#endif // DOUBLY_LINKED_LIST_H
