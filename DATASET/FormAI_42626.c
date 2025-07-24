//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void print_maze() {
    int i, j;
    for(i = 0; i < MAX_ROWS; i++) {
        for(j = 0; j < MAX_COLS; j++){
            if(maze[i][j] == 1) printf("# ");
            else if (maze[i][j] == 0) printf("  ");
        }
        printf("\n");
    }
}

int find_path(int r, int c) {
    if (r == MAX_ROWS - 1 && c == MAX_COLS - 1) {
        maze[r][c] = 2; // mark end point
        return 1;
    }
    if (r < 0 || r >= MAX_ROWS || c < 0 || c >= MAX_COLS) // out of bounds
        return 0;
    if (maze[r][c] == 0) {
        maze[r][c] = 2;
        if (find_path(r, c - 1) || find_path(r - 1, c) ||
            find_path(r, c + 1) || find_path(r + 1, c)) {
            return 1;
        } else {
            maze[r][c] = 3;
        }
    }
    return 0;
}

int main() {
    printf("Welcome to the C Maze Route Finder!\n");
    printf("Here is the current maze:\n");
    print_maze();
    printf("\n");
    printf("Starting search for path...\n\n");
    if (find_path(1, 1)) {
        printf("Success! Here is the path:\n\n");
        print_maze();
    } else {
        printf("Sorry, no path found.\n");
    }
    printf("Thank you for using the C Maze Route Finder!\n");
    return 0;
}