#include "trie.h"

// Create a new trie node
TrieNode* create_node() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->is_end_of_word = false; // Initially, not the end of a word
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL; // Initialize all child pointers to NULL
    }
    return node;
}

// Insert a word into the trie
void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';  // Get the index of the character
        if (current->children[index] == NULL) {
            current->children[index] = create_node(); // Create node if doesn't exist
        }
        current = current->children[index]; // Move to the child node
        word++;
    }
    current->is_end_of_word = true; // Mark the end of the word
}

// Search for a word in the trie
bool search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    while (*word) {
        int index = *word - 'a';
        if (current->children[index] == NULL) {
            return false; // If the character doesn't exist, return false
        }
        current = current->children[index];
        word++;
    }
    return current != NULL && current->is_end_of_word; // Return true if it's the end of a word
}

// Check if a prefix exists in the trie
bool starts_with(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    while (*prefix) {
        int index = *prefix - 'a';
        if (current->children[index] == NULL) {
            return false; // If the prefix doesn't exist, return false
        }
        current = current->children[index];
        prefix++;
    }
    return true; // Return true if the prefix exists
}

// Free the memory used by the trie
void free_trie(TrieNode* root) {
    if (root == NULL) return;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            free_trie(root->children[i]); // Recursively free child nodes
        }
    }
    free(root);
}

int main() {
    TrieNode* root = create_node();

    // Insert words into the trie
    insert(root, "hello");
    insert(root, "hell");
    insert(root, "he");
    insert(root, "goodbye");

    // Search for words in the trie
    printf("Search 'hello': %s\n", search(root, "hello") ? "Found" : "Not Found");
    printf("Search 'hell': %s\n", search(root, "hell") ? "Found" : "Not Found");
    printf("Search 'he': %s\n", search(root, "he") ? "Found" : "Not Found");
    printf("Search 'good': %s\n", search(root, "good") ? "Found" : "Not Found");
    
    // Check for prefix existence
    printf("Prefix 'he' exists: %s\n", starts_with(root, "he") ? "Yes" : "No");
    printf("Prefix 'good': %s\n", starts_with(root, "good") ? "Yes" : "No");

    // Free the trie memory
    free_trie(root);

    return 0;
}