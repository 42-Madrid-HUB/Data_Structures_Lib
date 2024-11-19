#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the tree
typedef struct TreeNode {
    int value;                 // Value stored in the node
    struct TreeNode* left;     // Pointer to left child
    struct TreeNode* right;    // Pointer to right child
} TreeNode;

// Function prototypes
TreeNode* create_node(int value);            // Create a new node
void insert(TreeNode** root, int value);     // Insert a value into the tree
TreeNode* search(TreeNode* root, int value); // Search for a value in the tree
void inorder(TreeNode* root);                // Inorder traversal
void preorder(TreeNode* root);               // Preorder traversal
void postorder(TreeNode* root);              // Postorder traversal
void free_tree(TreeNode* root);              // Free the tree

#endif // TREE_H
