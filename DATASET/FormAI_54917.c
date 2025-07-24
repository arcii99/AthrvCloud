//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// An A* Algorithm Node
typedef struct node {
    int row, col;
    int f, g, h;
    bool blocked;
    struct node* parent;
} Node;

// The A* Algorithm
Node* A_Star(Node* start, Node* target, Node* graph[ROW][COL])
{
    // Open List initialization
    Node* openList[ROW*COL];
    int openListSize = 0;
    
    // Closed List initialization
    bool closedList[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            closedList[i][j] = false;
        }
    }

    // Add start node to the open list
    openList[0] = start;
    openListSize++;

    while (openListSize > 0) {
        // Find the node with the smallest f value in the open list
        int smallestF = openList[0]->f;
        int index = 0;
        for (int i = 1; i < openListSize; i++) {
            if (openList[i]->f < smallestF) {
                smallestF = openList[i]->f;
                index = i;
            }
        }

        // Remove it from the open list
        Node* current = openList[index];
        openListSize--;
        openList[index] = openList[openListSize];

        // If the current node is the target node, return it
        if (current == target) {
            return current;
        }

        // Mark the current node as visited
        closedList[current->row][current->col] = true;

        // Check the eight neighboring nodes
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int newRow = current->row + i;
                int newCol = current->col + j;

                // Check if the neighboring node is within the grid
                if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL) {

                    // Check if the neighboring node is blocked or has been visited before
                    if (!graph[newRow][newCol]->blocked && !closedList[newRow][newCol]) {

                        // Calculate the new g value
                        int newG = current->g + 1;

                        // Calculate the new h value (heuristic)
                        int newH = abs(newRow - target->row) + abs(newCol - target->col);

                        // Calculate the new f value
                        int newF = newG + newH;

                        // If the neighboring node is not in the open list, add it to the open list
                        // Set its f, g, and h values, and set its parent to the current node
                        if (!graph[newRow][newCol]->parent) {
                            graph[newRow][newCol]->f = newF;
                            graph[newRow][newCol]->g = newG;
                            graph[newRow][newCol]->h = newH;
                            graph[newRow][newCol]->parent = current;
                            openList[openListSize] = graph[newRow][newCol];
                            openListSize++;
                        }
                        // If the neighboring node is already in the open list, update its f, g, and h values
                        // if the new f value is lower than its current f value
                        else if (newF < graph[newRow][newCol]->f) {
                            graph[newRow][newCol]->f = newF;
                            graph[newRow][newCol]->g = newG;
                            graph[newRow][newCol]->h = newH;
                            graph[newRow][newCol]->parent = current;
                        }
                    }
                }
            }
        }
    }

    // If the target node is not found, return NULL
    return NULL;
}

// Create a grid
void createGrid(Node* graph[ROW][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            graph[i][j] = (Node*)malloc(sizeof(Node));
            graph[i][j]->row = i;
            graph[i][j]->col = j;
            graph[i][j]->f = 0;
            graph[i][j]->g = 0;
            graph[i][j]->h = 0;
            graph[i][j]->blocked = false;
            graph[i][j]->parent = NULL;

            // Add some obstacles
            if (i == 3 && j >= 3 && j <= 7) {
                graph[i][j]->blocked = true;
            }
            if (i == 6 && j >= 2 && j <= 6) {
                graph[i][j]->blocked = true;
            }
            if (i == 8 && j >= 5 && j <= 8) {
                graph[i][j]->blocked = true;
            }
        }
    }
}

// Print the grid with the path
void printGrid(Node* graph[ROW][COL], Node* path)
{
    printf("   ");
    for (int j = 0; j < COL; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < ROW; i++) {
        printf("%02d ", i);
        for (int j = 0; j < COL; j++) {
            if (graph[i][j]->blocked) {
                printf("X ");
            }
            else if (path && path == graph[i][j]) {
                printf("* ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// The main function
int main()
{
    Node* graph[ROW][COL];
    createGrid(graph);

    Node* start = graph[0][0];
    Node* target = graph[9][9];
    Node* path = A_Star(start, target, graph);

    if (path) {
        printf("Path found!\n");
        printGrid(graph, path);
    }
    else {
        printf("Path not found.\n");
    }

    return 0;
}