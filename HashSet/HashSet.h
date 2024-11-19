#ifndef HASH_SET_H
#define HASH_SET_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Node structure for each element in the HashSet
typedef struct HashSetNode {
    char* key;                  // The key (string)
    struct HashSetNode* next;   // Pointer to the next node (for collision resolution)
} HashSetNode;

// HashSet structure
typedef struct HashSet {
    int size;                   // Number of buckets
    HashSetNode** table;        // Array of linked lists
} HashSet;

// Function prototypes
HashSet* create_hash_set(int size);             // Create a new HashSet
unsigned int hash_function(const char* key, int size); // Hash function
void add(HashSet* set, const char* key);        // Add an element to the HashSet
int contains(HashSet* set, const char* key);    // Check if an element exists
void remove_key(HashSet* set, const char* key); // Remove an element from the HashSet
void print_hash_set(HashSet* set);              // Print the HashSet
void free_hash_set(HashSet* set);               // Free memory of the HashSet

#endif // HASH_SET_H
