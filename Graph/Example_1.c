#include "graph.h"

// Create a new adjacency list node
AdjListNode* create_node(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with a given number of vertices
Graph* create_graph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (!graph) {
        printf("Memory allocation failed for graph.\n");
        exit(1);
    }

    graph->numVertices = numVertices;
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));
    if (!graph->array) {
        printf("Memory allocation failed for adjacency list.\n");
        free(graph);
        exit(1);
    }

    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Add an edge to the graph (undirected by default)
void add_edge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    AdjListNode* newNode = create_node(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src
    newNode = create_node(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Print the graph representation
void print_graph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjListNode* temp = graph->array[i].head;
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Free the memory allocated for the graph
void free_graph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        AdjListNode* temp = graph->array[i].head;
        while (temp) {
            AdjListNode* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    // Create a graph with 5 vertices
    int numVertices = 5;
    Graph* graph = create_graph(numVertices);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the adjacency list representation
    printf("Graph adjacency list:\n");
    print_graph(graph);

    // Free the graph's memory
    free_graph(graph);

    return 0;
}
