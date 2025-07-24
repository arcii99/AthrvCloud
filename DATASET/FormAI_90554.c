//FormAI DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a function to turn on/off the lights
void toggleLights(bool *lightsOn) {
    *lightsOn = !(*lightsOn);   // Flip the value of `lightsOn`
    if (*lightsOn) {
        printf("Lights turned ON\n");
    } else {
        printf("Lights turned OFF\n");
    }
}

int main() {
    bool livingRoomLightsOn = false;    // Initialize the living room lights to off
    bool kitchenLightsOn = false;       // Initialize the kitchen lights to off
    
    char userInput;     // Define a variable to store user input
    
    // Display the instructions
    printf("-- Smart Home Light Control --\n");
    printf("Press 'l' to toggle living room lights\n");
    printf("Press 'k' to toggle kitchen lights\n");
    printf("Press 'q' to quit\n");
    
    // Start the control loop
    do {
        printf("Enter command: ");
        scanf(" %c", &userInput);       // Get user input
        
        switch(userInput) {
            case 'l':   // User toggles living room lights
                toggleLights(&livingRoomLightsOn);
                break;
            case 'k':   // User toggles kitchen lights
                toggleLights(&kitchenLightsOn);
                break;
            case 'q':   // User quits the program
                printf("Quitting...\n");
                break;
            default:    // Invalid user input
                printf("Invalid command\n");
                break;
        }
    } while (userInput != 'q');     // Keep looping until the user quits
    
    return 0;   // End of program
}