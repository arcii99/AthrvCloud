//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printIntro();
void printHelp();
void printWin();
void printLose();
void printError();

int main()
{
    char input[20];
    int inventory[3] = {0, 0, 0};
    int location = 0;
    printIntro();
    while (1)
    {
        printf("\n> ");
        scanf("%s", input);
        if (strcmp(input, "north") == 0)
        {
            if (location == 0)
            {
                location = 1;
                printf("You have moved north.\n");
            }
            else if (location == 2 && inventory[0] == 1)
            {
                location = 3;
                printf("You unlocked the door with the key and moved north.\n");
            }
            else
            {
                printError();
            }
        }
        else if (strcmp(input, "east") == 0)
        {
            if (location == 1 && inventory[1] == 1)
            {
                location = 2;
                printf("You unlocked the chest with the key and moved east.\n");
            }
            else
            {
                printError();
            }
        }
        else if (strcmp(input, "south") == 0)
        {
            if (location == 1 || location == 3)
            {
                location = 0;
                printf("You have moved south.\n");
            }
            else
            {
                printError();
            }
        }
        else if (strcmp(input, "west") == 0)
        {
            if (location == 0)
            {
                location = 3;
                printf("You have moved west.\n");
            }
            else
            {
                printError();
            }
        }
        else if (strcmp(input, "look") == 0)
        {
            if (location == 0)
            {
                printf("You are in a forest.\n");
            }
            else if (location == 1)
            {
                printf("You are in a cave. There is a chest here.\n");
            }
            else if (location == 2)
            {
                printf("You are in a room. There is a locked door here.\n");
            }
            else if (location == 3)
            {
                printf("You are in a hallway.\n");
            }
        }
        else if (strcmp(input, "take") == 0)
        {
            if (location == 1)
            {
                inventory[1] = 1;
                printf("You have taken the key.\n");
            }
            else if (location == 3)
            {
                inventory[0] = 1;
                printf("You have taken the torch.\n");
            }
            else
            {
                printError();
            }
        }
        else if (strcmp(input, "help") == 0)
        {
            printHelp();
        }
        else if (strcmp(input, "quit") == 0)
        {
            exit(0);
        }
        else
        {
            printError();
        }
        if (location == 2 && inventory[0] == 1 && inventory[1] == 1)
        {
            printWin();
            exit(0);
        }
        else if (location == 1 && inventory[2] == 1)
        {
            printLose();
            exit(0);
        }
    }
}

void printIntro()
{
    printf("Welcome adventurer! You find yourself in a mysterious forest, unsure of how you got here.\n");
    printf("As you wander through the trees, you come upon a dark cave.\n");
    printf("Do you dare to enter?\n");
    printf("Type 'help' if you need it.\n");
}

void printHelp()
{
    printf("Your commands are: 'north', 'east', 'south', 'west', 'look', 'take', 'help' and 'quit'.\n");
    printf("You can take the torch, the key, and something else you'll discover...\n");
    printf("You win if you unlock the door and leave the room. You lose if you open the chest.\n");
}

void printWin()
{
    printf("You unlocked the door and escaped the mysterious place! Well done!\n");
}

void printLose()
{
    printf("You opened the chest, and a monster killed you. You have failed...\n");
}

void printError()
{
    printf("I don't understand that command. Type 'help' if you need it.\n");
}