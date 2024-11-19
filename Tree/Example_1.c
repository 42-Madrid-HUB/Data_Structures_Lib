#include "tree.h"

// Create a new tree node with the specified value
TreeNode* create_node(int value) {
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (!new_node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Insert a new value into the binary tree
void insert(TreeNode** root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }
    if (value < (*root)->value) {
        insert(&((*root)->left), value);  // Insert into the left subtree
    } else {
        insert(&((*root)->right), value); // Insert into the right subtree
    }
}

// Search for a value in the binary tree
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;  // Found or end of tree
    }
    if (value < root->value) {
        return search(root->left, value); // Search in the left subtree
    } else {
        return search(root->right, value); // Search in the right subtree
    }
}

// Inorder traversal: Left, Root, Right
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

// Preorder traversal: Root, Left, Right
void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal: Left, Right, Root
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

// Free the memory used by the tree
void free_tree(TreeNode* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

#include "tree.h"

int main() {
    TreeNode* root = NULL;

    // Insert nodes into the tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    // Search for a value in the tree
    TreeNode* result = search(root, 40);
    if (result) {
        printf("Found value: %d\n", result->value);
    } else {
        printf("Value not found.\n");
    }

    // Print the tree in different traversals
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    // Free the tree memory
    free_tree(root);

    return 0;
}
