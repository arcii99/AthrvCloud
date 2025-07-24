//FormAI DATASET v1.0 Category: Robot movement control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// declare function for robot movement
void move_robot(int *x, int *y, int direction);

// main function
int main(void) {
    int board[ROWS][COLS] = {0};

    // randomly generate starting coordinates for robot
    srand(time(NULL));
    int x = rand() % ROWS;
    int y = rand() % COLS;
    board[x][y] = 1; // mark starting position on board

    // display initial board
    printf("Initial board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // randomly generate direction for robot to move in and move the robot
    for (int i = 0; i < 10; i++) {
        int direction = rand() % 4;
        move_robot(&x, &y, direction);
        board[x][y] = 1; // mark new position on board

        // display updated board
        printf("Board after move %d:\n", i+1);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

// function to move robot in specified direction
void move_robot(int *x, int *y, int direction) {
    switch (direction) {
        case 0: // move up
            if (*x > 0) *x -= 1;
            break;
        case 1: // move down
            if (*x < ROWS-1) *x += 1;
            break;
        case 2: // move left
            if (*y > 0) *y -= 1;
            break;
        case 3: // move right
            if (*y < COLS-1) *y += 1;
            break;
        default:
            printf("Invalid direction!\n");
            break;
    }
}