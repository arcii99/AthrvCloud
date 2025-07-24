//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 25 // height of maze
#define WIDTH 25 // width of maze

void generate_maze(int maze[HEIGHT][WIDTH]);
void print_maze(int maze[HEIGHT][WIDTH]);

int main(void) {
    int maze[HEIGHT][WIDTH] = { 0 };
    srand(time(NULL)); // seed random number generator
    
    generate_maze(maze);
    print_maze(maze);

    return 0;
}

void generate_maze(int maze[HEIGHT][WIDTH]) {
    /* Recursive backtracking algorithm */
    int stack[HEIGHT * WIDTH][2] = {{0}};
    int top = 1;
    int visited = 1;
    int current[2] = {0};
    maze[0][0] = 1;
    stack[0][0] = 0;
    stack[0][1] = 0;

    while (visited < HEIGHT * WIDTH) {
        /* Check if we can move up */
        if (current[0] - 1 >= 0 && maze[current[0] - 1][current[1]] == 0) {
            stack[top][0] = current[0];
            stack[top][1] = current[1];
            top++;
            maze[current[0] - 1][current[1]] = 1;
            current[0]--;
            visited++;
            continue;
        }
        /* Check if we can move down */
        if (current[0] + 1 < HEIGHT && maze[current[0] + 1][current[1]] == 0) {
            stack[top][0] = current[0];
            stack[top][1] = current[1];
            top++;
            maze[current[0] + 1][current[1]] = 1;
            current[0]++;
            visited++;
            continue;
        }
        /* Check if we can move left */
        if (current[1] - 1 >= 0 && maze[current[0]][current[1] - 1] == 0) {
            stack[top][0] = current[0];
            stack[top][1] = current[1];
            top++;
            maze[current[0]][current[1] - 1] = 1;
            current[1]--;
            visited++;
            continue;
        }
        /* Check if we can move right */
        if (current[1] + 1 < WIDTH && maze[current[0]][current[1] + 1] == 0) {
            stack[top][0] = current[0];
            stack[top][1] = current[1];
            top++;
            maze[current[0]][current[1] + 1] = 1;
            current[1]++;
            visited++;
            continue;
        }
        /* If there is no unvisited path, backtrack */
        top--;
        current[0] = stack[top][0];
        current[1] = stack[top][1];
    }
}

void print_maze(int maze[HEIGHT][WIDTH]) {
    /* Print the maze */
    for (int i = 0; i < WIDTH; i++) {
        printf("__");
    }
    printf("\n");
    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 1) {
                printf("  ");
            } else {
                printf("__");
            }
            printf("|");
        }
        printf("\n");
    }
}