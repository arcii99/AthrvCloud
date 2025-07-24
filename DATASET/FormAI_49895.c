//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void showMainMenu();
void startGame();
void enterRoom(int roomId);
void displayStatus();
void gameOver(bool win);

// Global variables
int currentRoom = 1;
bool hasKey = false;
bool hasLantern = false;

int main()
{
    showMainMenu();
    return 0;
}

void showMainMenu()
{
    printf("Welcome to the C Text-Based Adventure Game!\n\n");
    printf("1. Start game\n");
    printf("2. Exit\n\n");

    char input[50];
    fgets(input, 50, stdin);

    switch(atoi(input))
    {
        case 1:
            startGame();
            break;
        case 2:
            printf("Goodbye!\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            showMainMenu();
    }
}

void startGame()
{
    printf("\nYou wake up in a dimly lit dungeon. You can hear the sound of dripping water echoing off the walls.\n\n");
    enterRoom(currentRoom);
}

void enterRoom(int roomId)
{
    switch(roomId)
    {
        case 1:
            printf("You are in the first room. There are two doors, one to the left and one to the right.\n\n");
            break;
        case 2:
            printf("You are in the second room. There is a chest on the ground.\n\n");
            break;
        case 3:
            printf("You are in the third room. It is empty except for a key on the ground.\n\n");
            break;
        case 4:
            printf("You are in the fourth room. It is very dark in here. You can't see anything.\n\n");
            break;
        case 5:
            printf("You are in the fifth room. There is a lantern on the ground.\n\n");
            break;
        case 6:
            printf("You are in the sixth room. There is a locked door blocking your way.\n\n");
            break;
        case 7:
            printf("You have found the treasure chest! You win!\n");
            gameOver(true);
            break;
        default:
            printf("Invalid room id. Please try again.\n");
            displayStatus();
    }

    if(roomId != 7)
    {
        printf("Where do you want to go?\n");
        printf("1. Left door\n");
        printf("2. Right door\n");
        printf("3. Return to previous room\n");
        if(roomId == 6 && hasKey)
        {
            printf("4. Unlock door\n");
        }
        printf("\n");

        char input[50];
        fgets(input, 50, stdin);

        switch(atoi(input))
        {
            case 1:
                if(roomId == 1)
                {
                    enterRoom(3);
                } else if (roomId == 4)
                {
                    enterRoom(5);   
                } else
                {
                    printf("Invalid input. Please try again.\n");
                    enterRoom(roomId);
                }
                break;
            case 2:
                if(roomId == 1)
                {
                    enterRoom(2);
                } else if (roomId == 5)
                {
                    enterRoom(4);   
                } else
                {
                    printf("Invalid input. Please try again.\n");
                    enterRoom(roomId);
                }
                break;
            case 3:
                if(roomId == 2 || roomId == 3 || roomId == 5 || roomId == 6)
                {
                    enterRoom(1);
                } else if (roomId == 4)
                {
                    printf("You can't go back that way. It's too dark to navigate.\n");
                    enterRoom(roomId);   
                } else
                {
                    printf("Invalid input. Please try again.\n");
                    enterRoom(roomId);
                }
                break;
            case 4:
                if(roomId == 6 && hasKey)
                {
                    printf("You unlock the door!\n");
                    enterRoom(7);
                }
                else
                {
                    printf("Invalid input. Please try again.\n");
                    enterRoom(roomId);
                }
                break;
            default:
                printf("Invalid input. Please try again.\n");
                enterRoom(roomId);
        }
    }
}

void displayStatus()
{
    printf("Current room: %d\n", currentRoom);
    printf("Inventory:\n");
    if(hasKey)
    {
        printf(" - Key\n");
    }
    if(hasLantern)
    {
        printf(" - Lantern\n");
    }
    printf("\n");
    enterRoom(currentRoom);
}

void gameOver(bool win)
{
    if(win)
    {
        printf("Congratulations! You have won the game!\n");
    }
    else
    {
        printf("Game over. Better luck next time!\n");
    }
}