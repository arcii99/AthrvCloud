//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

//Definitions
#define ROW 5
#define COLUMN 5
#define NUM_NODES 25

typedef struct{
    int x;
    int y;
    int g;
    int h;
    int f;
    int closed;
    int visited;
    int parent;
}Node;

//Functions Declaration
void initGrid();
void printGrid();
int getNumFromRowCol(int row, int col);
void getNodeCoordinates(int node, int *row, int *col);
int calculateH(int currNode, int destNode);
void calculateF(int node);
void addToOpenList(int node);
int pickNextNode();
void tracePath(int startNode, int endNode);
void aStar(int startNode, int endNode);

//Globals
Node grid[ROW][COLUMN];
int openList[NUM_NODES];
int openListCount = 0;

//Main function
int main(){
    initGrid();
    int startNode = getNumFromRowCol(1, 1); //Starting node
    int endNode = getNumFromRowCol(4, 3); //Ending node
    aStar(startNode, endNode);
    printf("Shortest Path Found! Path is the following:\n");
    tracePath(startNode, endNode);
    return 0;
}

//Initialize Grid
void initGrid(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            int nodeNum = getNumFromRowCol(i, j);
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].g = 0;
            grid[i][j].h = 0;
            grid[i][j].f = 0;
            grid[i][j].closed = 0;
            grid[i][j].visited = 0;
            grid[i][j].parent = -1;
            switch(nodeNum){
                case 1:
                case 2:
                case 3:
                case 11:
                case 12:
                case 13:
                case 14:
                case 16:
                case 17:
                case 18:
                case 22:
                case 23:
                case 24:
                case 25:
                    grid[i][j].h = 1;
                    break;
                default:
                    grid[i][j].h = 0;
                    break;
            }
        }
    }
}

//Printing Grid
void printGrid(){
    printf("Grid:\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            if(grid[i][j].visited == 1){
                printf("v ");
            }else if(grid[i][j].closed == 1){
                printf("c ");
            }else{
                printf("- ");
            }
        }
        printf("\n");
    }
}

//Get the Unique number of a node from the row and column
int getNumFromRowCol(int row, int col){
    return (row * COLUMN) + col;
}

//Find the row and column of a node from its unique number
void getNodeCoordinates(int node, int *row, int *col){
    *row = (int)node/COLUMN;
    *col = node % COLUMN;
}

//Calculate h Score of a node
int calculateH(int currNode, int destNode){
    int currRow, currCol, destRow, destCol, h;
    getNodeCoordinates(currNode, &currRow, &currCol);
    getNodeCoordinates(destNode, &destRow, &destCol);
    h = abs(destRow - currRow) + abs(destCol - currCol);
    return h;
}

//Calculate f Score of a node
void calculateF(int node){
    grid[node/COLUMN][node%COLUMN].f = grid[node/COLUMN][node%COLUMN].g + grid[node/COLUMN][node%COLUMN].h;
}

//Add a node to the open list
void addToOpenList(int node){
    openList[openListCount] = node;
    openListCount++;
}

//Pick the node with the lowest f to be the next node
int pickNextNode(){
    int node = -1;
    int minF = 1000000;
    int i;
    int bestNode = 0;
    for(i = 0; i < openListCount; i++){
        node = openList[i];
        if(grid[node/COLUMN][node%COLUMN].f < minF){
            bestNode = i;
            minF = grid[node/COLUMN][node%COLUMN].f;
        }
    }
    node = openList[bestNode];
    for(i = bestNode; i < openListCount-1; i++){
        openList[i] = openList[i+1];
    }
    openListCount--;
    return node;
}

//Trace path and print it
void tracePath(int startNode, int endNode){
    int currentNode = endNode;
    while(currentNode != startNode){
        printf("%d <- ", currentNode);
        currentNode = grid[currentNode/COLUMN][currentNode%COLUMN].parent;
    }
    printf("%d", currentNode);
}

//A Star Search Algorithm
void aStar(int startNode, int endNode){
    int currentNode = -1;
    int i;
    int neighborNode;
    //Add the starting node to the open list
    addToOpenList(startNode);
    //As long as we have nodes in the open list, keep searching
    while(openListCount > 0){
        //Pick the node with the lowest f
        currentNode = pickNextNode();
        //If the node is the destination, we have found the path
        if(currentNode == endNode){
            return;
        }
        //Mark the node as closed
        grid[currentNode/COLUMN][currentNode%COLUMN].closed = 1;
        //Calculate the f score of the node's neighbors
        for(i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                int row, col;
                getNodeCoordinates(currentNode, &row, &col);
                int newRow = row + i;
                int newCol = col + j;
                if(newRow < 0 || newRow >= ROW || newCol < 0 || newCol >= COLUMN){
                    continue;
                }
                neighborNode = getNumFromRowCol(newRow, newCol);
                //If the neighbor node is already closed, ignore
                if(grid[newRow][newCol].closed == 1){
                    continue;
                }
                //If the neighbor node is not blocked, calculate its f score
                if(grid[newRow][newCol].h != 0){
                    if(grid[newRow][newCol].visited != 1){
                        grid[newRow][newCol].visited = 1;
                        addToOpenList(neighborNode);
                        grid[newRow][newCol].parent = currentNode;
                        grid[newRow][newCol].g = grid[currentNode/COLUMN][currentNode%COLUMN].g + 1;
                        calculateF(neighborNode);
                    }else{
                        if(grid[currentNode/COLUMN][currentNode%COLUMN].g + 1 < grid[newRow][newCol].g){
                            grid[newRow][newCol].parent = currentNode;
                            grid[newRow][newCol].g = grid[currentNode/COLUMN][currentNode%COLUMN].g + 1;
                            calculateF(neighborNode);
                        }
                    }
                }
            }
        }
    }
    //If we reach here, there is no path from start node to end node
    printf("No path found!");
}