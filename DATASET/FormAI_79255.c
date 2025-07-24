//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    float expense;
} player;

int main() {
    int numPlayers, round;
    printf("How many players are playing?\n");
    scanf("%d", &numPlayers);
    player players[numPlayers];

    for (int i = 0; i < numPlayers; i++) {
        printf("Player %d's name: ", i+1);
        scanf("%s", players[i].name);
        players[i].expense = 0;
    }

    printf("How many rounds are you playing?\n");
    scanf("%d", &round);
    printf("\n");

    for (int i = 0; i < round; i++) {
        printf("Round %d beginning. Enter expenses below:\n", i+1);
        for (int j = 0; j < numPlayers; j++) {
            float expenseInput;
            printf("Player %s: ", players[j].name);
            scanf("%f", &expenseInput);
            players[j].expense += expenseInput;
        }
        printf("\nRound %d has ended.\nCurrent leaderboard:\n", i+1);
        for (int j = 0; j < numPlayers; j++) {
            printf("%d: %s - $%.2f\n", j+1, players[j].name, players[j].expense);
        }
        printf("\n");
    }

    printf("Final results:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%d: %s - $%.2f\n", i+1, players[i].name, players[i].expense);
    }

    return 0;
}