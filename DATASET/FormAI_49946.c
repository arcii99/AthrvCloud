//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Node;

void printMap(char map[15][15], Node start, Node end, Node* path) {
    printf("  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
    for(int i = 0; i < 15; i++) {
        printf("%c ", 'A'+i);
        for(int j = 0; j < 15; j++) {
            if(i == start.y && j == start.x) printf("S ");
            else if(i == end.y && j == end.x) printf("E ");
            else {
                int flag = 0;
                for(int k = 0; k < 100; k++) {
                    if(path[k].x == j && path[k].y == i) {
                        printf("* ");
                        flag = 1;
                        break;
                    }
                }
                if(!flag) printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char map[15][15] = {
        "+-+-+-+-+-+-+-+-+-+",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# #S# # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "|# # # # # # # # # #|",
        "+-+-+-+-+-+-+-+-+-+"
    };

    Node start = {2, 2};    //S is the start point
    Node end = {12, 9};     //E is the end point

    // A* Search algorithm
    int openList[15*15], closeList[15*15];
    int fScore[15*15], gScore[15*15];
    int parent[15*15];
    for(int i = 0; i < 15*15; i++) {
        openList[i] = -1;
        closeList[i] = -1;
        fScore[i] = -1;
        gScore[i] = -1;
        parent[i] = -1;
    }

    int openCount = 0;
    openList[openCount++] = start.y*15+start.x;
    gScore[start.y*15+start.x] = 0;
    fScore[start.y*15+start.x] = abs(start.x-end.x)+abs(start.y-end.y);

    while(openCount > 0) {
        // Find the cell with the lowest fScore
        int minIndex = 0;
        for(int i = 0; i < openCount; i++) {
            if(fScore[openList[i]] < fScore[openList[minIndex]]) {
                minIndex = i;
            }
        }

        int cellIndex = openList[minIndex];
        if(cellIndex == end.y*15+end.x) {
            Node path[100];
            int pathLength = 0;

            while(cellIndex != start.y*15+start.x) {
                path[pathLength].x = cellIndex%15;
                path[pathLength].y = cellIndex/15;
                pathLength++;
                cellIndex = parent[cellIndex];
            }
            path[pathLength].x = start.x;
            path[pathLength].y = start.y;

            printMap(map, start, end, path);
            return 0;
        }

        // Remove the current cell from the open list and add it to the close list
        openList[minIndex] = openList[--openCount];
        closeList[cellIndex] = 1;

        // Process the neighbors of the current cell
        int x = cellIndex%15, y = cellIndex/15;
        if(x > 0 && map[y][x-1] != '#' && closeList[y*15+x-1] != 1) {   // Left
            int g = gScore[cellIndex] + 1;
            int h = abs(x-1-end.x)+abs(y-end.y);
            int f = g + h;

            int neighborIndex = y*15+x-1;
            if(gScore[neighborIndex] == -1 || g < gScore[neighborIndex]) {
                parent[neighborIndex] = cellIndex;
                gScore[neighborIndex] = g;
                fScore[neighborIndex] = f;

                int found = 0;
                for(int i = 0; i < openCount; i++) {
                    if(openList[i] == neighborIndex) {
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    openList[openCount++] = neighborIndex;
                }
            }
        }
        if(x < 14 && map[y][x+1] != '#' && closeList[y*15+x+1] != 1) {  // Right
            int g = gScore[cellIndex] + 1;
            int h = abs(x+1-end.x)+abs(y-end.y);
            int f = g + h;

            int neighborIndex = y*15+x+1;
            if(gScore[neighborIndex] == -1 || g < gScore[neighborIndex]) {
                parent[neighborIndex] = cellIndex;
                gScore[neighborIndex] = g;
                fScore[neighborIndex] = f;

                int found = 0;
                for(int i = 0; i < openCount; i++) {
                    if(openList[i] == neighborIndex) {
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    openList[openCount++] = neighborIndex;
                }
            }
        }
        if(y > 0 && map[y-1][x] != '#' && closeList[(y-1)*15+x] != 1) {  // Up
            int g = gScore[cellIndex] + 1;
            int h = abs(x-end.x)+abs(y-1-end.y);
            int f = g + h;

            int neighborIndex = (y-1)*15+x;
            if(gScore[neighborIndex] == -1 || g < gScore[neighborIndex]) {
                parent[neighborIndex] = cellIndex;
                gScore[neighborIndex] = g;
                fScore[neighborIndex] = f;

                int found = 0;
                for(int i = 0; i < openCount; i++) {
                    if(openList[i] == neighborIndex) {
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    openList[openCount++] = neighborIndex;
                }
            }
        }
        if(y < 14 && map[y+1][x] != '#' && closeList[(y+1)*15+x] != 1) { // Down
            int g = gScore[cellIndex] + 1;
            int h = abs(x-end.x)+abs(y+1-end.y);
            int f = g + h;

            int neighborIndex = (y+1)*15+x;
            if(gScore[neighborIndex] == -1 || g < gScore[neighborIndex]) {
                parent[neighborIndex] = cellIndex;
                gScore[neighborIndex] = g;
                fScore[neighborIndex] = f;

                int found = 0;
                for(int i = 0; i < openCount; i++) {
                    if(openList[i] == neighborIndex) {
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    openList[openCount++] = neighborIndex;
                }
            }
        }
    }

    printf("No path found.\n");

    return 0;
}