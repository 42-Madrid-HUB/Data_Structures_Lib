#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Node structure for storing key-value pairs
typedef struct HashNode {
    char* key;                   // Key (string)
    int value;                   // Value (integer for simplicity)
    struct HashNode* next;       // Pointer to the next node (for collision resolution)
} HashNode;

// Hash map structure
typedef struct HashMap {
    int size;                    // Number of buckets
    HashNode** table;            // Array of linked lists
} HashMap;

// Function prototypes
HashMap* create_hash_map(int size);          // Create a new hash map
unsigned int hash_function(const char* key, int size); // Hash function
void insert(HashMap* map, const char* key, int value); // Insert key-value pair
int search(HashMap* map, const char* key, int* value); // Search for a key
void delete_key(HashMap* map, const char* key);        // Delete a key-value pair
void print_hash_map(HashMap* map);                     // Print the hash map
void free_hash_map(HashMap* map);                      // Free the hash map memory

#endif // HASH_MAP_H
