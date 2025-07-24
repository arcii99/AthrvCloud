//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

int main() {
    char player_name[MAX_INPUT_LENGTH];
    char player_input[MAX_INPUT_LENGTH];

    printf("Welcome adventurer! What is your name?\n");
    fgets(player_name, MAX_INPUT_LENGTH, stdin);

    printf("Greetings %s! You find yourself in a dark dungeon...\n", player_name);
    printf("You see two doors in front of you. Which one do you choose? (left/right)\n");

    fgets(player_input, MAX_INPUT_LENGTH, stdin);

    if(strcmp(player_input, "left\n") == 0) {
        printf("You open the left door and find a treasure chest! You win!\n");
    } else if(strcmp(player_input, "right\n") == 0) {
        printf("You open the right door and are immediately attacked by a giant spider! Fight or flee? (fight/flee)\n");

        fgets(player_input, MAX_INPUT_LENGTH, stdin);

        if(strcmp(player_input, "fight\n") == 0) {
            printf("You battle the spider and emerge victorious! But you are wounded...\n");
            printf("You see two potions on the ground. One is red, one is blue. Which one do you choose? (red/blue)\n");

            fgets(player_input, MAX_INPUT_LENGTH, stdin);

            if(strcmp(player_input, "red\n") == 0) {
                printf("You drink the red potion and your wound heals. You win!\n");
            } else if(strcmp(player_input, "blue\n") == 0) {
                printf("You drink the blue potion and immediately feel weaker. You lose...\n");
            } else {
                printf("Invalid input. You die...\n");
            }
        } else if(strcmp(player_input, "flee\n") == 0) {
            printf("You run away from the spider, but in your haste you fall into a pit. You die...\n");
        } else {
            printf("Invalid input. You die...\n");
        }
    } else {
        printf("Invalid input. You die...\n");
    }

    return 0;
}