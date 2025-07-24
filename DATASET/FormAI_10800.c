//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROW 10
#define COL 10

// The coordinates of a node on the map
typedef struct{
    int row;
    int col;
} Node;

// The basic structure of a node on the map
typedef struct{
    Node pos;           // the coordinates of the node
    int gScore;         // the cost from start to the current node
    int fScore;         // the total cost from start to the goal through the current node
    Node parent;        // the parent node of the current node
    int isOpen;         // a boolean to keep track of whether the node is open
    int isClosed;       // a boolean to keep track of whether the node is closed
} MapNode;

// The Map structure
typedef struct{
    MapNode nodes[ROW][COL];    // the nodes on the map
    Node start;                 // the starting position
    Node goal;                  // the goal position
} Map;

// Heuristic function: The euclidean distance between two nodes
float heuristic(Node p1, Node p2){
    return sqrt(pow((p1.row - p2.row), 2) + pow((p1.col - p2.col), 2));
}

// The main A* pathfinding function
void AStar(Map* map){
    // Set the starting node's gScore and fScore to 0
    map->nodes[map->start.row][map->start.col].gScore = 0;
    map->nodes[map->start.row][map->start.col].fScore = heuristic(map->start, map->goal);
    
    // Create an array to store the open nodes
    MapNode openList[ROW * COL];
    int openCount = 1;
    openList[0] = map->nodes[map->start.row][map->start.col];
    openList[0].isOpen = 1;

    // Create an array to store the closed nodes
    MapNode closedList[ROW][COL];
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
            closedList[row][col].isClosed = 0;
        }
    }

    // Iterate while the open list is not empty
    while(openCount > 0){
        // Find the node with the smallest fScore in the open list
        int smallestIndex = 0;
        for(int i = 0; i < openCount; i++){
            if(openList[i].fScore < openList[smallestIndex].fScore){
                smallestIndex = i;
            }
        }

        // Get the current node
        MapNode current = openList[smallestIndex];

        // If the current node is the goal, break out of the loop
        if(current.pos.row == map->goal.row && current.pos.col == map->goal.col){
            break;
        }

        // Remove the current node from the open list and add it to the closed list
        current.isOpen = 0;
        current.isClosed = 1;
        closedList[current.pos.row][current.pos.col] = current;

        // Look at the neighbors of the current node
        for(int r = -1; r <= 1; r++){
            for(int c = -1; c <= 1; c++){
                // Skip the current node
                if(r == 0 && c == 0){
                    continue;
                }

                // Get the coordinates of the neighbor
                int newRow = current.pos.row + r;
                int newCol = current.pos.col + c;

                // If the neighbor is not on the map, skip it
                if(newRow < 0 || newCol < 0 || newRow >= ROW || newCol >= COL){
                    continue;
                }

                // If the neighbor is closed, skip it
                if(closedList[newRow][newCol].isClosed){
                    continue;
                }

                // Calculate the gScore of the neighbor
                int neighborGScore = current.gScore + 1;

                // Get the neighbor node
                MapNode neighbor = map->nodes[newRow][newCol];

                // If the neighbor is not in the open list, add it
                if(!neighbor.isOpen){
                    neighbor.gScore = neighborGScore;
                    neighbor.fScore = neighborGScore + heuristic(neighbor.pos, map->goal);
                    neighbor.parent = current.pos;
                    neighbor.isOpen = 1;
                    openList[openCount] = neighbor;
                    openCount++;
                }
                // If the neighbor is in the open list, check if this path is shorter
                else if(neighborGScore < neighbor.gScore){
                    neighbor.gScore = neighborGScore;
                    neighbor.fScore = neighborGScore + heuristic(neighbor.pos, map->goal);
                    neighbor.parent = current.pos;
                }
            }
        }
    }

    // Print the path from the start to the goal
    MapNode current = closedList[map->goal.row][map->goal.col];
    while((current.pos.row != map->start.row || current.pos.col != map->start.col)){
        printf("(%d,%d) ", current.pos.row, current.pos.col);
        current = closedList[current.parent.row][current.parent.col];
    }
    printf("(%d,%d) ", map->start.row, map->start.col);
}

// The main function
int main(){
    // Create the map
    Map map;
    for(int row = 0; row < ROW; row++){
        for(int col = 0; col < COL; col++){
            map.nodes[row][col].pos.row = row;
            map.nodes[row][col].pos.col = col;
            map.nodes[row][col].gScore = 99999;
            map.nodes[row][col].isOpen = 0;
            map.nodes[row][col].isClosed = 0;
        }
    }

    // Define the start and goal positions
    map.start.row = 0;
    map.start.col = 0;
    map.goal.row = 9;
    map.goal.col = 9;

    // Add some obstacles to the map
    map.nodes[1][1].isClosed = 1;
    map.nodes[1][2].isClosed = 1;
    map.nodes[1][3].isClosed = 1;
    map.nodes[2][3].isClosed = 1;
    map.nodes[3][3].isClosed = 1;
    map.nodes[4][3].isClosed = 1;
    map.nodes[5][3].isClosed = 1;
    map.nodes[6][3].isClosed = 1;
    map.nodes[7][3].isClosed = 1;
    map.nodes[8][3].isClosed = 1;
    map.nodes[4][4].isClosed = 1;
    map.nodes[4][5].isClosed = 1;
    map.nodes[4][6].isClosed = 1;
    map.nodes[4][7].isClosed = 1;
    map.nodes[4][8].isClosed = 1;
    map.nodes[4][9].isClosed = 1;

    // Run the A* algorithm
    AStar(&map);

    return 0;
}