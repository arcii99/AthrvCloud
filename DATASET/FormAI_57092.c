//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up the random number generator
    srand(time(0));
    
    // Initializing variables for game play
    int choice;
    int ghost_location = rand() % 10 + 1;
    int door_location = rand() % 10 + 1;
    int is_game_over = 0;
    
    while (!is_game_over)
    {
        // Printing game instructions and current status
        printf("Welcome to the Haunted House Simulator!\n");
        printf("You are standing in front of a haunted house.\n");
        printf("There is a ghost lurking around inside the house.\n");
        printf("There are 10 doors in the house, but only one door leads to safety.\n");
        printf("If you choose the wrong door, the ghost will catch you and you will lose the game.\n");
        printf("Enter the number of the door you want to open (1-10): ");
        scanf("%d", &choice);
        
        // Checking if the chosen door leads to safety or if the ghost caught you
        if (choice == door_location)
        {
            printf("Congratulations, you have escaped the haunted house!\n");
            is_game_over = 1;
        }
        else if (choice == ghost_location)
        {
            printf("Oh no, the ghost has caught you!\n");
            is_game_over = 1;
        }
        else
        {
            printf("You chose the wrong door, there is nothing behind it.\n");
        }
    }
    
    return 0;
}