#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26 // Assuming lowercase English alphabet

// Definition of a trie node
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE]; // Children nodes
    bool is_end_of_word;                      // Flag to mark the end of a word
} TrieNode;

// Function prototypes
TrieNode* create_node();                            // Create a new trie node
void insert(TrieNode* root, const char* word);      // Insert a word into the trie
bool search(TrieNode* root, const char* word);     // Search for a word in the trie
bool starts_with(TrieNode* root, const char* prefix); // Check if a prefix exists in the trie
void free_trie(TrieNode* root);                    // Free the memory used by the trie

#endif // TRIE_H
