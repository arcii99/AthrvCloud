//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL];
int visited[ROW][COL];

void generateMaze(int x, int y) {
    visited[x][y] = 1;
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int random, nextX, nextY;
    for(int i = 0; i < 4; i++) {
        random = rand() % 4;
        nextX = x + direction[random][0];
        nextY = y + direction[random][1];
        if(nextX >= 0 && nextX < ROW && nextY >= 0 && nextY < COL && !visited[nextX][nextY]) {
            maze[x][y] |= (1 << random);
            maze[nextX][nextY] |= (1 << (random ^ 1));
            generateMaze(nextX, nextY);
        }
    }
}

void printMaze() {
    printf(" ");
    for(int i = 0; i < COL * 2 - 1; i++) {
        printf("_");
    }
    printf("\n");
    for(int i = 0; i < ROW; i++) {
        printf("|");
        for(int j = 0; j < COL; j++) {
            if((maze[i][j] & 2) != 0) {
                printf(" ");
            } else {
                printf("_");
            }
            if((maze[i][j] & 1) != 0) {
                if(((maze[i][j] | maze[i][j + 1]) & 2) != 0) {
                    printf(" ");
                } else {
                    printf("|");
                }
            } else {
                printf("|");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generateMaze(0, 0);
    printMaze();
    return 0;
}