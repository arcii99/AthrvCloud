//FormAI DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

void display_table(char table[ROWS][COLS]) {
    int i, j;
    printf("\n-------\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("|%c", table[i][j]);
        }
        printf("|\n-------\n");
    }
}

int check_win(char table[ROWS][COLS], char player) {
    int i, j;
    
    // Check horizontal wins
    for (i = 0; i < ROWS; i++) {
        if (table[i][0] == player && table[i][1] == player && table[i][2] == player) {
            return 1;
        }
    }
    
    // Check vertical wins
    for (j = 0; j < COLS; j++) {
        if (table[0][j] == player && table[1][j] == player && table[2][j] == player) {
            return 1;
        }
    }
    
    // Check diagonal wins
    if (table[0][0] == player && table[1][1] == player && table[2][2] == player) {
        return 1;
    }
    
    if (table[0][2] == player && table[1][1] == player && table[2][0] == player) {
        return 1;
    }
    
    return 0;
}

int main() {
    char table[ROWS][COLS] = {{'1', '2', '3'},
                              {'4', '5', '6'},
                              {'7', '8', '9'}};
    int player = 1, choice, i, j;
    char mark;
    srand(time(NULL));
    
    printf("Welcome to 2-player Tic-Tac-Toe!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n");
    
    display_table(table);
    
    while (1) {
        if (player == 1) {
            printf("Player 1's turn\n");
            mark = 'X';
            printf("Enter a position: ");
            scanf("%d", &choice);
        } else {
            printf("Player 2's turn\n");
            mark = 'O';
            choice = rand() % 9 + 1;
            printf("Computer selected position %d\n", choice);
        }
        
        // Check if selected position is already marked
        i = (choice - 1) / ROWS;
        j = (choice - 1) % COLS;
        if (table[i][j] == 'X' || table[i][j] == 'O') {
            printf("Position already marked, choose a different one\n");
            continue;
        }
        
        table[i][j] = mark;
        display_table(table);
        
        if (check_win(table, mark)) {
            printf("Player %d wins!\n", player);
            break;
        }
        
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    
    return 0;
}