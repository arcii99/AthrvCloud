//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    system("cls");
}

void print_intro() {
    clear_screen();
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Your goal is to find the treasure located in the dungeon.\n");
    printf("Are you ready? Let's begin!\n");
}

void print_game_over() {
    clear_screen();
    printf("Game over.\n");
}

void print_victory() {
    clear_screen();
    printf("Congratulations! You have found the treasure.\n");
}

int main() {
    int room_number = 1;
    char user_input[20];

    print_intro();

    while (1) {
        if (room_number == 1) {
            printf("You are in a dark room.\n");
            printf("There are two doors, 'north' and 'east'.\n");
            printf("What do you want to do?\n");

            fgets(user_input, sizeof(user_input), stdin);
            user_input[strcspn(user_input, "\n")] = 0;

            if (strcmp(user_input, "north") == 0) {
                room_number = 2;
            } else if (strcmp(user_input, "east") == 0) {
                room_number = 4;
            } else {
                printf("Invalid command\n");
            }
        } else if (room_number == 2) {
            printf("You are in a corridor.\n");
            printf("There are two doors, 'south' and 'east'.\n");
            printf("What do you want to do?\n");

            fgets(user_input, sizeof(user_input), stdin);
            user_input[strcspn(user_input, "\n")] = 0;

            if (strcmp(user_input, "south") == 0) {
                room_number = 1;
            } else if (strcmp(user_input, "east") == 0) {
                room_number = 3;
            } else {
                printf("Invalid command\n");
            }
        } else if (room_number == 3) {
            printf("You are in a room with a monster.\n");
            printf("You can 'attack' or 'flee'.\n");
            printf("What do you want to do?\n");

            fgets(user_input, sizeof(user_input), stdin);
            user_input[strcspn(user_input, "\n")] = 0;

            if (strcmp(user_input, "attack") == 0) {
                printf("You defeated the monster!\n");
                room_number = 5;
            } else if (strcmp(user_input, "flee") == 0) {
                room_number = 2;
            } else {
                printf("Invalid command\n");
            }
        } else if (room_number == 4) {
            printf("You are in an empty room.\n");
            printf("There is a 'key' on the ground.\n");
            printf("What do you want to do?\n");

            fgets(user_input, sizeof(user_input), stdin);
            user_input[strcspn(user_input, "\n")] = 0;

            if (strcmp(user_input, "key") == 0) {
                printf("You have picked up the key!\n");
                room_number = 2;
            } else {
                printf("Invalid command\n");
            }
        } else if (room_number == 5) {
            print_victory();
            break;
        } else {
            print_game_over();
            break;
        }
    }

    return 0;
}