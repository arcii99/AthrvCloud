//FormAI DATASET v1.0 Category: Robot movement control ; Style: recursive
#include <stdio.h>

void moveRobot(int x, int y) {
    if (x == 0 && y == 0) {
        printf("Robot is at origin.");
        return;
    }
    
    if (x > 0) {
        printf("Move right.\n");
        moveRobot(x-1, y);
    }
    else if (x < 0) {
        printf("Move left.\n");
        moveRobot(x+1, y);
    }
    
    if (y > 0) {
        printf("Move up.\n");
        moveRobot(x, y-1);
    }
    else if (y < 0) {
        printf("Move down.\n");
        moveRobot(x, y+1);
    }
}

int main() {
    int x, y;
    printf("Enter the x and y coordinates: ");
    scanf("%d%d", &x, &y);
    moveRobot(x, y);
    return 0;
}