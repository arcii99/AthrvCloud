//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create a function to randomly generate events in the haunted house
void generateEvent()
{
    int event = rand() % 4;
    switch(event)
    {
        case 0:
            printf("You hear a creaking sound coming from upstairs.\n");
            break;
        case 1:
            printf("The lights flicker and then go out.\n");
            break;
        case 2:
            printf("You feel a cold breeze on the back of your neck.\n");
            break;
        case 3:
            printf("You see a shadow move out of the corner of your eye.\n");
            break;
        default:
            printf("Nothing strange happens....yet.\n");
    }
}

int main()
{
    srand(time(NULL)); // Initialize random seed

    int playerChoice;
    int hasKey = 0;
    int hasWon = 0;

    // Set up the game
    printf("\nWelcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of an old, creepy mansion. As you look around, you realize that this is the perfect opportunity to test your courage and bravery.\n");
    printf("Do you dare to enter? Press 1 for yes, 2 for no.\n");
    scanf("%d", &playerChoice);

    if(playerChoice == 2)
    {
        printf("\nYou've chickened out. Game over.\n");
        return 0;
    }
    else if(playerChoice != 1)
    {
        printf("\nSorry, I didn't understand your choice. Game over.\n");
        return 0;
    }

    // First room
    printf("\nYou enter the mansion and find yourself in a dark foyer. A strange feeling creeps over you, as if you're being watched.\n");
    generateEvent();
    printf("You see three doorways: one to your left, one to your right, and one straight ahead.\n");
    printf("Which one do you choose? Press 1 for left, 2 for center, and 3 for right.\n");
    scanf("%d", &playerChoice);

    if(playerChoice == 1)
    {
        printf("\nYou enter a dark library. The air is thick with dust and the bookshelves loom ominously along the walls. You see a key on a nearby table. Do you take it? Press 1 for yes, 2 for no.\n");
        scanf("%d", &playerChoice);

        if(playerChoice == 1)
        {
            printf("\nYou take the key. It might come in handy later.\n");
            hasKey = 1;
        }
        else if(playerChoice != 2)
        {
            printf("\nSorry, I didn't understand your choice. Game over.\n");
            return 0;
        }
    }
    else if(playerChoice != 2 && playerChoice != 3)
    {
        printf("\nSorry, I didn't understand your choice. Game over.\n");
        return 0;
    }

    // Second room
    printf("\nYou enter a large, dimly lit parlor. The furniture is covered in sheets and cobwebs hang from the ceiling. You see a door across the room. Do you try to open it? Press 1 for yes, 2 for no.\n");
    scanf("%d", &playerChoice);

    if(playerChoice == 1)
    {
        if(hasKey == 1)
        {
            printf("\nYou use the key to open the door. As you push it open, you feel a strange gust of wind. You see a narrow staircase leading up.\n");
            hasKey = 0; // Use up key
        }
        else
        {
            printf("\nThe door is locked. You'll need to find a key.\n");
        }
    }
    else if(playerChoice != 2)
    {
        printf("\nSorry, I didn't understand your choice. Game over.\n");
        return 0;
    }

    // Third room
    printf("\nYou cautiously climb up the staircase and find yourself in a dusty attic. The air is stale and the floorboards creak beneath your feet. You see a chest in the corner of the room. Do you try to open it? Press 1 for yes, 2 for no.\n");
    scanf("%d", &playerChoice);

    if(playerChoice == 1)
    {
        printf("\nYou slowly approach the chest and pry it open. Inside, you find a dusty old map. It appears to show a hidden passage leading out of the house. Do you take the map? Press 1 for yes, 2 for no.\n");
        scanf("%d", &playerChoice);
        if(playerChoice == 1)
        {
            printf("\nYou take the map. Hopefully it will lead you to safety.\n");
            hasWon = 1;
        }
        else if(playerChoice != 2)
        {
            printf("\nSorry, I didn't understand your choice. Game over.\n");
            return 0;
        }
    }
    else if(playerChoice != 2)
    {
        printf("\nSorry, I didn't understand your choice. Game over.\n");
        return 0;
    }

    // Final room
    if(hasWon == 1)
    {
        printf("\nYou use the map to find a hidden passage leading out of the house. As you step outside, you breathe a sigh of relief. You've made it out alive!\n");
    }
    else
    {
        printf("\nAs you stumble around in the attic, you hear strange noises coming from below. Suddenly, the floor gives way and you find yourself falling...\n");
        printf("You wake up hours later, battered and bruised. You're not sure how, but somehow you've survived.\n");
    }

    printf("\nThanks for playing the Haunted House Simulator!\n");

    return 0;
}