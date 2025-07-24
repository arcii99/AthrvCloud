//FormAI DATASET v1.0 Category: Browser Plugin ; Style: brave
#include <stdio.h>

int main() {
    printf("Welcome to my Brave-style C Browser Plugin!\n");
    int num_clicks = 0; // Keep track of how many times the button is clicked
    while(1) // Loop infinitely until the user exits the program
    {
        printf("Click the button to start browsing!\n"); 
        printf("Number of clicks so far: %d\n", num_clicks);
        char button = getchar(); // Get input character from user
        if(button == '\n') // If the user presses the Enter key
        {
            num_clicks++; // Increment the number of clicks
            printf("Opening a new tab...\n");
            printf("Would you like to browse privately? (yes or no)\n");
            char choice[20]; // Store user's choice
            scanf("%s", choice); 
            if(strcmp(choice, "yes") == 0)
            {
                printf("Private browsing mode activated!\n"); 
            }
            else if(strcmp(choice, "no") == 0)
            {
                printf("Normal browsing mode activated.\n");
            }
            else
            {
                printf("Invalid choice.\n"); 
            }
        }
        else if(button == 'q') // If the user presses the 'q' key
        {
            printf("Exiting program...\n");
            break; // Exit the program
        }
        else // If the user presses any other key
        {
            printf("Invalid input.\n"); 
        }
    }
    return 0;
}