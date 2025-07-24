//FormAI DATASET v1.0 Category: Graph representation ; Style: enthusiastic
#include <stdio.h>
#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX]; 

void add_edge(int v1, int v2) 
{ 
    graph[v1][v2] = 1; 
    graph[v2][v1] = 1; 
} 

void print_graph() 
{ 
    int i, j; 
    for (i = 0; i < MAX_VERTEX; i++) { 
        for (j = 0; j < MAX_VERTEX; j++) { 
            printf("%d ", graph[i][j]); 
        } 
        printf("\n"); 
    } 
} 

int main() 
{ 
    int num_vertices = 6; 
    
    printf("Welcome to Graph Representation Example Program\n\n");
    
    printf("Adding edges to graph:\n");
    add_edge(0, 1); 
    add_edge(0, 2); 
    add_edge(1, 3); 
    add_edge(2, 4); 
    add_edge(3, 4); 
    add_edge(4, 5); 
    
    printf("\nPrinting Graph:\n");
    print_graph(); 
    
    printf("\nThank you for using the Graph Representation Example Program");
    return 0; 
}