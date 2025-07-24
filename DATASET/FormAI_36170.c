//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Welcome message
    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You have just entered a haunted house and need to find your way out.\n");

    // Declare and initialize variables
    int current_room = 1;
    bool is_alive = true;
    char input[20];
    int room_list[5] = {1, 2, 3, 4, 5};

    // Game loop
    while (is_alive && current_room != 5)
    {
        // Randomly rearrange the order of the rooms
        for (int i = 0; i < 5; i++)
        {
            int random_index = random_number(0, 4);
            int temp_room = room_list[i];
            room_list[i] = room_list[random_index];
            room_list[random_index] = temp_room;
        }

        // Print out the available directions
        printf("\nYou are currently in room %d.\n", current_room);
        printf("Available directions: \n");
        if (current_room == 1)
        {
            printf("      North (Room %d)\n", room_list[0]);
            printf("      East (Room %d)\n", room_list[1]);
        }
        else if (current_room == 2)
        {
            printf("      South (Room %d)\n", room_list[0]);
            printf("      East (Room %d)\n", room_list[1]);
            printf("      West (Room %d)\n", room_list[2]);
        }
        else if (current_room == 3)
        {
            printf("      North (Room %d)\n", room_list[0]);
            printf("      South (Room %d)\n", room_list[1]);
            printf("      East (Room %d)\n", room_list[2]);
        }
        else if (current_room == 4)
        {
            printf("      North (Room %d)\n", room_list[0]);
            printf("      West (Room %d)\n", room_list[1]);
        }

        // Get user input
        printf("\nWhat direction would you like to go? ");
        fgets(input, sizeof(input), stdin);

        // Check for valid input
        if (strncmp(input, "north", 5) == 0 || strncmp(input, "North", 5) == 0)
        {
            if (current_room == 1 || current_room == 3 || current_room == 4)
            {
                printf("\nYou have moved North.\n");
                current_room = room_list[0];
            }
            else
            {
                printf("\nYou cannot go that way.\n");
            }
        }
        else if (strncmp(input, "south", 5) == 0 || strncmp(input, "South", 5) == 0)
        {
            if (current_room == 2 || current_room == 3)
            {
                printf("\nYou have moved South.\n");
                current_room = room_list[1];
            }
            else
            {
                printf("\nYou cannot go that way.\n");
            }
        }
        else if (strncmp(input, "east", 4) == 0 || strncmp(input, "East", 4) == 0)
        {
            if (current_room == 1 || current_room == 2 || current_room == 3)
            {
                printf("\nYou have moved East.\n");
                current_room = room_list[1];
            }
            else
            {
                printf("\nYou cannot go that way.\n");
            }
        }
        else if (strncmp(input, "west", 4) == 0 || strncmp(input, "West", 4) == 0)
        {
            if (current_room == 2 || current_room == 4)
            {
                printf("\nYou have moved West.\n");
                current_room = room_list[2];
            }
            else
            {
                printf("\nYou cannot go that way.\n");
            }
        }
        else
        {
            printf("\nInvalid direction.\n");
        }

        // Random event
        int event = random_number(1, 10);
        if (event <= 3)
        {
            printf("\nYou have encountered a ghost!\n");
            printf("You have been scared to death and died.\n");
            is_alive = false;
        }
        else if (event <= 6)
        {
            printf("\nYou have found a key!\n");
            printf("You can use this key to unlock a door.\n");
        }
        else if (event <= 9)
        {
            printf("\nYou hear a strange noise in the distance.\n");
        }
        else
        {
            printf("\nThe room is silent.\n");
        }
    }

    // End game message
    if (is_alive && current_room == 5)
    {
        printf("\nCongratulations! You have escaped the haunted house!\n");
    }
    else
    {
        printf("\nGAME OVER\n");
    }

    return 0;
}