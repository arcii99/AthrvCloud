//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_card(char card[ROWS][COLS]);
int check_bingo(char card[ROWS][COLS], int call[ROWS*COLS], int round);

int main() {
    // Set up card
    char card[ROWS][COLS] = {' ', ' ', ' ', ' ', ' ',
                             ' ', ' ', ' ', ' ', ' ',
                             ' ', ' ', 'X', ' ', ' ',
                             ' ', 'X', ' ', 'X', ' ',
                             'X', ' ', ' ', ' ', 'X'};
    print_card(card);

    // Generate calls
    int calls[ROWS*COLS];
    srand(time(NULL));
    for(int i=0; i<ROWS*COLS; i++) {
        calls[i] = rand() % 75 + 1;
    }

    // Play game
    int round = 0;
    while(1) {
        // Call next number
        int number = calls[round];
        printf("Round %d: %d\n", round+1, number);

        // Check for bingo
        if(check_bingo(card, calls, round)) {
            printf("\nBINGO!!!\n");
            print_card(card);
            break;
        }

        // Wait for user input
        printf("\nPress enter to continue...");
        while(getchar() != '\n');
        round++;
    }

    return 0;
}

void print_card(char card[ROWS][COLS]) {
    printf("\n  B |  I |  N |  G |  O\n");
    for(int row=0; row<ROWS; row++) {
        printf("-----------------------\n");
        for(int col=0; col<COLS; col++) {
            printf(" %2c |", card[row][col]);
        }
        printf(" %c\n", 'B'+row);
    }
    printf("-----------------------\n");
}

int check_bingo(char card[ROWS][COLS], int call[ROWS*COLS], int round) {
    // Check rows
    for(int row=0; row<ROWS; row++) {
        int count = 0;
        for(int col=0; col<COLS; col++) {
            for(int i=0; i<=round; i++) {
                if(call[i] == ((row*15)+col)+1 && card[row][col] == 'X') {
                    count++;
                    break;
                }
            }
        }
        if(count == COLS) {
            return 1;
        }
    }

    // Check columns
    for(int col=0; col<COLS; col++) {
        int count = 0;
        for(int row=0; row<ROWS; row++) {
            for(int i=0; i<=round; i++) {
                if(call[i] == ((row*15)+col)+1 && card[row][col] == 'X') {
                    count++;
                    break;
                }
            }
        }
        if(count == ROWS) {
            return 1;
        }
    }

    // Check diagonals
    int count = 0;
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(i == j && card[i][j] == 'X') {
                for(int k=0; k<=round; k++) {
                    if(call[k] == ((i*15)+j)+1) {
                        count++;
                        break;
                    }
                }
            }
            if(i+j == ROWS-1 && card[i][j] == 'X') {
                for(int k=0; k<=round; k++) {
                    if(call[k] == ((i*15)+j)+1) {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    if(count == ROWS+COLS-1) {
        return 1;
    }

    // No bingo
    return 0;
}