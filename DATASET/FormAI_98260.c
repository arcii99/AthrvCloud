//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 20
#define MAX_COL 40

char Maze[MAX_ROW][MAX_COL];
int Visited[MAX_ROW][MAX_COL];
int StartRow, StartCol, EndRow, EndCol;

void GenerateMaze() {
    int x, y, i, j, k, Direction;
    // Set all cells to be wall
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            Maze[i][j] = '#';
            Visited[i][j] = 0;
        }
    }
    // Choose a random starting point
    srand(time(NULL));
    StartRow = rand() % MAX_ROW;
    StartCol = rand() % MAX_COL;
    Maze[StartRow][StartCol] = 'S';
    // Choose a random ending point
    EndRow = rand() % MAX_ROW;
    EndCol = rand() % MAX_COL;
    Maze[EndRow][EndCol] = 'E';
    // Generate the maze
    x = StartRow;
    y = StartCol;
    Visited[x][y] = 1;
    while (1) {
        k = 0;
        for (i = 0; i < 4; i++) {
            switch (i) {
                case 0: // Up
                    if (x > 0 && !Visited[x-1][y]) {
                        k++;
                        break;
                    }
                    else continue;
                case 1: // Down
                    if (x < MAX_ROW-1 && !Visited[x+1][y]) {
                        k++;
                        break;
                    }
                    else continue;
                case 2: // Left
                    if (y > 0 && !Visited[x][y-1]) {
                        k++;
                        break;
                    }
                    else continue;
                case 3: // Right
                    if (y < MAX_COL-1 && !Visited[x][y+1]) {
                        k++;
                        break;
                    }
                    else continue;
            }
        }
        if (k == 0) {
            if (x == StartRow && y == StartCol) return;
            Direction = rand() % 4;
            switch (Direction) {
                case 0: // Up
                    x--;
                    break;
                case 1: // Down
                    x++;
                    break;
                case 2: // Left
                    y--;
                    break;
                case 3: // Right
                    y++;
                    break;
            }
        }
        else {
            Direction = -1;
            while (Direction == -1) {
                i = rand() % 4;
                switch (i) {
                    case 0: // Up
                        if (x > 0 && !Visited[x-1][y]) {
                            Direction = i;
                            break;
                        }
                        else continue;
                    case 1: // Down
                        if (x < MAX_ROW-1 && !Visited[x+1][y]) {
                            Direction = i;
                            break;
                        }
                        else continue;
                    case 2: // Left
                        if (y > 0 && !Visited[x][y-1]) {
                            Direction = i;
                            break;
                        }
                        else continue;
                    case 3: // Right
                        if (y < MAX_COL-1 && !Visited[x][y+1]) {
                            Direction = i;
                            break;
                        }
                        else continue;
                }
            }
            switch (Direction) {
                case 0: // Up
                    Maze[x-1][y] = ' ';
                    x--;
                    break;
                case 1: // Down
                    Maze[x+1][y] = ' ';
                    x++;
                    break;
                case 2: // Left
                    Maze[x][y-1] = ' ';
                    y--;
                    break;
                case 3: // Right
                    Maze[x][y+1] = ' ';
                    y++;
                    break;
            }
            Visited[x][y] = 1;
        }
    }
}

void PrintMaze() {
    int i, j;
    for (i = 0; i < MAX_ROW; i++) {
        for (j = 0; j < MAX_COL; j++) {
            printf("%c", Maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GenerateMaze();
    PrintMaze();
    return 0;
}