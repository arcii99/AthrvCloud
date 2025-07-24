//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void startGame();
void intro();
void room1();
void room2();
void room3();
void room4();
void room5();
void ending();

int main()
{
    startGame();
    return 0;
}

void startGame()
{
    char userInput[50];
    printf("Welcome to the Escape Game! Press enter to begin.");
    getchar();
    intro();
}

void intro()
{
    printf("You wake up in a dark, cold room with no recollection of how you got there.\n");
    printf("The door is locked and the only thing in the room is a note on the floor.\n");
    printf("What do you do?\n");
    printf("Type 'read note' to read the note or 'look around' to search the room.\n");
    char userInput[50];
    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "read note") == 0)
    {
        printf("The note reads: 'To escape, you must find 5 keys located in 5 different rooms. GOOD LUCK.'\n");
        printf("Type 'open door' to try and open the door or 'look around' to search the room.\n");
    }
    else if(strcmp(userInput, "look around") == 0)
    {
        printf("You search the room and find a key hidden under the bed.\n");
        printf("Type 'open door' to try and open the door or 'look around' to search the room again.\n");
    }
    else
    {
        printf("Invalid input, please try again.\n");
        intro();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "open door") == 0)
    {
        printf("You insert the key into the lock and the door unlocks.\n");
        printf("You leave the room and enter a hallway. The hallway splits into 2 paths.\n");
        printf("Which path do you take? Type 'left' or 'right'.\n");
    }
    else if(strcmp(userInput, "look around") == 0)
    {
        printf("You search the room but find nothing else of interest.\n");
        printf("Type 'open door' to try and open the door or 'look around' to search the room again.\n");
    }
    else
    {
        printf("Invalid input, please try again.\n");
        intro();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "left") == 0)
    {
        room1();
    }
    else if(strcmp(userInput, "right") == 0)
    {
        room2();
    }
    else
    {
        printf("Invalid input, please try again.\n");
        intro();
    }
}

void room1()
{
    printf("You enter a room with a table and 3 locked cabinets.\n");
    printf("There is a piece of paper on the table with a riddle on it.\n");
    printf("The riddle reads: 'I am always hungry, I must always be fed. The finger I touch will soon turn red. What am I?'\n");
    printf("Type your answer:");
    char userInput[50];
    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "fire") == 0)
    {
        printf("Correct! A cabinet has unlocked and revealed a key. Take the key and move onto the next room.\n");
        printf("Type 'next' to move onto the next room.\n");
    }
    else
    {
        printf("Incorrect! Try again.\n");
        room1();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "next") == 0)
    {
        room3();
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room1();
    }
}

void room2()
{
    printf("You enter a room filled with mirrors.\n");
    printf("You see a reflection of yourself in a mirror, but it looks slightly different.\n");
    printf("Type 'investigate' to investigate the mirror or 'look around' to search the room.\n");
    char userInput[50];
    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "investigate") == 0)
    {
        printf("You touch the mirror and it shatters, revealing a key hidden inside it.\n");
        printf("Type 'next' to move onto the next room.\n");
    }
    else if(strcmp(userInput, "look around") == 0)
    {
        printf("You search the room but find nothing else of interest.\n");
        printf("Type 'investigate' to investigate the mirror or 'look around' to search the room again.\n");
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room2();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "next") == 0)
    {
        room4();
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room2();
    }
}

void room3()
{
    printf("You enter a room with a piano.\n");
    printf("There is a note on the piano that reads: 'To unlock the cabinet, you must play the correct tune on the piano.'\n");
    printf("Type 'play' to play the piano or 'look around' to search the room.\n");
    char userInput[50];
    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "play") == 0)
    {
        printf("You play the tune and a cabinet unlocks, revealing a key. Take the key and move onto the next room.\n");
        printf("Type 'next' to move onto the next room.\n");
    }
    else if(strcmp(userInput, "look around") == 0)
    {
        printf("You search the room but find nothing else of interest.\n");
        printf("Type 'play' to play the piano or 'look around' to search the room again.\n");
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room3();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "next") == 0)
    {
        room5();
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room3();
    }
}

void room4()
{
    printf("You enter a room with a safe.\n");
    printf("There is a note on the safe that reads: 'To unlock the safe, you must enter the correct code.'\n");
    printf("Type 'enter code' to enter the code or 'look around' to search the room.\n");
    char userInput[50];
    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "enter code") == 0)
    {
        printf("You enter the correct code and the safe unlocks, revealing a key. Take the key and move onto the next room.\n");
        printf("Type 'next' to move onto the next room.\n");
    }
    else if(strcmp(userInput, "look around") == 0)
    {
        printf("You search the room but find nothing else of interest.\n");
        printf("Type 'enter code' to enter the code or 'look around' to search the room again.\n");
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room4();
    }

    scanf("%[^\n]%*c", userInput);
    if(strcmp(userInput, "next") == 0)
    {
        room5();
    }
    else
    {
        printf("Invalid input, please try again.\n");
        room4();
    }
}

void room5()
{
    printf("You enter a room with a locked door.\n");
    printf("You use all the keys you have found to unlock the door and escape.\n");
    ending();
}

void ending()
{
    printf("Congratulations, you have successfully escaped!\n");
}