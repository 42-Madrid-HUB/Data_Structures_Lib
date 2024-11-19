#include "HashMap.h"

// Create a new hash map with the given number of buckets
HashMap* create_hash_map(int size) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    if (!map) {
        printf("Memory allocation failed for hash map.\n");
        exit(1);
    }

    map->size = size;
    map->table = (HashNode**)calloc(size, sizeof(HashNode*));
    if (!map->table) {
        printf("Memory allocation failed for hash table.\n");
        free(map);
        exit(1);
    }

    return map;
}

// Hash function: simple modular hashing
unsigned int hash_function(const char* key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash * 31) + *key++; // Prime multiplier (31) for better distribution
    }
    return hash % size;
}

// Insert a key-value pair into the hash map
void insert(HashMap* map, const char* key, int value) {
    unsigned int index = hash_function(key, map->size);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (!newNode) {
        printf("Memory allocation failed for hash node.\n");
        exit(1);
    }

    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = map->table[index];
    map->table[index] = newNode; // Insert at the beginning of the list
}

// Search for a key in the hash map
int search(HashMap* map, const char* key, int* value) {
    unsigned int index = hash_function(key, map->size);
    HashNode* node = map->table[index];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (value) *value = node->value;
            return 1; // Key found
        }
        node = node->next;
    }
    return 0; // Key not found
}

// Delete a key-value pair from the hash map
void delete_key(HashMap* map, const char* key) {
    unsigned int index = hash_function(key, map->size);
    HashNode* node = map->table[index];
    HashNode* prev = NULL;

    while (node) {
        if (strcmp(node->key, key) == 0) {
            if (prev) {
                prev->next = node->next;
            } else {
                map->table[index] = node->next;
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

// Print the hash map (for debugging)
void print_hash_map(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        printf("Bucket %d: ", i);
        HashNode* node = map->table[i];
        while (node) {
            printf("(%s, %d) -> ", node->key, node->value);
            node = node->next;
        }
        printf("NULL\n");
    }
}

// Free all memory used by the hash map
void free_hash_map(HashMap* map) {
    for (int i = 0; i < map->size; i++) {
        HashNode* node = map->table[i];
        while (node) {
            HashNode* toDelete = node;
            node = node->next;
            free(toDelete->key);
            free(toDelete);
        }
    }
    free(map->table);
    free(map);
}

int main() {
    HashMap* map = create_hash_map(10);

    // Insert key-value pairs
    insert(map, "apple", 3);
    insert(map, "banana", 5);
    insert(map, "orange", 8);

    // Print the hash map
    printf("Hash map contents:\n");
    print_hash_map(map);

    // Search for keys
    int value;
    if (search(map, "banana", &value)) {
        printf("Found 'banana' with value: %d\n", value);
    } else {
        printf("'banana' not found.\n");
    }

    // Delete a key
    delete_key(map, "banana");

    // Print the hash map again
    printf("\nAfter deletion:\n");
    print_hash_map(map);

    // Free memory
    free_hash_map(map);

    return 0;
}
