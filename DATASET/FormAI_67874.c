//FormAI DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>

// Function to turn on the lights
void turnOn() {
    printf("The light is now on.\n");
}

// Function to turn off the lights
void turnOff() {
    printf("The light is now off.\n");
}

// Main function
int main() {
    // Declare variables
    int choice = 0;
    
    // Print instructions
    printf("Welcome to Smart Home Light Control\n\n");
    printf("1. Turn on the lights\n");
    printf("2. Turn off the lights\n");
    printf("3. Exit\n\n");
    
    // Loop until user chooses to exit
    while (choice != 3) {
        // Get user choice
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Switch statement to execute user choice
        switch (choice) {
            case 1:
                turnOn();
                break;
            case 2:
                turnOff();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}