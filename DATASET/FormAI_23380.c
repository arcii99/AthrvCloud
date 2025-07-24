//FormAI DATASET v1.0 Category: Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct player {
    char name[50];
    int score;
} player;

int main() {
    int numPlayers;
    printf("Welcome to the game! How many players (2-4)?\n");
    scanf("%d", &numPlayers);
    if (numPlayers < 2 || numPlayers > 4) {
        printf("Invalid number of players. Exiting.\n");
        return 1;
    }
    player players[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d:\n", i+1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }
    int numRounds;
    printf("How many rounds would you like to play?\n");
    scanf("%d", &numRounds);
    for (int i = 0; i < numRounds; i++) {
        printf("\nRound %d!\n", i+1);
        for (int j = 0; j < numPlayers; j++) {
            printf("%s's turn! Enter score for this round:\n", players[j].name);
            int score;
            scanf("%d", &score);
            players[j].score += score;
            printf("%s's score is now %d.\n", players[j].name, players[j].score);
        }
    }
    printf("\nFinal scores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
    return 0;
}