//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: lively
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

void print_card(int card[][SIZE]) {
    printf("| B  | I  | N  | G  | O  |\n");
    for (int i = 0; i < SIZE; i++) {
        printf("|----|----|----|----|----|\n");
        for (int j = 0; j < SIZE; j++) {
            printf("| %2d ", card[i][j]);
        }
        printf("|\n");
    }
    printf("|----|----|----|----|----|\n");
}

bool check_bingo(int card[][SIZE]) {
    bool bingo = false;
    for (int i = 0; i < SIZE; i++) {
        // Check rows
        if (card[i][0] != 0 && card[i][1] != 0 && card[i][2] != 0 && card[i][3] != 0 && card[i][4] != 0) {
            if (card[i][0] + card[i][1] + card[i][2] + card[i][3] + card[i][4] == 5*(2*SIZE-1)) {
                bingo = true;
                break;
            }
        }
        // Check columns
        if (card[0][i] != 0 && card[1][i] != 0 && card[2][i] != 0 && card[3][i] != 0 && card[4][i] != 0) {
            if (card[0][i] + card[1][i] + card[2][i] + card[3][i] + card[4][i] == 5*(2*SIZE-1)) {
                bingo = true;
                break;
            }
        }
    }
    // Check diagonals
    if (card[2][2] != 0 && card[0][0] != 0 && card[1][1] != 0 && card[3][3] != 0 && card[4][4] != 0) {
        if (card[0][0] + card[1][1] + card[2][2] + card[3][3] + card[4][4] == 5*(2*SIZE-1)) {
            bingo = true;
        }
    }
    if (card[2][2] != 0 && card[0][4] != 0 && card[1][3] != 0 && card[3][1] != 0 && card[4][0] != 0) {
        if (card[0][4] + card[1][3] + card[2][2] + card[3][1] + card[4][0] == 5*(2*SIZE-1)) {
            bingo = true;
        }
    }
    return bingo;
}

int main() {
    srand(time(NULL));
    int card[SIZE][SIZE] = {0};
    int checked[SIZE*SIZE+1] = {0};
    printf("Welcome to the Bingo Simulator!\n");
    printf("Generating Bingo Card...\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int n;
            do {
                n = rand() % (SIZE*SIZE) + 1;
            } while (checked[n]);
            checked[n] = 1;
            card[i][j] = n;
        }
    }
    print_card(card);
    printf("Starting Bingo Game!\n");
    int drawn[SIZE*SIZE] = {0};
    int count = 0;
    while (!check_bingo(card)) {
        count++;
        int n;
        do {
            n = rand() % (SIZE*SIZE) + 1;
        } while (drawn[n]);
        drawn[n] = 1;
        printf("Drawing Ball %d...\n", n);
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (card[i][j] == n) {
                    card[i][j] = 0;
                }
            }
        }
        print_card(card);
    }
    printf("BINGO! It took %d draws to win!\n", count);
    return 0;
}