//FormAI DATASET v1.0 Category: Poker Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1[5], player2[5];
    int i, j, k;
    srand(time(0));
    printf("Welcome to the Surrealist Poker Game!\n\n");
    printf("Player 1's cards: ");
    for (i = 0; i < 5; i++) {
        player1[i] = (rand() % 13) + 1;
        printf("%d ", player1[i]);
    }
    printf("\n");
    printf("Player 2's cards: ");
    for (j = 0; j < 5; j++) {
        player2[j] = (rand() % 13) + 1;
        printf("%d ", player2[j]);
    }
    printf("\n");
    int player1_points = 0, player2_points = 0;
    for (k = 1; k <= 13; k++) {
        printf("\nCard of rank %d:\n", k);
        int rank_count1 = 0, rank_count2 = 0;
        for (i = 0; i < 5; i++) {
            if (player1[i] == k) {
                printf("Player 1 has a %d!\n", k);
                rank_count1++;
            }
            if (player2[i] == k) {
                printf("Player 2 has a %d!\n", k);
                rank_count2++;
            }
        }
        if (rank_count1 > rank_count2) {
            player1_points += (k * rank_count1);
        }
        else if (rank_count1 < rank_count2) {
            player2_points += (k * rank_count2);
        }
    }
    printf("\nPoints:\n");
    printf("Player 1: %d\n", player1_points);
    printf("Player 2: %d\n", player2_points);
    if (player1_points > player2_points) {
        printf("\nSurrealist Victory! Player 1 wins!\n");
    }
    else if (player1_points < player2_points) {
        printf("\nSurrealist Victory! Player 2 wins!\n");
    }
    else {
        printf("\nSurrealist Draw!\n");
    }

    return 0;
}