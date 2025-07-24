//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 15

//Helper function to find minimum of two numbers
int min(int a, int b){
    return (a<b)? a: b;
}

//Structure to hold a point in a board
struct Point{
    int x, y;
};

//Function to check if a given point is inside the board
bool isInsideBoard(int x, int y){
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

//Function to check if a point is obstacle or not
bool isObstacle(int board[ROW][COL], int x, int y){
    return (board[x][y] == 1);
}

// Function to check if a given point is already in the open list 
bool isInOpenList(struct Point openList[], struct Point p, int openListSize){
    for(int i=0; i<openListSize; i++){
        if(openList[i].x == p.x && openList[i].y == p.y)
            return true;
    }
    return false;
}

// Function to check if a given point is already in the closed list
bool isInClosedList(struct Point closedList[], struct Point p, int closedListSize){
    for(int i=0; i<closedListSize; i++){
        if(closedList[i].x == p.x && closedList[i].y == p.y)
            return true;
    }
    return false;
}

//Function to calculate the heuristic from a given point to the goal
int calculateHeuristic(struct Point startPoint, struct Point endPoint){
    return abs(startPoint.x - endPoint.x) + abs(startPoint.y - endPoint.y);
}

//Function to print the path from start to end
void printPath(struct Point cameFrom[][COL], struct Point endPoint){
    //Base case
    if(cameFrom[endPoint.x][endPoint.y].x == -1 && cameFrom[endPoint.x][endPoint.y].y == -1)
        return;
    
    printPath(cameFrom, cameFrom[endPoint.x][endPoint.y]);
    printf("(%d,%d) -> ", endPoint.x, endPoint.y);
}

//Function to find the shortest path
void findShortestPath(int board[ROW][COL], struct Point startPoint, struct Point endPoint){
    //If the starting point and ending point are the same, then no need to run the algorithm
    if(startPoint.x == endPoint.x && startPoint.y == endPoint.y){
        printf("Start point and End point are the same. No need to find any path.\n");
        return;
    }

    //Arrays to hold the open and closed list of points
    struct Point openList[ROW*COL], closedList[ROW*COL];
    //Variable to hold the size of open and closed list
    int openListSize = 0, closedListSize = 0;

    //Array to hold the parent point for each point
    struct Point cameFrom[ROW][COL];
    //Initialize cameFrom to (-1,-1) to denote that no parent is assigned yet
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            cameFrom[i][j].x = cameFrom[i][j].y = -1;

    //Push the starting point to the open list
    openList[openListSize++] = startPoint;

    //Variable to hold the cost from start to each point
    int gCost[ROW][COL];
    //Initialize gCost to infinity for all points except start point
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(i == startPoint.x && j == startPoint.y)
                gCost[i][j] = 0;
            else
                gCost[i][j] = ROW*COL;
        }
    }

    //Variable to hold the cost from start to end point via a given point
    int fCost[ROW][COL];
    //Initialize fCost to infinity for all points except start point
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            if(i == startPoint.x && j == startPoint.y)
                fCost[i][j] = calculateHeuristic(startPoint, endPoint);
            else
                fCost[i][j] = ROW*COL;
        }
    }

    while(openListSize > 0){
        //Find the point with the minimum fCost from openList and remove it from there
        int minFCost = ROW*COL+1, minFCostIndex = -1;
        for(int i=0; i<openListSize; i++){
            if(fCost[openList[i].x][openList[i].y] < minFCost){
                minFCost = fCost[openList[i].x][openList[i].y];
                minFCostIndex = i;
            }
        }

        //If the point with minimum fCost is the end point, then print the path and return
        if(openList[minFCostIndex].x == endPoint.x && openList[minFCostIndex].y == endPoint.y){
            printf("Found the shortest path from start(%d,%d) to end(%d,%d).\n", startPoint.x, startPoint.y, endPoint.x, endPoint.y);
            printf("Shortest Path : ");
            printPath(cameFrom, endPoint);
            printf("\n");
            return;
        }

        //Remove the point with minimum fCost from openList and push it to closedList
        struct Point currentPoint = openList[minFCostIndex];
        openList[minFCostIndex] = openList[--openListSize];
        closedList[closedListSize++] = currentPoint;

        //Find all the neighbors of this point
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int newX = currentPoint.x + dx[i], newY = currentPoint.y + dy[i];
            if(!isInsideBoard(newX, newY) || isObstacle(board, newX, newY) || isInClosedList(closedList, (struct Point){newX, newY}, closedListSize))
                continue;

            int tentative_gCost = gCost[currentPoint.x][currentPoint.y] + 1;
            if(!isInOpenList(openList, (struct Point){newX, newY}, openListSize) || tentative_gCost < gCost[newX][newY]){
                cameFrom[newX][newY] = currentPoint;
                gCost[newX][newY] = tentative_gCost;
                fCost[newX][newY] = gCost[newX][newY] + calculateHeuristic((struct Point){newX, newY}, endPoint);

                if(!isInOpenList(openList, (struct Point){newX, newY}, openListSize))
                    openList[openListSize++] = (struct Point){newX, newY};
            }
        }
    }

    printf("Unable to find any path from start(%d,%d) to end(%d,%d).\n", startPoint.x, startPoint.y, endPoint.x, endPoint.y);
}

int main(){
    //Initialize the board where 0 denotes a free point and 1 denotes an obstacle
    int board[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    //Initialize start and end points
    struct Point startPoint = {0,0}, endPoint = {9,14};

    //Find the shortest path
    findShortestPath(board, startPoint, endPoint);

    return 0;
}