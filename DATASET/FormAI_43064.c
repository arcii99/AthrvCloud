//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

int graph[MAX][MAX], num_of_vertices, num_of_colors;

/* Function to check if a vertex can be colored with given color */
int isSafe(int vertex, int color[], int c) {
    for(int i=0; i<num_of_vertices; i++) {
        if(graph[vertex][i] && color[i] == c) 
            return 0;
    }
    return 1;
}

/* Function to solve graph coloring problem using backtracking*/
int graphColoring(int color[], int vertex) {
    if(vertex == num_of_vertices) 
        return 1;

    for(int i=1; i<=num_of_colors; i++) {
        if(isSafe(vertex, color, i)) {
            color[vertex] = i;
            if(graphColoring(color, vertex+1))
                return 1;
            color[vertex] = 0;
        }
    }
    return 0;
}

/* Function to generate a random graph */
void generateGraph() {
    srand(time(0));
    for(int i=0; i<num_of_vertices; i++) {
        for(int j=0; j<num_of_vertices; j++) {
            if(i == j)
                graph[i][j] = 0;
            else 
                graph[i][j] = graph[j][i] = rand() % 2;
        }
    }
}

/* Function to print the graph */
void printGraph() {
    printf("The graph is:\n");
    for(int i=0; i<num_of_vertices; i++) {
        for(int j=0; j<num_of_vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &num_of_vertices);
    if(num_of_vertices > MAX) {
        printf("Error: Number of vertices out of range.\n");
        exit(1);
    }

    printf("Enter the number of colors: ");
    scanf("%d", &num_of_colors);

    generateGraph();
    printGraph();

    int color[num_of_vertices];

    if(graphColoring(color, 0)) {
        printf("Solution exists!\n");
        printf("The vertex colors are:\n");
        for(int i=0; i<num_of_vertices; i++) 
            printf("%d ", color[i]);
        printf("\n");
    }
    else {
        printf("Solution does not exist.\n");
    }

    return 0;
}