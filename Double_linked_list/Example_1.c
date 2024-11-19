#include "doubly_linked_list.h"

// Create a new node
Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Insert a node at the end of the list
void insert_at_end(Node** head, int data) {
    Node* new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node; // If the list is empty, the new node becomes the head
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }
    temp->next = new_node; // Link the last node to the new node
    new_node->prev = temp; // Set the previous pointer of the new node
}

// Insert a node at the beginning of the list
void insert_at_beginning(Node** head, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head;  // Point the new node to the current head
    if (*head != NULL) {
        (*head)->prev = new_node; // Set the previous pointer of the old head to the new node
    }
    *head = new_node; // The new node becomes the head of the list
}

// Delete a node by value (key)
void delete_node(Node** head, int key) {
    Node* temp = *head;
    // If the list is empty
    if (temp == NULL) return;

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) return;

    // If the node to delete is the head node
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // If the node to delete is not the head
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // Set the previous pointer of the next node
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next; // Set the next pointer of the previous node
    }
    free(temp); // Free the memory of the deleted node
}

// Print the list from head to tail
void print_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free the entire list
void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL; // Initialize an empty list

    // Insert elements at the end
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);

    // Insert an element at the beginning
    insert_at_beginning(&head, 5);

    // Print the list
    printf("Doubly Linked List: ");
    print_list(head);

    // Delete a node
    delete_node(&head, 20); // Delete the node with data 20
    printf("After deleting 20: ");
    print_list(head);

    // Free the list
    free_list(head);
    return 0;
}