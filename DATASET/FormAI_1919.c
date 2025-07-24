//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void movePlayer(int *playerPosition) {
    int diceRoll = rand() % 6 + 1;
    printf("You rolled a %d!\n", diceRoll);
    *playerPosition += diceRoll;
    switch (*playerPosition) {
        case 4:
            printf("You landed on a ladder! Climbing up to spot 14...\n");
            *playerPosition = 14;
            break;
        case 9:
            printf("You landed on a ladder! Climbing up to spot 31...\n");
            *playerPosition = 31;
            break;
        case 17:
            printf("You landed on a ladder! Climbing up to spot 7...\n");
            *playerPosition = 7;
            break;
        case 20:
            printf("You landed on a ladder! Climbing up to spot 38...\n");
            *playerPosition = 38;
            break;
        case 28:
            printf("You landed on a ladder! Climbing up to spot 84...\n");
            *playerPosition = 84;
            break;
        case 40:
            printf("You landed on a ladder! Climbing up to spot 59...\n");
            *playerPosition = 59;
            break;
        case 51:
            printf("You landed on a ladder! Climbing up to spot 67...\n");
            *playerPosition = 67;
            break;
        case 54:
            printf("You landed on a snake! Sliding down to spot 34...\n");
            *playerPosition = 34;
            break;
        case 62:
            printf("You landed on a ladder! Climbing up to spot 19...\n");
            *playerPosition = 19;
            break;
        case 64:
            printf("You landed on a snake! Sliding down to spot 60...\n");
            *playerPosition = 60;
            break;
        case 71:
            printf("You landed on a ladder! Climbing up to spot 91...\n");
            *playerPosition = 91;
            break;
        case 87:
            printf("You landed on a snake! Sliding down to spot 24...\n");
            *playerPosition = 24;
            break;
        case 93:
            printf("You landed on a snake! Sliding down to spot 73...\n");
            *playerPosition = 73;
            break;
        case 95:
            printf("You landed on a snake! Sliding down to spot 75...\n");
            *playerPosition = 75;
            break;
        case 99:
            printf("You landed on a snake! Sliding down to spot 78...\n");
            *playerPosition = 78;
            break;
        default:
            printf("Nothing special happened. You're at spot %d.\n", *playerPosition);
            break;
    }
}

int main() {
    srand(time(NULL));
    int player1Position = 0, player2Position = 0;
    printf("Welcome to Snakes and Ladders! Player 1 goes first.\n");

    while (1) {
        // Player 1's turn
        printf("Player 1, press enter to roll the dice.\n");
        getchar();
        movePlayer(&player1Position);
        if (player1Position >= 100) {
            printf("Player 1 wins!\n");
            break;
        }

        // Player 2's turn
        printf("Player 2, press enter to roll the dice.\n");
        getchar();
        movePlayer(&player2Position);
        if (player2Position >= 100) {
            printf("Player 2 wins!\n");
            break;
        }
    }
    return 0;
}