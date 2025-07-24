//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // Initialize random seed

    int room = 0;  // Initialize room number to 0
    bool has_key = false;  // Initialize key flag to false

    printf("You have entered a haunted house. Your goal is to find the key and escape. Good luck!\n");

    while (true)  // Infinite loop until player escapes or dies
    {
        room = rand() % 10 + 1;  // Random number from 1 to 10

        switch (room)
        {
            case 1: printf("You are in the foyer. There is a dusty coat rack and an old piano.\n"); break;
            case 2: printf("You are in the kitchen. The sink is filled with dirty dishes and there is a creepy doll on the counter.\n"); break;
            case 3: printf("You are in the dining room. The table is set for a formal dinner, but there is no food.\n"); break;
            case 4: printf("You are in the living room. The lights flicker and you hear strange noises.\n"); break;
            case 5: printf("You are in the library. The shelves are filled with old books and cobwebs.\n"); break;
            case 6: printf("You are in the study. There is a desk with papers scattered about and a locked drawer.\n"); break;
            case 7: printf("You are in the bathroom. The tub is filled with murky water and there is a strange smell in the air.\n"); break;
            case 8: printf("You are in the bedroom. The bed is made, but there is nobody in sight.\n"); break;
            case 9:
                if (has_key == true)
                {
                    printf("You have found the front door. You insert the key and escape the haunted house!\n");
                    return 0;
                }
                else
                {
                    printf("You have found the front door, but it is locked. You need to find the key.\n");
                }
                break;
            case 10:
                printf("You have stumbled upon a ghost! You die.\n");
                return 0;
        }

        if (room == 6)  // Check if player is in the study
        {
            printf("You found a key in the unlocked drawer!\n");
            has_key = true;  // Set key flag to true
        }
    }

    return 0;
}