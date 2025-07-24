//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define SOURCE 1
#define DESTINATION 2
#define OBSTACLE 3
#define EMPTY 0

int map[ROW][COL] = {{0,0,0,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,3,0,0,0},
                     {0,1,0,0,0,0,3,0,0,0},
                     {0,1,0,0,0,0,3,0,0,0},
                     {0,0,0,0,0,0,3,2,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0}};

void printMap();

void findPath(int xStart, int yStart, int xDest, int yDest) {
    int xQueue[ROW*COL], yQueue[ROW*COL];
    int i, x, y, xNext, yNext;
    int direction[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    int visited[ROW][COL];
    for(i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            visited[i][j] = 0;
        }
    }
    visited[xStart][yStart] = 1;
    xQueue[0] = xStart;
    yQueue[0] = yStart;
    int queueFront = 0, queueBack = 1;
    while(queueFront < queueBack) {
        x = xQueue[queueFront];
        y = yQueue[queueFront];
        queueFront++;
        for(i = 0; i < 8; i++) {
            xNext = x + direction[i][0];
            yNext = y + direction[i][1];
            if(xNext < 0 || xNext >= ROW || yNext < 0 || yNext >= COL) {
                continue;
            }
            if(visited[xNext][yNext] == 1) {
                continue;
            }
            if(map[xNext][yNext] == OBSTACLE) {
                continue;
            }
            visited[xNext][yNext] = 1;
            xQueue[queueBack] = xNext;
            yQueue[queueBack] = yNext;
            queueBack++;
        }
    }
    if(visited[xDest][yDest] == 1) {
        printf("Destination is reachable from source\n");
    } else {
        printf("Destination is not reachable from source\n");
    }
}

void printMap() {
    for(int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            switch(map[i][j]) {
                case SOURCE:
                    printf("S ");
                    break;
                case DESTINATION:
                    printf("D ");
                    break;
                case OBSTACLE:
                    printf("X ");
                    break;
                case EMPTY:
                    printf("O ");
                    break;
                default:
                    printf("? ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Welcome to the Mind-Bending Pathfinder!\n");
    printf("Your objective is to guide the Source (S) through the Obstacles (X)\nto reach its ultimate Destination (D).\n");
    printf("Press any key to continue...");
    getchar();
    printf("\n");
    printf("Here is the initial map:\n");
    printMap();
    printf("Press any key to embark on this mind-bending journey...");
    getchar();
    printf("\n");
    printf("Our adventure begins!\n");
    findPath(1, 1, 5, 7);
    printf("\n");
    printf("Fasten your seatbelts, we have reached our final destination!\n");
    printf("Here is the final map with the path:\n");
    map[5][7] = DESTINATION;
    printMap();
    return 0;
}