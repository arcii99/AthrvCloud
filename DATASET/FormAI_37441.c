//FormAI DATASET v1.0 Category: Table Game ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int player1, player2, status = 0, turn;
    printf("Welcome to the Table Game!\n");

    while(status != 1) {
        player1 = rand() % 6 + 1;
        player2 = rand() % 6 + 1;
        printf("\nPlayer 1 rolls the dice: %d\n", player1);
        printf("Player 2 rolls the dice: %d\n", player2);

        if(player1 == player2) {
            printf("It's a tie!\n");
            continue;
        }

        turn = rand() % 2;
        if(turn == 0) {
            printf("Player 1 goes first!\n");
            while(player1 > 0 && player2 > 0) {
                printf("Player 1, roll the dice! (press Enter)\n");
                getchar();
                player1 += rand() % 6 + 1;
                printf("Player 1's current score: %d\n", player1);
                if(player1 == player2) {
                    printf("Player 1 landed on Player 2's space! Player 1 wins!\n");
                    status = 1;
                    break;
                }
                if(player1 > 100) {
                    printf("Player 1 has reached 100! Player 1 wins!\n");
                    status = 1;
                    break;
                }
                printf("Player 2, roll the dice! (press Enter)\n");
                getchar();
                player2 += rand() % 6 + 1;
                printf("Player 2's current score: %d\n", player2);
                if(player2 > 100) {
                    printf("Player 2 has reached 100! Player 2 wins!\n");
                    status = 1;
                    break;
                }
            }
        }
        else {
            printf("Player 2 goes first!\n");
            while(player1 > 0 && player2 > 0) {
                printf("Player 2, roll the dice! (press Enter)\n");
                getchar();
                player2 += rand() % 6 + 1;
                printf("Player 2's current score: %d\n", player2);
                if(player1 == player2) {
                    printf("Player 2 landed on Player 1's space! Player 2 wins!\n");
                    status = 1;
                    break;
                }
                if(player2 > 100) {
                    printf("Player 2 has reached 100! Player 2 wins!\n");
                    status = 1;
                    break;
                }
                printf("Player 1, roll the dice! (press Enter)\n");
                getchar();
                player1 += rand() % 6 + 1;
                printf("Player 1's current score: %d\n", player1);
                if(player1 > 100) {
                    printf("Player 1 has reached 100! Player 1 wins!\n");
                    status = 1;
                    break;
                }
            }
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}