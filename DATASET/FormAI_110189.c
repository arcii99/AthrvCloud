//FormAI DATASET v1.0 Category: Robot movement control ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STEPS 5

// Define a structure for holding the current position of the robot
struct Position {
    int x;
    int y;
};

// Define a structure for holding a list of positions
struct PositionList {
    struct Position positions[MAX_STEPS];
    int size;
};

// Function for checking if a given position is valid
bool isValidPosition(int x, int y) {
    return x >= 0 && x < MAX_STEPS && y >= 0 && y < MAX_STEPS;
}

// Function for moving the robot
void moveRobot(struct Position* position, struct PositionList* history, int x, int y) {
    // Check if the new position is valid
    if (!isValidPosition(x, y)) {
        printf("Invalid position!\n");
        return;
    }
    
    // Check if the new position has already been visited
    for (int i = 0; i < history->size; i++) {
        if (history->positions[i].x == x && history->positions[i].y == y) {
            printf("You already visited this position!\n");
            return;
        }
    }
    
    // Add the new position to the list of visited positions
    history->positions[history->size].x = x;
    history->positions[history->size].y = y;
    history->size++;
    
    // Move the robot
    position->x = x;
    position->y = y;
}

int main() {
    struct Position position = {0, 0};
    struct PositionList history = {{0}, 0};
    
    // Move the robot to some positions
    moveRobot(&position, &history, 1, 1);
    moveRobot(&position, &history, 2, 2);
    moveRobot(&position, &history, 3, 3);
    moveRobot(&position, &history, 2, 2);
    
    // Print the list of visited positions
    for (int i = 0; i < history.size; i++) {
        printf("(%d, %d) ", history.positions[i].x, history.positions[i].y);
    }
    printf("\n");
    
    return 0;
}