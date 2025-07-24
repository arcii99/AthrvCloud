//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to read user input
int read_input() {
    int input;
    printf("Enter a number between 1 and 4 to control the vehicle:\n");
    scanf("%d", &input);
    return input;
}

int main() {
    int direction = 0; // 0 - stop, 1 - forward, 2 - left, 3 - right, 4 - backward
    bool running = true;
    
    while(running) {
        int input = read_input();
        
        switch(input) {
            case 1:
                printf("Vehicle moving forward.\n");
                direction = 1;
                break;
            case 2:
                printf("Vehicle turning left.\n");
                direction = 2;
                break;
            case 3:
                printf("Vehicle turning right.\n");
                direction = 3;
                break;
            case 4:
                printf("Vehicle moving backward.\n");
                direction = 4;
                break;
            default:
                printf("Invalid input.\n");
                direction = 0;
        }
        
        if(direction == 0) {
            printf("Vehicle stopped.\n");
        }
    }
    
    printf("Program ended.\n");
    return 0;
}