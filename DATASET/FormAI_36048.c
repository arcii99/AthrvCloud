//FormAI DATASET v1.0 Category: Robot movement control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int x = 0, y = 0; // Robot's starting position
    char input[100]; // User input string
    bool exitLoop = false; // Loop control variable
    
    printf("Enter robot movement commands (U: Up, D: Down, L: Left, R: Right):\n");
    
    while(!exitLoop) { // Loop until user enters "exit" command
        printf("Position: (%d, %d)\n", x, y);
        printf("Enter command (or type 'exit' to exit): ");
        fgets(input, 100, stdin); // Read input from user
        
        if(strcmp(input, "exit\n") == 0) { // Check if user wants to exit
            exitLoop = true;
        }
        else if(strlen(input) != 2) { // Check if input has incorrect length
            printf("Invalid command!\n");
        }
        else {
            switch(input[0]) { // Check input direction
                case 'U':
                    y++;
                    break;
                case 'D':
                    y--;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
                default:
                    printf("Invalid command!\n");
                    break;
            }
        }
    }
 
    printf("Goodbye!\n");
    return 0;
}