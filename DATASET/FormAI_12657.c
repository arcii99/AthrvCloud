//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

char maze[MAX_ROWS][MAX_COLS];
int rows, cols;
int start_row, start_col, end_row, end_col;

void read_maze(FILE *fp) {
    char buffer[MAX_COLS];
    int i = 0;
    while(fgets(buffer, MAX_COLS, fp) != NULL) {
        int len = strcspn(buffer, "\n"); 
        memcpy(maze[i], buffer, len); 
        i++;
        cols = len;
    }
    rows = i;
}

void print_maze() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int solve_maze(int row, int col) {
    if(row < 0 || col < 0 || row >= rows || col >= cols) {
        return 0;
    }
    if(maze[row][col] == '#') {
        return 0;
    }
    if(maze[row][col] == 'E') {
        return 1;
    }
    maze[row][col] = '#';
    if(solve_maze(row-1, col) == 1) { 
        return 1;
    }
    if(solve_maze(row+1, col) == 1) {
        return 1;
    }
    if(solve_maze(row, col-1) == 1) {
        return 1;
    }
    if(solve_maze(row, col+1) == 1) {
        return 1;
    }
    maze[row][col] = '.';
    return 0;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s <maze_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    read_maze(fp);
    fclose(fp);

    printf("Maze:\n");
    print_maze();

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(maze[i][j] == 'S') {
                start_row = i;
                start_col = j;
            } else if(maze[i][j] == 'E') {
                end_row = i;
                end_col = j;
            }
        }
    }

    if(solve_maze(start_row, start_col) == 1) {
        printf("\nCongratulations! You found a way out!\n");
        maze[start_row][start_col] = 'S';
        maze[end_row][end_col] = 'E';
        print_maze();
    } else {
        printf("\nSorry, there is no way out!\n");
    }

    return 0;
}