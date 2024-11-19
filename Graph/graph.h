#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
typedef struct AdjListNode {
    int dest;                        // Destination vertex
    struct AdjListNode* next;        // Pointer to the next node
} AdjListNode;

// Structure for an adjacency list
typedef struct AdjList {
    AdjListNode* head;               // Pointer to the head of the list
} AdjList;

// Structure for a graph
typedef struct Graph {
    int numVertices;                 // Number of vertices
    AdjList* array;                  // Array of adjacency lists
} Graph;

// Function prototypes
Graph* create_graph(int numVertices);
void add_edge(Graph* graph, int src, int dest);
void print_graph(Graph* graph);
void free_graph(Graph* graph);

#endif // GRAPH_H
