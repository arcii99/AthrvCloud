//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
                    {0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                    {0, 0, 1, 1, 1, 0, 1, 0, 1, 0},
                    {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                    {0, 0, 1, 0, 1, 0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                    {1, 1, 1, 1, 1, 0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
                    {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}
                };

struct Node{
    int x;
    int y;
    int f;
    int g;
    int h;
    struct Node *parent;
};

int getNeighborList(struct Node *current, struct Node *neighborList[]){
    int numNeighbors = 0;
    for(int x=-1; x<=1; x++){
        for(int y=-1; y<=1; y++){
            if(x == 0 && y == 0) continue;
            int neighborX = current->x + x;
            int neighborY = current->y + y;
            if(neighborX >= 0 && neighborX < ROWS && neighborY >= 0 && neighborY < COLS){
                struct Node *neighbor = malloc(sizeof(struct Node));
                neighbor->x = neighborX;
                neighbor->y = neighborY;
                neighborList[numNeighbors++] = neighbor;
            }
        }
    }
    return numNeighbors;
}

int calcHValue(struct Node *current, struct Node *goal){
    int dx = abs(current->x - goal->x);
    int dy = abs(current->y - goal->y);
    return dx + dy;
}

void clearNodeList(struct Node *nodeList[], int numNodes){
    for(int i=0; i<numNodes; i++){
        free(nodeList[i]);
        nodeList[i] = NULL;
    }
}

void printPath(struct Node *currentNode){
    printf("Path found, coordinates:\n");
    while(currentNode->parent != NULL){
        printf("(%d,%d)\n", currentNode->x, currentNode->y);
        currentNode = currentNode->parent;
    }
    printf("(%d,%d)\n", currentNode->x, currentNode->y);
}

void pathfind(struct Node *start, struct Node *goal){
    struct Node *openList[ROWS*COLS], *closedList[ROWS*COLS];
    int numNodes = 0, numOpen = 1, fScore = 0;
    openList[0] = start;
    start->f = 0;
    start->g = 0;
    start->h = 0;
    while(numOpen > 0){
        struct Node *current = NULL;
        fScore = 99999;
        for(int i=0; i<numOpen; i++){
            if(openList[i]->f < fScore){
                current = openList[i];
                fScore = current->f;
            }
        }
        if(current == goal){
            printPath(current);
            return;
        }
        for(int i=0; i<numOpen; i++){
            if(current == openList[i]){
                openList[i] = openList[numOpen-1];
                numOpen--;
                break;
            }
        }
        closedList[numNodes++] = current;
        struct Node *neighborList[8];
        int numNeighbors = getNeighborList(current, neighborList);
        for(int i=0; i<numNeighbors; i++){
            struct Node *neighbor = neighborList[i];
            
            int neighborIsBetter = 0;
            int neighborIsInOpen = 0;
            int neighborIsInClosed = 0;
            int tentativeGScore = current->g + 1;
            
            for(int j=0; j<numOpen; j++){
                if(neighbor->x == openList[j]->x && neighbor->y == openList[j]->y){
                    neighborIsInOpen = 1;
                    break;
                }
            }
            if(!neighborIsInOpen){
                for(int j=0; j<numNodes; j++){
                    if(neighbor->x == closedList[j]->x && neighbor->y == closedList[j]->y){
                        neighborIsInClosed = 1;
                        break;
                    }
                }
                if(!neighborIsInClosed){
                    neighborIsBetter = 1;
                    neighbor->h = calcHValue(neighbor, goal);
                    neighbor->g = tentativeGScore;
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                    openList[numOpen++] = neighbor;
                }
            }
            else{
                if(tentativeGScore < neighbor->g){
                    neighborIsBetter = 1;
                }                
            }
            if(neighborIsBetter){
                neighbor->parent = current;
                neighbor->g = tentativeGScore;
                neighbor->f = neighbor->g + neighbor->h;
            }
        }
        clearNodeList(neighborList, numNeighbors);
    }    
}

int main(){
    struct Node start;
    start.x = 0;
    start.y = 0;
    struct Node goal;
    goal.x = ROWS-1;
    goal.y = COLS-1;
    pathfind(&start, &goal);
    return 0;
}