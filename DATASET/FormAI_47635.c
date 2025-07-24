//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes
void clear_screen();
void wait_for_input();
void game_over();
void win_game();

int main()
{
    // Introduction
    printf("Welcome to 'The Quest for the Golden Key', a text-based adventure game!\n");
    printf("Your mission is to find the three pieces of the Golden Key and open the treasure chest to win the game.\n");
    printf("You are currently standing in front of a dark cave. Are you ready to begin?\n");
    wait_for_input();

    // Level 1 - The Cave
    clear_screen();
    printf("You enter the cave. It's dark and damp. You need to find a torch to light your way.\n");
    printf("As you walk deeper into the cave, you hear strange noises coming from the darkness.\n");
    wait_for_input();

    char choice[10];
    bool has_torch = false;
    int level = 1;
    while (true) {
        clear_screen();
        printf("LEVEL %d - The Cave\n", level);
        printf("You see two paths ahead of you. Which one will you take?\n");
        printf("1. Left path\n");
        printf("2. Right path\n");
        printf("3. Go back\n");
        fgets(choice, sizeof(choice), stdin);
        strtok(choice, "\n");

        if (strcmp(choice, "1") == 0) {
            printf("You follow the left path and come across a chest. Will you open it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            fgets(choice, sizeof(choice), stdin);
            strtok(choice, "\n");

            if (strcmp(choice, "1") == 0) {
                printf("The chest is empty.\n");
            } else {
                printf("You ignore the chest and continue on your journey.\n");
            }
        } else if (strcmp(choice, "2") == 0) {
            if (has_torch) {
                printf("You follow the right path and find a piece of the Golden Key!\n");
                printf("Congratulations, you have completed level %d!\n", level);
                level++;
                has_torch = false;
                wait_for_input();
                if (level > 3) {
                    win_game();
                    return 0;
                } else {
                    continue;
                }
            } else {
                printf("You need a torch to go down this path.\n");
                printf("You decide to turn back.\n");
                wait_for_input();
                continue;
            }
        } else if (strcmp(choice, "3") == 0) {
            if (level == 1) {
                printf("You cannot go back any further.\n");
            } else {
                level--;
                printf("You return to level %d.\n", level);
                wait_for_input();
            }
        } else {
            printf("Invalid input. Please try again.\n");
            wait_for_input();
        }

        if (!has_torch) {
            printf("You find a torch lying on the ground. Will you pick it up?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            fgets(choice, sizeof(choice), stdin);
            strtok(choice, "\n");

            if (strcmp(choice, "1") == 0) {
                printf("You pick up the torch.\n");
                has_torch = true;
            } else {
                printf("You leave the torch behind.\n");
            }
        }
    }

    return 0;
}

void clear_screen() {
    system("clear");
}

void wait_for_input() {
    printf("Press enter to continue...");
    getchar();
}

void game_over() {
    printf("GAME OVER\n");
    printf("You have failed in your quest. Better luck next time!\n");
}

void win_game() {
    printf("CONGRATULATIONS!\n");
    printf("You have found all three pieces of the Golden Key and opened the treasure chest.\n");
    printf("You are rich beyond your wildest dreams!\n");
}