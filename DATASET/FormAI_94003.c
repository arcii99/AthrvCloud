//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // initializing the light status as off
    int lightStatus = 0;

    // printing the current status of the light
    printf("The light is currently Off.\n");

    // Looping through the options for controlling the light
    while(1)
    {
        // Printing the user prompt to change the light status
        printf("Enter '1' to turn on the light, '0' to turn off the light and '2' to exit: ");
        int userInput;
        scanf("%d", &userInput);

        // Checking the user input and acting accordingly
        if(userInput == 1)
        {
            // Turning on the light
            lightStatus = 1;
            printf("The light is now On.\n");
        }
        else if(userInput == 0)
        {
            // Turning off the light
            lightStatus = 0;
            printf("The light is now Off.\n");
        }
        else if(userInput == 2)
        {
            // Exiting the program
            printf("Exiting the Smart Home Light Control program...\n");
            break;
        }
        else
        {
            // If the user enters anything other than 1, 0 or 2
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}