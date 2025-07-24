//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {N = 5};

void print_card(int card[N][N]) {
    printf("\t B    I    N    G    O\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (card[i][j] == 0) 
                printf("\tFREE ");
            else 
                printf("\t%2d  ", card[i][j]);
        }
        printf("\n");
    }
}

int is_winner(int card[N][N]) {
    int i, j, line, col, diag1, diag2;
    
    for (i = 0, line = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (card[i][j] == 0) 
                line++;
        }
        if (line == N) return 1;
        line = 0;
    }
    
    for (j = 0, col = 0; j < N; j++) {
        for (i = 0; i < N; i++) {
            if (card[i][j] == 0) 
                col++;
        }
        if (col == N) return 1;
        col = 0;
    }
    
    for (i = 0, diag1 = 0; i < N; i++)
        if (card[i][i] == 0) diag1++;
    if (diag1 == N) return 1;
    
    for (i = 0, diag2 = 0; i < N; i++)
        if (card[i][N-i-1] == 0) diag2++;
    if (diag2 == N) return 1;
    
    return 0;
}

void play_bingo() {
    int card[N][N], used[76] = {0}, n, i, j, won = 0, count = 0;
    srand(time(NULL));
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == N/2 && j == N/2)
                card[i][j] = 0;
            else {
                do {
                    n = rand()%75+1;
                } while (used[n]);
                card[i][j] = n;
                used[n] = 1;
            }
        }
    }
    
    printf("Get ready, the game is about to start!\n");
    printf("You have a Bingo card with random numbers from 1 to 75.\n");
    printf("If the caller calls out a number that appears in your card, mark it with an X.\n");
    printf("You win if you have a row, a column or a diagonal of X's.\n");
    printf("Here is your Bingo card:\n");
    print_card(card);
    
    while (!won) {
        do {
            n = rand()%75+1;
        } while (used[n]);
        used[n] = 1;
        printf("The caller called out %d.\n", n);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (card[i][j] == n) {
                    card[i][j] = 0;
                    count++;
                }
            }
        }
        printf("You have %d number%s left to mark.\n", N*N-count, (N*N-count == 1) ? "" : "s");
        
        if (is_winner(card)) {
            won = 1;
            printf("Congratulations! You won Bingo!!!\n");
        }
    }
}

int main() {
    char play_again;
    printf("Welcome to the Bingo Simulator!\n");
    
    do {
        play_bingo();
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');
    
    printf("Thank you for playing Bingo Simulator!\n");
    return 0;
}