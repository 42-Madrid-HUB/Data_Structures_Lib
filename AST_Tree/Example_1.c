#include "ast_tree.h"

// Create a node representing a literal value
ASTNode* create_literal_node(int value) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->type = AST_OP_LITERAL;
    node->value = value;
    return node;
}

// Create a node representing an operator with two operands (left and right)
ASTNode* create_operator_node(AstNodeType type, ASTNode* left, ASTNode* right) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    if (!node) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

// Print the AST in a simple notation
void print_ast(ASTNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->type == AST_OP_LITERAL) {
        printf("%d ", node->value); // Print the value of a literal node
    } else {
        printf("(");
        print_ast(node->left); // Recursively print the left operand
        switch (node->type) {
            case AST_OP_ADD: printf("+"); break;
            case AST_OP_SUBTRACT: printf("-"); break;
            case AST_OP_MULTIPLY: printf("*"); break;
            case AST_OP_DIVIDE: printf("/"); break;
            default: break;
        }
        print_ast(node->right); // Recursively print the right operand
        printf(")");
    }
}

// Free the memory of the AST
void free_ast(ASTNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->type != AST_OP_LITERAL) {
        free_ast(node->left);   // Free the left operand
        free_ast(node->right);  // Free the right operand
    }
    free(node);  // Free the current node
}

#include "ast_tree.h"

int main() {
    // Create a simple AST for the expression (3 + 5) * 2
    ASTNode* node1 = create_literal_node(3);  // Literal 3
    ASTNode* node2 = create_literal_node(5);  // Literal 5
    ASTNode* addNode = create_operator_node(AST_OP_ADD, node1, node2);  // 3 + 5

    ASTNode* node3 = create_literal_node(2);  // Literal 2
    ASTNode* mulNode = create_operator_node(AST_OP_MULTIPLY, addNode, node3);  // (3 + 5) * 2

    // Print the AST
    printf("AST representation: ");
    print_ast(mulNode);
    printf("\n");

    // Free the AST
    free_ast(mulNode);

    return 0;
}
