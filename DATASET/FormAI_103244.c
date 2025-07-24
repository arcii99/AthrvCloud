//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 100
#define MAX_COL 100

#define WALL -1
#define PATH -2
#define VISITED -3

int maze[MAX_ROW][MAX_COL];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int find_route(int x, int y, int dest_x, int dest_y, int num_rows, int num_cols) {
    if(x < 0 || y < 0 || x >= num_rows || y >= num_cols) {
        return 0;
    }
    if(maze[x][y] == WALL || maze[x][y] == VISITED) {
        return 0;
    }
    if(x == dest_x && y == dest_y) {
        maze[x][y] = PATH;
        return 1;
    }
    maze[x][y] = VISITED;
    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(find_route(new_x, new_y, dest_x, dest_y, num_rows, num_cols)) {
            maze[x][y] = PATH;
            return 1;
        }
    }
    return 0;
}

int main() {
    int num_rows, num_cols, start_x, start_y, dest_x, dest_y;

    printf("Enter the number of rows and columns in the maze: ");
    scanf("%d %d", &num_rows, &num_cols);

    for(int i = 0; i < num_rows; i++) {
        for(int j = 0; j < num_cols; j++) {
            printf("Enter 1 if cell (%d, %d) is a wall, 0 otherwise: ", i, j);
            scanf("%d", &maze[i][j]);
        }
    }

    memset(maze, WALL, sizeof(maze[0]));
    printf("Enter the starting x and y coordinates: ");
    scanf("%d %d", &start_x, &start_y);

    printf("Enter the destination x and y coordinates: ");
    scanf("%d %d", &dest_x, &dest_y);

    if(find_route(start_x, start_y, dest_x, dest_y, num_rows, num_cols)) {
        printf("There is a path from (%d, %d) to (%d, %d).\n", start_x, start_y, dest_x, dest_y);
        for(int i = 0; i < num_rows; i++) {
            for(int j = 0; j < num_cols; j++) {
                if(maze[i][j] == WALL) {
                    printf("# ");
                } else if(maze[i][j] == PATH) {
                    printf(". ");
                } else if(maze[i][j] == VISITED) {
                    printf("~ ");
                }
            }
            printf("\n");
        }
    } else {
        printf("There is no path from (%d, %d) to (%d, %d).\n", start_x, start_y, dest_x, dest_y);
    }
    return 0;
}