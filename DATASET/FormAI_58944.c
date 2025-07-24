//FormAI DATASET v1.0 Category: Robot movement control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// function to move robot forward
void move_forward(int meters) {
    printf("Moving forward %d meters\n", meters);
}

// function to move robot backward
void move_backward(int meters) {
    printf("Moving backward %d meters\n", meters);
}

// function to turn robot left
void turn_left(int degrees) {
    printf("Turning left %d degrees\n", degrees);
}

// function to turn robot right
void turn_right(int degrees) {
    printf("Turning right %d degrees\n", degrees);
}

int main() {
    int option, value;
    
    // display menu
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Quit\n");
    
    do {
        printf("Enter option: ");
        scanf("%d", &option);
        
        // switch case for different options
        switch(option) {
            case 1:
                printf("Enter distance in meters: ");
                scanf("%d", &value);
                move_forward(value);
                break;
                
            case 2:
                printf("Enter distance in meters: ");
                scanf("%d", &value);
                move_backward(value);
                break;
                
            case 3:
                printf("Enter degrees to turn left: ");
                scanf("%d", &value);
                turn_left(value);
                break;
                
            case 4:
                printf("Enter degrees to turn right: ");
                scanf("%d", &value);
                turn_right(value);
                break;
                
            case 5:
                printf("Exiting program\n");
                exit(0);
                break;
                
            default:
                printf("Invalid option\n");
        }
    } while (1);
    
    return 0;
}