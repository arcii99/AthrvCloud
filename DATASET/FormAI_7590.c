//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to check if the player has won
bool hasWon(char* playerInput) {
    return strcmp(playerInput, "open door") == 0;
}

int main() {
    // Introduction
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself standing in front of a mysterious house.\n");
    printf("What do you do?\n");

    // Player Input
    char playerInput[50];
    fgets(playerInput, 50, stdin);
    strtok(playerInput, "\n");

    // Game Loop
    while(true) {
        // Check if the player has won
        if(hasWon(playerInput)) {
            printf("Congratulations, you have opened the door and won the game!\n");
            break;
        }

        // Ask the player what to do next
        printf("What do you do next?\n");
        fgets(playerInput, 50, stdin);
        strtok(playerInput, "\n");
    }

    // End of Game
    printf("Thank you for playing the Text-Based Adventure Game!\n");
    return 0;
}