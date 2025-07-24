//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROW 10
#define COL 10


bool isOpen(int row, int col, int maze[][COL], int visited[][COL]){
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1 && visited[row][col] == 0){
        return true;
    }
    else{
        return false;
    }
}


int calculateHeuristic(int currentX, int currentY, int endX, int endY){
    int dx = abs(currentX - endX);
    int dy = abs(currentY - endY);
    int heuristic = sqrt(pow(dx,2) + pow(dy,2));
    return heuristic;
}


void aStarPathfinding(int maze[][COL], int startX, int startY, int endX, int endY){
    
    int visited[ROW][COL] = {0};
    int cost[ROW][COL] = {0};
    int parent[ROW][COL] = {0};
    
    int xMoves[] = {-1, 0, 1, 0};
    int yMoves[] = {0, 1, 0, -1};
    
    bool foundEnd = false;
    
    visited[startX][startY] = 1;
    cost[startX][startY] = 0;
    parent[startX][startY] = -1;
    
    int currentX, currentY, newX, newY, totalCost, tempCost, heuristic, move;
    
    while(!foundEnd){
        totalCost = 99999;
        
        for(int i = 0; i < 4; i++){
            newX = startX + xMoves[i];
            newY = startY + yMoves[i];
            
            if(isOpen(newX, newY, maze, visited)){
                heuristic = calculateHeuristic(newX, newY, endX, endY);
                move = cost[startX][startY] + 1;
                
                tempCost = heuristic + move;
                
                if(tempCost < totalCost){
                    currentX = newX;
                    currentY = newY;
                    totalCost = tempCost;
                    parent[currentX][currentY] = startX * COL + startY;
                    cost[currentX][currentY] = move;
                }
            }
        }
        
        if(currentX == endX && currentY == endY){
            foundEnd = true;
        }
        else if(totalCost == 99999){
            printf("No path found!");
            return;
        }
        
        visited[currentX][currentY] = 1;
        startX = currentX;
        startY = currentY;
    }
    
    int path[ROW*COL];
    int pathIndex = 0;
    
    int currentPos = endX*COL + endY;
    path[pathIndex] = currentPos;
    pathIndex++;
    
    while(currentPos != startX*COL + startY){
        currentPos = parent[currentPos/COL][currentPos%COL];
        path[pathIndex] = currentPos;
        pathIndex++;
    }
    
    printf("\nThe path from (%d,%d) to (%d,%d) is: ", startX, startY, endX, endY);
    
    for(int i = pathIndex-1; i >= 0; i--){
        printf("(%d,%d) ", path[i]/COL, path[i]%COL);
    }
    
}


int main(){
    
    int startX = 1, startY = 1, endX = 8, endY = 8; //Change the start and end points to desired values
    
    int maze[ROW][COL] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    
    printf("The maze is:\n");
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    
    aStarPathfinding(maze, startX, startY, endX, endY);
    
    return 0;
}