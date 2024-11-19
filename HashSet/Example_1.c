#include "HashSet.h"

// Create a new HashSet
HashSet* create_hash_set(int size) {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    if (!set) {
        printf("Memory allocation failed for HashSet.\n");
        exit(1);
    }

    set->size = size;
    set->table = (HashSetNode**)calloc(size, sizeof(HashSetNode*));
    if (!set->table) {
        printf("Memory allocation failed for HashSet table.\n");
        free(set);
        exit(1);
    }

    return set;
}

// Hash function
unsigned int hash_function(const char* key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++; // Prime multiplier (31) for better distribution
    }
    return hash % size;
}

// Add an element to the HashSet
void add(HashSet* set, const char* key) {
    unsigned int index = hash_function(key, set->size);
    HashSetNode* node = set->table[index];

    // Check if the key already exists
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return; // Key already exists, do nothing
        }
        node = node->next;
    }

    // Key does not exist, create a new node
    HashSetNode* newNode = (HashSetNode*)malloc(sizeof(HashSetNode));
    if (!newNode) {
        printf("Memory allocation failed for HashSet node.\n");
        exit(1);
    }

    newNode->key = strdup(key);
    newNode->next = set->table[index];
    set->table[index] = newNode; // Insert at the beginning of the list
}

// Check if an element exists in the HashSet
int contains(HashSet* set, const char* key) {
    unsigned int index = hash_function(key, set->size);
    HashSetNode* node = set->table[index];

    while (node) {
        if (strcmp(node->key, key) == 0) {
            return 1; // Key found
        }
        node = node->next;
    }
    return 0; // Key not found
}

// Remove an element from the HashSet
void remove_key(HashSet* set, const char* key) {
    unsigned int index = hash_function(key, set->size);
    HashSetNode* node = set->table[index];
    HashSetNode* prev = NULL;

    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                set->table[index] = node->next;
            }
            free(node->key);
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
    printf("Key '%s' not found.\n", key);
}

// Print the HashSet
void print_hash_set(HashSet* set) {
    for (int i = 0; i < set->size; i++) {
        printf("Bucket %d: ", i);
        HashSetNode* node = set->table[i];
        while (node) {
            printf("%s -> ", node->key);
            node = node->next;
        }
        printf("NULL\n");
    }
}

// Free memory of the HashSet
void free_hash_set(HashSet* set) {
    for (int i = 0; i < set->size; i++) {
        HashSetNode* node = set->table[i];
        while (node) {
            HashSetNode* toDelete = node;
            node = node->next;
            free(toDelete->key);
            free(toDelete);
        }
    }
    free(set->table);
    free(set);
}

int main() {
    HashSet* set = create_hash_set(10);

    // Add elements to the set
    add(set, "apple");
    add(set, "banana");
    add(set, "cherry");

    // Print the HashSet
    printf("HashSet contents:\n");
    print_hash_set(set);

    // Check if elements exist
    printf("\nContains 'banana': %s\n", contains(set, "banana") ? "Yes" : "No");
    printf("Contains 'grape': %s\n", contains(set, "grape") ? "Yes" : "No");

    // Remove an element
    remove_key(set, "banana");
    printf("\nAfter removing 'banana':\n");
    print_hash_set(set);

    // Free memory
    free_hash_set(set);

    return 0;
}
