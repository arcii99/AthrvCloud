//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {         // sample maze case
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},  
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},  
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},  
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},  
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},  
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},  
    {1, 0, 0, 0, 1, 0, 0, 1, 0, 1},  
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},  
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},  
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  
}; 

int path[ROW][COL];    // table to store the shortest distance of each position to the starting point

int distance = 0; // Variable to keep track of the current shortest distance

void findMinDist(int x, int y, int dist){ // function to find the minimum distance between the given position and the starting point
    if(maze[x][y] == 0) return; // Is the given coordinate a wall?
    if(path[x][y] <= dist) return; // Have we already found a shorter distance to this spot?

    path[x][y] = dist; // Store the new shortest distance
    if(x == 0 && y == 0){ // Are we at the starting point?
        distance = dist; // Store the total shortest distance
        return;
    }

    if(x > 0) findMinDist(x-1, y, dist+1); // Check north
    if(y > 0) findMinDist(x, y-1, dist+1); // Check west
    if(x < ROW-1) findMinDist(x+1, y, dist+1); // Check south
    if(y < COL-1) findMinDist(x, y+1, dist+1); // Check east
}

void printShortestPath(){ // function to print the shortest path to the starting point
    int x = 0, y = 0; // Starting point
    printf("Shortest path:\n(%d,%d)\n", x, y); // Print starting point

    while(x != ROW-1 || y != COL-1){ // Keep going until we reach the end point
        if(x > 0 && path[x-1][y] < path[x][y]){ // Check north
            x--;
            printf("(%d,%d)\n", x, y);
        }
        else if(y > 0 && path[x][y-1] < path[x][y]){ // Check west
            y--;
            printf("(%d,%d)\n", x, y);
        }
        else if(x < ROW-1 && path[x+1][y] < path[x][y]){ // Check south
            x++;
            printf("(%d,%d)\n", x, y);
        }
        else{ // Must be east
            y++;
            printf("(%d,%d)\n", x, y);
        }
    }

    printf("Total distance: %d\n", distance); // Print total distance
}

int main(){
    // Initialize the path table with maximum possible distance from starting point
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            path[i][j] = ROW*COL;
        }
    }

    findMinDist(ROW-1, COL-1, 0); // Start the recursive function to find the shortest path
    printShortestPath(); // Print the shortest path

    return 0;
}