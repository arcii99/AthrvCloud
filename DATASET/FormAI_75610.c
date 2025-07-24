//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>

int moveRobot(int distance, int direction, int currentX, int currentY){
    //base case
    if(distance == 0){
        return 1;
    }
    //recursive case
    switch(direction){
        case 0:
            printf("Move forward one unit\n");
            currentY++;
            break;
        case 1:
            printf("Turn left\n");
            direction = 3;
            break;
        case 2:
            printf("Turn around\n");
            direction = 0;
            currentX--;
            break;
        case 3:
            printf("Turn right\n");
            direction = 0;
            currentX++;
            break;
    }
    distance--;
    //recursive call
    moveRobot(distance, direction, currentX, currentY);
}

int main(){
    int distance = 5;
    int direction = 0; // 0 for facing up, 1 for facing left, 2 for facing down, 3 for facing right
    int currentX = 0;
    int currentY = 0;
    printf("Starting position: (%d, %d)\n", currentX, currentY);
    //call the recursive function
    moveRobot(distance, direction, currentX, currentY);
    //print final position
    printf("Final position: (%d, %d)\n", currentX, currentY);
    return 0;
}