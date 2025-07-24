//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Linux Adventure Game!\n");
    printf("You find yourself on a command line interface.\n");
    printf("In front of you lies a challenge to restore the lost kernel...\n");
    printf("Type 'help' if you need some assistance.\n");

    char input[100];
    while (1) {
        printf(">> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        if (strcmp(input, "help") == 0) {
            printf("You can type: 'inventory' to check your items, 'go' to move to a new place, 'find' to search for an item, 'combine' to combine items, and 'quit' to exit the game.\n");
        } else if (strcmp(input, "inventory") == 0) {
            printf("You have nothing in your inventory.\n");
        } else if (strcmp(input, "go") == 0) {
            printf("Where do you want to go? Type 'north', 'south', 'east', or 'west'.\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character

            if (strcmp(input, "north") == 0) {
                printf("You cannot go that way.\n");
            } else if (strcmp(input, "south") == 0) {
                printf("You cannot go that way.\n");
            } else if (strcmp(input, "east") == 0) {
                printf("You cannot go that way.\n");
            } else if (strcmp(input, "west") == 0) {
                printf("You find yourself in a room filled with old computer parts.\n");
            } else {
                printf("Invalid input.\n");
            }
        } else if (strcmp(input, "find") == 0) {
            printf("You search the room and find a broken motherboard.\n");
        } else if (strcmp(input, "combine") == 0) {
            printf("What two items do you want to combine?\n");
            fgets(input, 100, stdin);
            input[strcspn(input, "\n")] = 0; // Remove newline character
            char item1[50];
            char item2[50];
            sscanf(input, "%s %s", item1, item2);

            if (strcmp(item1, "broken") == 0 && strcmp(item2, "motherboard") == 0) {
                printf("You combine the broken motherboard with a spare one and manage to restore the lost kernel!\n");
                printf("Congratulations, you have completed the Linux Adventure Game.\n");
                exit(0);
            } else {
                printf("You cannot combine those items.\n");
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Thank you for playing the Linux Adventure Game.\n");
            exit(0);
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}