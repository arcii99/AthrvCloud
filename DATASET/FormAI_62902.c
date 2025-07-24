//FormAI DATASET v1.0 Category: Graph representation ; Style: mind-bending
#include <stdio.h>

int main() {

    // Creating the vertices of the graph
    int vertexCount = 7;
    char vertices[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    // Creating an adjacency matrix to represent the edges between the vertices
    int adjacencyMatrix[vertexCount][vertexCount];
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[0][2] = 1;
    adjacencyMatrix[1][0] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[1][4] = 1;
    adjacencyMatrix[2][0] = 1;
    adjacencyMatrix[2][4] = 1;
    adjacencyMatrix[3][1] = 1;
    adjacencyMatrix[4][1] = 1;
    adjacencyMatrix[4][2] = 1;
    adjacencyMatrix[5][6] = 1;
    adjacencyMatrix[6][5] = 1;

    // Printing out the graph using ASCII art
    printf("        %c\n", vertices[0]);
    printf("       / \\ \n");
    printf("      /   \\ \n");
    printf("     /     \\ \n");
    printf("    %c       %c\n", vertices[1], vertices[2]);
    printf("   / \\     / \\\n");
    printf("  /   \\   /   \\\n");
    printf(" %c     %c %c     %c\n", vertices[3], vertices[4], vertices[4], vertices[2]);
    printf("        |\n");
    printf("        |\n");
    printf("        %c\n", vertices[5]);
    printf("        |\n");
    printf("        |\n");
    printf("        %c\n", vertices[6]);

    return 0;
}