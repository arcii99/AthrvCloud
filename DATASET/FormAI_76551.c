//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h> 

int main() {
    char action; // declare variable to capture user input
    
    printf("Welcome to the C Drone Remote Control:\n");
    printf("Use 'w' to move forward\n");
    printf("Use 'a' to move left\n");
    printf("Use 's' to move backward\n");
    printf("Use 'd' to move right\n");
    
    while(1) { // loop indefinitely 
        action = getchar(); // capture user input
        
        switch(action) {
            case 'w':
                printf("Drone moving forward\n");
                break;
            case 'a':
                printf("Drone moving left\n");
                break;
            case 's':
                printf("Drone moving backward\n");
                break;
            case 'd':
                printf("Drone moving right\n");
                break;
            default:
                printf("Invalid input, please try again\n");
                break;
        }
        
        while(getchar() != '\n'); // clear input buffer 
    }
    
    return 0;
}