//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define board size
#define ROW 10
#define COL 10

// define robot and goal positions
typedef struct {
    int row;
    int col;
} Position;

// define robot movement functions
void moveUp(Position* robot);
void moveDown(Position* robot);
void moveLeft(Position* robot);
void moveRight(Position* robot);

// define random direction generator function
int randomDirection();

int main() {
    // set up randomizer
    srand(time(NULL));
    
    // set initial robot and goal positions
    Position robot = {0, 0};
    Position goal = {ROW - 1, COL - 1};
    
    // print initial board state
    printf("Initial Board: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == robot.row && j == robot.col) {
                printf("R ");
            } else if (i == goal.row && j == goal.col) {
                printf("G ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    
    // move robot toward goal until reached
    while (robot.row != goal.row || robot.col != goal.col) {
        int direction = randomDirection();
        switch (direction) {
            case 0:
                moveUp(&robot);
                break;
            case 1:
                moveDown(&robot);
                break;
            case 2:
                moveLeft(&robot);
                break;
            case 3:
                moveRight(&robot);
                break;
            default:
                break;
        }
        
        // print updated board state
        printf("\nNext Move: \n");
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (i == robot.row && j == robot.col) {
                    printf("R ");
                } else if (i == goal.row && j == goal.col) {
                    printf("G ");
                } else {
                    printf(". ");
                }
            }
            printf("\n");
        }
    }
    
    // print final board state
    printf("\nFinal Board: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (i == robot.row && j == robot.col) {
                printf("R ");
            } else if (i == goal.row && j == goal.col) {
                printf("G ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    
    return 0;
}

void moveUp(Position* robot) {
    if (robot->row > 0) {
        robot->row--;
    }
}

void moveDown(Position* robot) {
    if (robot->row < ROW - 1) {
        robot->row++;
    }
}

void moveLeft(Position* robot) {
    if (robot->col > 0) {
        robot->col--;
    }
}

void moveRight(Position* robot) {
    if (robot->col < COL - 1) {
        robot->col++;
    }
}

int randomDirection() {
    int direction = rand() % 4;
    return direction;
}