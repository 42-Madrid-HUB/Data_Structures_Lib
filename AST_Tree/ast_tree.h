#ifndef AST_TREE_H
#define AST_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Enum to represent the type of operation or value in the AST
typedef enum {
    AST_OP_ADD,         // Addition
    AST_OP_SUBTRACT,    // Subtraction
    AST_OP_MULTIPLY,    // Multiplication
    AST_OP_DIVIDE,      // Division
    AST_OP_LITERAL      // Literal value (number)
} AstNodeType;

// Structure representing a node in the AST
typedef struct ASTNode {
    AstNodeType type;     // Type of the node (operation or literal)
    union {
        int value;        // Used if the node is a literal
        struct {          // Used if the node is an operation
            struct ASTNode* left;
            struct ASTNode* right;
        };
    };
} ASTNode;

// Function prototypes
ASTNode* create_literal_node(int value);                 // Create a literal node
ASTNode* create_operator_node(AstNodeType type, ASTNode* left, ASTNode* right); // Create an operation node
void print_ast(ASTNode* node);                            // Print the AST
void free_ast(ASTNode* node);                             // Free the memory of the AST

#endif // AST_TREE_H
