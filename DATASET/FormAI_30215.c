//FormAI DATASET v1.0 Category: Table Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Randomly generates a number between min and max (inclusive) */
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Checks if the given position is the winning position */
bool is_winning_position(int position) {
    return position == 100;
}

/* Moves the player's position forward by dice_roll */
int move_player(int position, int dice_roll) {
    position += dice_roll;
    /* If the new position exceeds the winning position, return the previous position */
    if (position > 100) {
        position -= dice_roll;
    }
    /* If the player lands on a ladder, move them up */
    if (position == 4) {
        position = 14;
    } else if (position == 9) {
        position = 31;
    } else if (position == 20) {
        position = 38;
    } else if (position == 28) {
        position = 84;
    } else if (position == 40) {
        position = 59;
    } else if (position == 51) {
        position = 67;
    } else if (position == 63) {
        position = 81;
    } else if (position == 71) {
        position = 91;
    }
    /* If the player lands on a snake, move them down */
    if (position == 17) {
        position = 7;
    } else if (position == 54) {
        position = 34;
    } else if (position == 62) {
        position = 19;
    } else if (position == 64) {
        position = 60;
    } else if (position == 87) {
        position = 24;
    } else if (position == 93) {
        position = 73;
    } else if (position == 95) {
        position = 75;
    } else if (position == 99) {
        position = 78;
    }
    return position;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int player1_position = 0;
    int player2_position = 0;
    bool player1_turn = true;

    while (!is_winning_position(player1_position) && !is_winning_position(player2_position)) {
        int dice_roll = random_int(1, 6); // Roll a 6-sided dice
        printf("Player %d rolled a %d\n", player1_turn ? 1 : 2, dice_roll);
        if (player1_turn) {
            player1_position = move_player(player1_position, dice_roll);
            printf("Player 1 moved to position %d\n", player1_position);
        } else {
            player2_position = move_player(player2_position, dice_roll);
            printf("Player 2 moved to position %d\n", player2_position);
        }
        player1_turn = !player1_turn; // Switch turns
    }

    if (is_winning_position(player1_position)) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }

    return 0;
}