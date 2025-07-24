//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define WALL '+'
#define PATH ' '
#define START 'S'
#define END 'E'

char maze[ROW][COL];

void drawMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Generate Maze
    srand(time(NULL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == 0 || i == ROW-1 || j == 0 || j == COL-1)
                maze[i][j] = WALL;
            else
                maze[i][j] = PATH;
        }
    }

    int startX = 1 + rand() % (ROW-2);
    int startY = 1 + rand() % (COL-2);
    int endX, endY;
    do {
        endX = 1 + rand() % (ROW-2);
        endY = 1 + rand() % (COL-2);
    } while (endX == startX && endY == startY);

    maze[startX][startY] = START;
    maze[endX][endY] = END;

    for (int i = 1; i < ROW-1; i++) {
        for (int j = 1; j < COL-1; j++) {
            if (maze[i][j] == PATH) {
                int r = rand() % 4;
                switch (r) {
                    case 0:
                        if (maze[i-1][j] == PATH)
                            maze[i-1][j] = WALL;
                        break;
                    case 1:
                        if (maze[i+1][j] == PATH)
                            maze[i+1][j] = WALL;
                        break;
                    case 2:
                        if (maze[i][j-1] == PATH)
                            maze[i][j-1] = WALL;
                        break;
                    case 3:
                        if (maze[i][j+1] == PATH)
                            maze[i][j+1] = WALL;
                        break;
                }
            }
        }
    }

    // Solve Maze
    int x = startX, y = startY;
    int targetX = endX, targetY = endY;
    while (maze[x][y] != END) {
        maze[x][y] = 'x';
        if (x > targetX)
            x--;
        else if (x < targetX)
            x++;
        else if (y > targetY)
            y--;
        else if (y < targetY)
            y++;
        drawMaze();
    }
    printf("Congratulations, you solved the maze!\n");

    return 0;
}