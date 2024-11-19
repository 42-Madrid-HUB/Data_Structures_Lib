#include "linked_list.h"

// Create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) { // Check for successful memory allocation
        printf("Memory allocation error.\n");
        exit(1);
    }
    new_node->data = data;  // Assign data
    new_node->next = NULL;  // Initialize next pointer to NULL
    return new_node;
}

// Insert a node at the beginning of the list
void insert_at_head(Node** head, int data) {
    Node* new_node = create_node(data); // Create a new node
    new_node->next = *head;            // Point the new node to the current head
    *head = new_node;                  // Update the head pointer
}

// Print the linked list
void print_list(Node* head) {
    Node* current = head;              // Start at the head
    while (current != NULL) {          // Traverse until the end of the list
        printf("%d -> ", current->data); // Print the node's data
        current = current->next;        // Move to the next node
    }
    printf("NULL\n"); // Indicate the end of the list
}

// Free all nodes in the list
void free_list(Node** head) {
    Node* current = *head;              // Start from the head
    while (current != NULL) {           // Traverse the list
        Node* temp = current;           // Save the current node
        current = current->next;        // Move to the next node
        free(temp);                     // Free the current node
    }
    *head = NULL; // Ensure the head pointer is null
}


int main() {
    Node* head = NULL; // Initialize an empty list

    // Add elements to the list
    insert_at_head(&head, 10); // Add 10 to the head
    insert_at_head(&head, 20); // Add 20 to the head
    insert_at_head(&head, 30); // Add 30 to the head

    // Print the list
    printf("Linked list: ");
    print_list(head);

    // Free the allocated memory
    free_list(&head);

    return 0;
}
