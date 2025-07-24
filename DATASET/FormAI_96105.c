//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void printIntro();
void printRoom(int);
int rollDice();
void playGame();

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator with current time
    printIntro(); // Print introduction
    playGame(); // Start the game
    return 0;
}

// Function to print introduction message
void printIntro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("This is a game of luck and strategy.\n");
    printf("You will be taken through a series of rooms.\n");
    printf("In each room, you will encounter different challenges.\n");
    printf("You must collect at least 10 coins to escape the haunted house.\n");
    printf("Good luck!\n\n");
}

// Function to print room description based on room number
void printRoom(int roomNumber) {
    switch(roomNumber) {
        case 0:
            printf("You are standing in the entrance hall.\n");
            printf("There are cobwebs and dust everywhere.\n");
            printf("You see a dusty old chest in the corner.\n");
            printf("You can see three doors leading to different rooms.\n");
            printf("Which door will you choose?\n");
            printf("1. Door on the left\n");
            printf("2. Door in the middle\n");
            printf("3. Door on the right\n");
            break;
        case 1:
            printf("You are in a library.\n");
            printf("Books are strewn all over the room.\n");
            printf("You notice a bookshelf that seems to be out of place.\n");
            printf("What will you investigate?\n");
            printf("1. The books on the shelves\n");
            printf("2. The out-of-place bookshelf\n");
            break;
        case 2:
            printf("You are in a kitchen.\n");
            printf("There are piles of dirty dishes everywhere.\n");
            printf("You notice a fridge with a sticky note on it.\n");
            printf("What does it say?\n");
            printf("1. Help yourself to the food\n");
            printf("2. Stay away from the fridge\n");
            break;
        case 3:
            printf("You are in a bedroom.\n");
            printf("There is a large bed with satin sheets.\n");
            printf("You notice that there is someone sleeping under the sheets.\n");
            printf("What will you do?\n");
            printf("1. Wake the sleeper\n");
            printf("2. Leave the room quietly\n");
            break;
        case 4:
            printf("You are in a bathroom.\n");
            printf("There is a bathtub with a shower curtain.\n");
            printf("You hear a strange noise coming from the bathtub.\n");
            printf("What will you do?\n");
            printf("1. Pull back the shower curtain\n");
            printf("2. Ignore the noise and leave the room\n");
            break;
    }
}

// Function to roll a six-sided dice
int rollDice() {
    return rand() % 6 + 1;
}

// Function to play the game
void playGame() {
    int room = 0; // Starting room
    int coins = 0; // Number of coins collected
    char input[10]; // User input buffer
    
    while(coins < 10 && room < 5) {
        printRoom(room); // Print room description
        
        // Get user input
        printf("> ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        // Handle user input for each room
        switch(room) {
            case 0:
                if(strcmp(input, "1") == 0) {
                    printf("You enter the room on the left.\n");
                    printf("You find a coin on the floor!\n");
                    coins++;
                    room = 1;
                } else if(strcmp(input, "2") == 0) {
                    printf("You enter the room in the middle.\n");
                    room = 2;
                } else if(strcmp(input, "3") == 0) {
                    printf("You enter the room on the right.\n");
                    printf("You find a coin on the dresser!\n");
                    coins++;
                    room = 3;
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
            case 1:
                if(strcmp(input, "1") == 0) {
                    int roll = rollDice(); // Roll dice
                    printf("You search the books on the shelves.\n");
                    printf("You find a coin behind one of the books!\n");
                    coins++;
                    printf("You roll the dice and get a %d.\n", roll);
                    if(roll > 3) {
                        printf("You hear a creaking noise.\n");
                        printf("A secret door opens!\n");
                        room = 4;
                    } else {
                        printf("Nothing else happens.\n");
                        room = 0;
                    }
                } else if(strcmp(input, "2") == 0) {
                    printf("You investigate the out-of-place bookshelf.\n");
                    printf("You find a treasure chest!\n");
                    printf("You try to open it but it's locked.\n");
                    printf("You need a key to open it.\n");
                    printf("You leave the room.\n");
                    room = 0;
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
            case 2:
                if(strcmp(input, "1") == 0) {
                    printf("You help yourself to the food.\n");
                    printf("You feel queasy.\n");
                    printf("You lose a coin!\n");
                    coins--;
                    room = 0;
                } else if(strcmp(input, "2") == 0) {
                    printf("You stay away from the fridge.\n");
                    room = 0;
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
            case 3:
                if(strcmp(input, "1") == 0) {
                    printf("You wake the sleeper.\n");
                    printf("The sleeper turns out to be a ghost!\n");
                    printf("It scares you and you run away.\n");
                    room = 0;
                } else if(strcmp(input, "2") == 0) {
                    printf("You leave the room quietly.\n");
                    printf("You hear a coin fall out of your pocket!\n");
                    coins++;
                    room = 0;
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
            case 4:
                if(strcmp(input, "1") == 0) {
                    printf("You pull back the shower curtain.\n");
                    printf("There is a coin in the drain!\n");
                    coins++;
                    room = 0;
                } else if(strcmp(input, "2") == 0) {
                    printf("You ignore the noise and leave the room.\n");
                    room = 0;
                } else {
                    printf("Invalid input. Try again.\n");
                }
                break;
        }
    }
    
    // End of game
    if(coins >= 10) {
        printf("Congratulations! You have collected enough coins to escape the haunted house!\n");
    } else {
        printf("Sorry, you were unable to collect enough coins to escape the haunted house.\n");
    }
}