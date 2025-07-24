//FormAI DATASET v1.0 Category: Robot movement control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

void move(int direction);

int main() {

    int input;
    
    while (1) {
        printf("Please input direction: (1) Forward (2) Backward (3) Left (4) Right: ");
        scanf("%d", &input);
        
        if (input < 1 || input > 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }
        
        move(input);
    }
    
    return 0;
}

void move(int direction) {
    switch(direction) {
        case FORWARD:
            printf("Robot moves forward.\n");
            break;
        case BACKWARD:
            printf("Robot moves backward.\n");
            break;
        case LEFT:
            printf("Robot turns left.\n");
            break;
        case RIGHT:
            printf("Robot turns right.\n");
            break;
    }
}