//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <string.h>

// function for getting user input and checking for valid input
void getUserInput(char input[], int inputSize, char validOptions[]) {
    int valid = 0;
    while (!valid) {
        printf(" > ");
        fgets(input, inputSize, stdin);
        input[strcspn(input, "\n")] = 0; // remove '\n' character from input
        for (int i = 0; i < strlen(validOptions); i++) {
            if (*input == validOptions[i]) {
                valid = 1;
            }
        }
        if (!valid) {
            printf("Invalid input. Please choose one of the following options: %s\n", validOptions);
        }
    }
}

// function for handling the player's next move
void movePlayer(char playerPosition[], char input[]) {
    if (strcmp(input, "n") == 0) {
        strcpy(playerPosition, "north");
    } else if (strcmp(input, "s") == 0) {
        strcpy(playerPosition, "south");
    } else if (strcmp(input, "e") == 0) {
        strcpy(playerPosition, "east");
    } else if (strcmp(input, "w") == 0) {
        strcpy(playerPosition, "west");
    }
}

int main() {

    // game variables
    char playerPosition[6] = "start";
    char input[11];
    int foundTreasure = 0;
    int monsterDefeated = 0;

    // game introduction
    printf("Welcome to Text-Based Adventure Game!\n");
    printf("Your goal is to explore the dungeon, defeat the monster, and find the treasure.\n");
    printf("You are currently at the start of the dungeon.\n");

    while (!foundTreasure && !monsterDefeated) {
        // display current room information and options for next move
        if (strcmp(playerPosition, "start") == 0) {
            printf("\nYou are at the entrance of the dungeon.\n");
            printf("You can go north (n) to enter the dungeon or south (s) to exit.\n");
            getUserInput(input, 11, "ns");
            movePlayer(playerPosition, input);
        } else if (strcmp(playerPosition, "north") == 0) {
            printf("\nYou have entered the dungeon.\n");
            printf("You can go north (n), east (e), or west (w).\n");
            getUserInput(input, 11, "new");
            movePlayer(playerPosition, input);
        } else if (strcmp(playerPosition, "south") == 0) {
            printf("\nYou have exited the dungeon.\n");
            printf("Game over.\n");
            return 0;
        } else if (strcmp(playerPosition, "east") == 0) {
            printf("\nYou have encountered a monster!\n");
            printf("You can fight the monster (f) or run away (r).\n");
            getUserInput(input, 11, "fr");
            if (strcmp(input, "f") == 0) {
                printf("You have defeated the monster and gained access to the treasure room!\n");
                monsterDefeated = 1;
            } else if (strcmp(input, "r") == 0) {
                printf("You have successfully run away from the monster.\n");
                strcpy(playerPosition, "north");
            }
        } else if (strcmp(playerPosition, "west") == 0) {
            printf("\nYou have found a treasure!\n");
            printf("Congratulations, you have won the game!\n");
            foundTreasure = 1;
        }
    }

    return 0;

}