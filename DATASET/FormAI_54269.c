//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Defining the minimum number of rows and columns
#define ROW 10
#define COL 10

// Defining a structure for each node of the A* Algorithm
typedef struct node{
    // x and y are the coordinates of the node
    int x, y;

    // F, G and H are the three values used in A* Algorithm calculation
    int F, G, H;

    // parent_x, parent_y stores the coordinates of the parent node
    int parent_x, parent_y;
} node;

// Defining the start and end points of the path
node start = {0, 0};
node end = {9, 9};

// Defining the heuristic function to calculate H value for each node
int heuristic(node a, node b){
    return ((abs(a.x-b.x) + abs(a.y-b.y)));
}

// Defining the function to check whether a given node is valid to check 
// or not and also check whether the given node is within the boundaries
int isValid(int row, int col){
    return (row>=0) && (row<ROW) && (col>=0) && (col<COL);
}

// Function to check whether the given node is blocked or not
int isUnblocked(int grid[][COL], int row, int col){
    return (grid[row][col] == 1)? 1: 0;
}

// Function to check whether the destination node has been reached or not
int isDestination(int row, int col){
    return (row == end.x) && (col == end.y);
}

// Function to print the optimal path from start to end
void printPath(node map[][COL], node current){
    if(current.parent_x == -1 && current.parent_y == -1){
        printf("(%d, %d)", current.x, current.y);
        return;
    }
    printPath(map, map[current.parent_x][current.parent_y]);
    printf(" -> (%d, %d)", current.x, current.y);
}

// Function that implements A* algorithm
void AStarSearch(int grid[][COL], node map[][COL], node start, node end){
    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};

    // ClosedList is a boolean list that stores the information about wether the given node is closed or not
    int closedList[ROW][COL];

    // Initialize the closedList as false
    memset(closedList, 0, sizeof(closedList));

    // Initializing the starting node with the values
    int i = start.x, j = start.y;
    map[i][j] = (node){i, j, 0, 0, 0, 0};

    // Initialize the F and G values for starting node
    map[i][j].F = map[i][j].G = map[i][j].H = 0;

    // Creating an openList array that will store the valid nodes that can be checked
    int count = 0;
    node openList[ROW * COL];
    openList[count++] = map[i][j];

    // Set the value of foundDestination to false
    int foundDestination = 0;

    // Continue Loop until the openList is not empty
    while(count != 0){
        // Find the node with smallest F and pop it from the openList
        node current = openList[0];
        int currentIdx = 0;
        for(int i = 1; i < count; i++){
            if(openList[i].F < current.F){
                current = openList[i];
                currentIdx = i; 
            }
        }
        // Pop the minimum value node from the openList
        openList[currentIdx] = openList[--count];

        // Add the current node to the closedList
        closedList[current.x][current.y] = 1;

        // Exploring the neighbors of the current node
        for(int i = 0; i < 4; i++){
            int rowIdx = current.x + row[i];
            int colIdx = current.y + col[i];

            // Check whether the neighbor is valid and unblocked
            if(isValid(rowIdx, colIdx) == 1){
                // Check whether we have reached the destination
                if(isDestination(rowIdx, colIdx) == 1){
                    map[rowIdx][colIdx].parent_x = current.x;
                    map[rowIdx][colIdx].parent_y = current.y;
                    printf("The destination has been found.\n");
                    printPath(map, map[rowIdx][colIdx]);
                    foundDestination = 1;
                    return;
                }
                // Check whether the given node has not been already processed or closed
                else if(closedList[rowIdx][colIdx] == 0 && isUnblocked(grid, rowIdx, colIdx) == 1){
                    int G_new, H_new, F_new;
                    G_new = current.G + 1;
                    H_new = heuristic((node){rowIdx, colIdx}, end);
                    F_new = G_new + H_new;

                    // Check if the given node is already in the openList
                    for(int i = 0; i < count; i++){
                        if(openList[i].x == rowIdx && openList[i].y == colIdx){
                            if(openList[i].G > G_new){
                                openList[i].F = F_new;
                                openList[i].G = G_new;
                                openList[i].H = H_new;
                                openList[i].parent_x = current.x;
                                openList[i].parent_y = current.y;
                            }
                            break;
                        }
                    }
                    // If the given node is not in the openList, add it to the openList
                    if(i == count){
                        openList[count++] = (node){rowIdx, colIdx, F_new, G_new, H_new, current.x, current.y};
                        map[rowIdx][colIdx] = openList[count-1];
                    }
                }
            }
        }
    }
    if(foundDestination == 0){
        printf("The destination could not be reached.\n");
    }
}

// Main function
int main(){
    int grid[ROW][COL] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1}, 
                            {1, 1, 1, 0, 1, 1, 1, 0, 1, 1}, 
                            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1}, 
                            {0, 0, 1, 0, 1, 0, 0, 0, 0, 1}, 
                            {1, 1, 1, 0, 1, 1, 1, 0, 1, 0}, 
                            {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}, 
                            {1, 0, 0, 0, 0, 1, 0, 0, 0, 1}, 
                            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1}, 
                            {1, 1, 1, 0, 0, 0, 1, 0, 0, 1} , 
                            {0, 1, 0, 1, 1, 1, 1, 1, 1, 1}};

    // Creating the map that stores the properties of each node
    node map[ROW][COL];

    // Initializing the map with empty node values
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            map[i][j] = (node){i, j, INT_MAX, INT_MAX, INT_MAX, -1, -1};
        }
    }
    AStarSearch(grid, map, start, end);
    return 0;
}