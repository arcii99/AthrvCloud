//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

struct coordinate {
    int row;
    int col;
};

bool maze[ROWS][COLS] = {
    {0,0,1,0,0,1,0,0,0,0},
    {1,0,1,1,0,1,0,1,1,0},
    {0,0,0,0,0,1,0,1,0,0},
    {0,1,1,1,0,1,0,1,0,1},
    {0,0,0,0,0,1,0,1,0,0},
    {1,0,1,1,0,0,0,1,0,1},
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,0,1,0,1,1,1},
    {0,0,0,0,0,1,0,0,0,0},
    {0,1,0,1,0,0,0,1,0,0}
};

void print_maze()
{
    printf("\n");
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            if(maze[i][j]) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_move(struct coordinate coor)
{
    return (coor.row >= 0 && coor.row < ROWS &&
            coor.col >= 0 && coor.col < COLS &&
            maze[coor.row][coor.col] == 0);
}

bool solve_maze_helper(struct coordinate start, struct coordinate end, bool(*solution)[COLS])
{
    if(start.row == end.row && start.col == end.col) {
        solution[start.row][start.col] = true;
        return true;
    }

    if(is_valid_move(start) == false) {
        return false;
    }

    solution[start.row][start.col] = true;

    struct coordinate right = {start.row, start.col+1};
    if(solve_maze_helper(right, end, solution)) {
        return true;
    }

    struct coordinate down = {start.row+1, start.col};
    if(solve_maze_helper(down, end, solution)) {
        return true;
    }

    solution[start.row][start.col] = false;
    return false;
}

bool solve_maze(struct coordinate start, struct coordinate end)
{
    bool solution[ROWS][COLS];

    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            solution[i][j] = false;
        }
    }

    if(solve_maze_helper(start, end, solution) == false) {
        printf("No solution found!\n");
        return false;
    }

    printf("Solution found:\n\n");

    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            if(solution[i][j]) {
                printf("* ");
            } else if(maze[i][j]) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return true;
}

int main()
{
    struct coordinate start = {0, 0};
    struct coordinate end = {ROWS-1, COLS-1};

    printf("Maze:\n\n");
    print_maze();

    solve_maze(start, end);

    return 0;
}