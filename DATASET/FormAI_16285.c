//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Alan Touring
#include <stdio.h>

int main() {
    char user_input[50];
    int player_location = 1;

    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark cave.\n");
    printf("There are two paths ahead of you.\n");

    while(player_location != -1) {

        printf("\nWhat would you like to do? ");
        fgets(user_input, 50, stdin);

        if(strncmp(user_input, "go left", 7) == 0) {
            if(player_location == 1) {
                printf("You follow the left path and find a treasure!\n");
                printf("Congratulations! You win!\n");
                player_location = -1;
            }
            else if(player_location == 2) {
                printf("You follow the left path but are attacked by goblins. Game over.\n");
                player_location = -1;
            }
            else {
                printf("You can't go left from here.\n");
            }
        }

        else if(strncmp(user_input, "go right", 8) == 0) {
            if(player_location == 1) {
                printf("You follow the right path and are trapped in a spider's web. Game over.\n");
                player_location = -1;
            }
            else if(player_location == 2) {
                printf("You follow the right path and find an exit out of the cave. Congratulations! You win!\n");
                player_location = -1;
            }
            else {
                printf("You can't go right from here.\n");
            }
        }

        else if(strncmp(user_input, "inspect", 7) == 0) {
            if(player_location == 1) {
                printf("You see a glimmer in the corner of the room.\n");
            }
            else if(player_location == 2) {
                printf("You see a pile of bones in the corner of the room.\n");
            }
            else {
                printf("You can't inspect anything here.\n");
            }
        }

        else if(strncmp(user_input, "quit", 4) == 0) {
            player_location = -1;
        }

        else {
            printf("I'm sorry, I don't understand that command.\n");
        }
    }

    return 0;
}