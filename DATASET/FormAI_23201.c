//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>

// This program controls the movements of a robot
// The robot can move forward, backward, left and right
// We will use 'W', 'A', 'S' and 'D' keys to control the robot

int main() {
    
    char move; // To store the movement key pressed
    
    printf("Press 'W' to move forward\n");
    printf("Press 'A' to move left\n");
    printf("Press 'S' to move backward\n");
    printf("Press 'D' to move right\n");
    
    // Loop to continue taking input until user exits
    while (1){
        printf("\nWhat do you want to do? ");
        scanf(" %c", &move);
        
        // Switch case to check user input
        switch (move){
            case 'W':
                printf("\nMoving forward...\n");
                break;
            case 'A':
                printf("\nMoving left...\n");
                break;
            case 'S':
                printf("\nMoving backward...\n");
                break;
            case 'D':
                printf("\nMoving right...\n");
                break;
        }
        
        // Prompt user to exit or continue
        printf("Enter 'E' to exit or any other key to continue: ");
        scanf(" %c", &move);
        
        // Check if user inputs to exit
        if (move == 'E'){
            break;
        }
    }
    
    return 0;
}