//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_STRING_LENGTH = 100;

void printIntro() {
    printf("You find yourself standing in front of a mysterious cave. The entrance is covered in vines and moss, and you can't see inside. Do you dare to enter? (yes/no)\n");
}

void printOptions() {
    printf("What would you like to do?\n");
    printf("1. Go deeper into the cave\n");
    printf("2. Look around outside the cave\n");
    printf("3. Try to leave the area\n");
}

void printExit() {
    printf("You have successfully escaped the cave. Congratulations!\n");
}

void printDeath() {
    printf("Unfortunately, you have died. Game over.\n");
}

int main() {
    char userInput[MAX_STRING_LENGTH];
    int gameState = 0;

    printf("Welcome to the Cave Adventure Game!\n");

    while (gameState != -1) {
        switch (gameState) {
            case 0:
                printIntro();
                fgets(userInput, MAX_STRING_LENGTH, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input
                if (strcmp(userInput, "yes") == 0) {
                    printf("You enter the cave...\n");
                    gameState = 1;
                } else if (strcmp(userInput, "no") == 0) {
                    printf("You decide not to enter the cave and turn around.\n");
                    gameState = -1; // end game
                } else {
                    printf("I don't understand that command. Please type 'yes' or 'no'.\n");
                }
                break;

            case 1:
                printf("You come across a fork in the road. Do you go left or right?\n");
                fgets(userInput, MAX_STRING_LENGTH, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input
                if (strcmp(userInput, "left") == 0) {
                    printf("You head down the left path.\n");
                    gameState = 2;
                } else if (strcmp(userInput, "right") == 0) {
                    printf("You head down the right path.\n");
                    gameState = 3;
                } else {
                    printf("I don't understand that command. Please type 'left' or 'right'.\n");
                }
                break;

            case 2:
                printf("You stumble upon a treasure chest! Do you open it? (yes/no)\n");
                fgets(userInput, MAX_STRING_LENGTH, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input
                if (strcmp(userInput, "yes") == 0) {
                    printf("You open the chest and find a valuable artifact inside. Congratulations!\n");
                    gameState = -1; // end game
                } else if (strcmp(userInput, "no") == 0) {
                    printf("You decide not to open the chest and continue on your journey.\n");
                    gameState = 1;
                } else {
                    printf("I don't understand that command. Please type 'yes' or 'no'.\n");
                }
                break;

            case 3:
                printf("You come across a fearsome dragon guarding the exit of the cave. What do you do?\n");
                printOptions();
                fgets(userInput, MAX_STRING_LENGTH, stdin);
                userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input
                if (strcmp(userInput, "1") == 0) {
                    printf("You bravely charge towards the dragon and manage to slay it! Congratulations!\n");
                    gameState = -1; // end game
                } else if (strcmp(userInput, "2") == 0) {
                    printf("You search around the outside of the cave and find a hidden path that leads to the other side of the dragon. You escape!\n");
                    gameState = -1; // end game
                } else if (strcmp(userInput, "3") == 0) {
                    printf("You try to leave the area but the dragon quickly catches up to you and devours you whole. Sorry!\n");
                    printDeath();
                    gameState = -1; // end game
                } else {
                    printf("I don't understand that command. Please select an option by typing the corresponding number.\n");
                }
                break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}