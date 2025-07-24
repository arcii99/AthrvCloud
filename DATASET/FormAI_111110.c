//FormAI DATASET v1.0 Category: Smart home light control ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
   Smart Home Light Control
   This program demonstrates how to control a home light system. The user can turn on/off the light 
   using the smart home application. The program is written in a portable style to work on any device 
   with a C compiler.
*/

int main() {
    
    int lightOn = 0;   // 0 = light off, 1 = light on
    char input[10];

    printf("Welcome to Smart Home Light Control!\n\n");
    
    while(1) {

        // Print menu
        printf("Menu:\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Quit program\n\n");

        // Get user input
        printf("Enter menu choice: ");
        fgets(input, 10, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Convert input to integer
        int choice = atoi(input);

        // Process input
        switch(choice) {
            case 1:
                if (lightOn == 1)
                    printf("Light is already on.\n");
                else {
                    printf("Turning on light...\n");
                    lightOn = 1;
                }
                break;
            case 2:
                if (lightOn == 0)
                    printf("Light is already off.\n");
                else {
                    printf("Turning off light...\n");
                    lightOn = 0;
                }
                break;
            case 3:
                printf("Exiting Smart Home Light Control...\n");
                return 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}