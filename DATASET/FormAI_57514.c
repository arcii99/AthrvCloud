//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: ephemeral
#include <stdio.h> // Standard Input Output library
#include <stdlib.h> // Standard library
#include <time.h> // Time library

typedef struct { // Custom data type for drone movement
    int up_down; // Vertical movement
    int front_back; // Forward or backward movement
    int left_right; // Left or right movement
    int rotate; // Rotate movement
} DroneMovement;

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    
    DroneMovement movement = {0, 0, 0, 0}; // Initialize drone movement with zero
    
    printf("Welcome to C Drone Remote Control Program!\n");
    printf("Enter 'q' to quit anytime.\n\n");
    
    while (1) { // Infinite loop until user exits
        printf("Enter 'u' to move drone up, 'd' to move down, 'f' to move forward, 'b' to move backward,\n'l' to move left, 'r' to move right, 'c' to rotate clockwise, 'a' to rotate anticlockwise:\n");
        
        char input = getchar(); // Read one character from console input
        
        if (input == 'q') {
            printf("Exiting C Drone Remote Control Program.\n");
            break; // Exit infinite loop
        }
        
        switch(input) {
            case 'u':
                movement.up_down += 10; // Move drone up by 10 meters
                printf("Drone moved up by 10 meters.\n\n");
                break;
            case 'd':
                movement.up_down -= 10; // Move drone down by 10 meters
                printf("Drone moved down by 10 meters.\n\n");
                break;
            case 'f':
                movement.front_back += rand() % 20 + 10; // Move drone forward randomly between 10 to 29 meters
                printf("Drone moved forward by %d meters.\n\n", movement.front_back);
                break;
            case 'b':
                movement.front_back -= rand() % 20 + 10; // Move drone backward randomly between 10 to 29 meters
                printf("Drone moved backward by %d meters.\n\n", -movement.front_back);
                break;
            case 'l':
                movement.left_right -= rand() % 20 + 10; // Move drone left randomly between 10 to 29 meters
                printf("Drone moved left by %d meters.\n\n", -movement.left_right);
                break;
            case 'r':
                movement.left_right += rand() % 20 + 10; // Move drone right randomly between 10 to 29 meters
                printf("Drone moved right by %d meters.\n\n", movement.left_right);
                break;
            case 'c':
                movement.rotate += 10; // Rotate drone clockwise by 10 degrees
                printf("Drone rotated clockwise by 10 degrees.\n\n");
                break;
            case 'a':
                movement.rotate -= 10; // Rotate drone anticlockwise by 10 degrees
                printf("Drone rotated anticlockwise by 10 degrees.\n\n");
                break;
            default:
                printf("Invalid input. Try again.\n\n");
                break;
        }
        
        while (getchar() != '\n'); // Clear console input buffer
    }
    
    return 0;
}