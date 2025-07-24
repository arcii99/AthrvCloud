//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];
int visited[ROWS][COLS];

void generate_maze(int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return;
    }

    if(visited[row][col] == 1) {
        return;
    }

    visited[row][col] = 1;

    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for(int i = 0; i < 4; i++) {
        int rand_dir = rand() % 4;
        int r = row + directions[rand_dir][0];
        int c = col + directions[rand_dir][1];

        if(r < 0 || r >= ROWS || c < 0 || c >= COLS) {
            continue;
        }

        if(visited[r][c] == 1) {
            continue;
        }

        maze[row][col] |= (1 << rand_dir);
        maze[r][c] |= (1 << ((rand_dir + 2) % 4));

        generate_maze(r, c);
    }
}

void print_maze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("+");

            if((maze[i][j] & 1) == 0) {
                printf("-");
            }
            else {
                printf(" ");
            }

            if((maze[i][j] & 2) == 0) {
                printf("|");
            }
            else {
                printf(" ");
            }
        }

        printf("+\n");

        for(int j = 0; j < COLS; j++) {
            if((maze[i][j] & 4) == 0) {
                printf("| ");
            }
            else {
                printf("  ");
            }

            printf(" ");
        }

        if((maze[i][COLS - 1] & 2) == 0) {
            printf("|");
        }
        else {
            printf(" ");
        }

        printf("\n");
    }

    for(int j = 0; j < COLS; j++) {
        printf("+");

        if((maze[ROWS - 1][j] & 1) == 0) {
            printf("-");
        }
        else {
            printf(" ");
        }
    }

    printf("+\n");
}

int main() {
    srand(time(NULL));

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    generate_maze(0, 0);
    print_maze();
    
    return 0;
}