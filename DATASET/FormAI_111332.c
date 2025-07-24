//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

char maze[ROW][COL + 1] = {
    "+--------+",
    "|        |",
    "| +------+",
    "| |      ",
    "| | +--+-+",
    "| | |     ",
    "| | +--+-+",
    "| |      ",
    "| +------+"
};

void print_maze() {
    for (int r = 0; r < ROW; r++) {
        printf("%s\n", maze[r]);
    }
}

bool valid_space(int r, int c) {
    if (r < 0 || c < 0 || r >= ROW || c >= COL || maze[r][c] != ' ') {
        return false;
    }
    return true;
}

bool dfs(int r, int c) {
    if (r == ROW - 1 && c == COL - 2) {
        maze[r][c] = 'X';
        return true;
    }
    if (valid_space(r, c)) {
        maze[r][c] = 'X';
        if (dfs(r + 1, c) || dfs(r, c + 1) || dfs(r - 1, c) || dfs(r, c - 1)) {
            return true;
        }
        maze[r][c] = ' ';    // backtrack
    }
    return false;
}

int main() {
    printf("Original Maze:\n");
    print_maze();

    if (dfs(0, 1)) {
        printf("\nSolved Maze:\n");
        print_maze();
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}