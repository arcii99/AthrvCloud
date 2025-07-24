//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Counting Game!\n");
    printf("In this game, we will take turns counting up from 1. The player who says '21' loses.\n");
    printf("Let's get started!\n\n");

    int count = 1;
    int player = 1;
    int input;

    while (count < 21) {
        printf("Player %d, please enter a number between %d and %d: ", player, count+1, count+3);
        scanf("%d", &input);

        if (input < count+1 || input > count+3) {
            printf("Invalid input. Please enter a number between %d and %d.\n", count+1, count+3);
            continue;
        }

        count = input;
        printf("Current count: %d\n\n", count);

        if (count == 20) {
            printf("Player %d wins!\n", player);
            return 0;
        }

        player = (player == 1) ? 2 : 1;
    }

    printf("Player %d loses. Player %d wins!\n", player, (player == 1) ? 2 : 1);
    return 0;
}