//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int ghost_pos = rand() % 10 + 1;
    int player_pos = 1;
    int moves_left = 10;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Your goal is to find the ghost before you run out of moves.\n");
    printf("You have %d moves left.\n", moves_left);

    while (moves_left > 0) {
        printf("You are currently in room %d.\n", player_pos);

        if (player_pos == ghost_pos) {
            printf("You found the ghost! Congrats!\n");
            return 0;
        }

        printf("Enter the room number you want to go: ");
        int room_choice;
        scanf("%d", &room_choice);

        while (room_choice < 1 || room_choice > 10 || room_choice == player_pos) {
            printf("Invalid room choice. Choose another room: ");
            scanf("%d", &room_choice);
        }

        player_pos = room_choice;
        moves_left--;

        printf("You have %d moves left.\n", moves_left);

        if (moves_left == 0) {
            printf("You ran out of moves. Game over.\n");
            return 0;
        }
    }

    return 0;
}