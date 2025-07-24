//FormAI DATASET v1.0 Category: Table Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10           /* size of the game board */
#define NUM_WIN 5         /* number of consecutive squares needed to win */

int board[SIZE][SIZE];     /* game board */
int player;                /* current player: 0 (player 1) or 1 (player 2) */

/* initialize game board */
void init_board()
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = -1;
        }
    }
}

/* print game board */
void print_board()
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            switch (board[i][j]) {
                case -1:
                    printf("_ ");
                    break;
                case 0:
                    printf("X ");
                    break;
                case 1:
                    printf("O ");
                    break;
            }
        }
        printf("\n");
    }
}

/* check if a player has won */
int check_win(int row, int col)
{
    int i, j;
    int count = 0;
    
    /* check horizontal */
    for (j = col-NUM_WIN+1; j <= col; j++) {
        if (j < 0) continue;
        if (j+NUM_WIN-1 >= SIZE) break;
        count = 0;
        for (i = j; i < j+NUM_WIN; i++) {
            if (board[row][i] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == NUM_WIN) {
                return 1;
            }
        }
    }
    
    /* check vertical */
    for (i = row-NUM_WIN+1; i <= row; i++) {
        if (i < 0) continue;
        if (i+NUM_WIN-1 >= SIZE) break;
        count = 0;
        for (j = i; j < i+NUM_WIN; j++) {
            if (board[j][col] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == NUM_WIN) {
                return 1;
            }
        }
    }
    
    /* check diagonal (top-left to bottom-right) */
    for (i = row-NUM_WIN+1, j = col-NUM_WIN+1; i <= row && j <= col; i++, j++) {
        if (i < 0 || j < 0) continue;
        if (i+NUM_WIN-1 >= SIZE || j+NUM_WIN-1 >= SIZE) break;
        count = 0;
        for (int k = 0; k < NUM_WIN; k++) {
            if (board[i+k][j+k] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == NUM_WIN) {
                return 1;
            }
        }
    }
    
    /* check diagonal (top-right to bottom-left) */
    for (i = row-NUM_WIN+1, j = col+NUM_WIN-1; i <= row && j >= col; i++, j--) {
        if (i < 0 || j >= SIZE) continue;
        if (i+NUM_WIN-1 >= SIZE || j-NUM_WIN+1 < 0) break;
        count = 0;
        for (int k = 0; k < NUM_WIN; k++) {
            if (board[i+k][j-k] == player) {
                count++;
            } else {
                count = 0;
            }
            if (count == NUM_WIN) {
                return 1;
            }
        }
    }
    
    return 0;
}

/* get a valid move from the current player */
void get_move(int *row, int *col)
{
    printf("Player %d's turn.\n", player+1);
    printf("Enter row (0-%d): ", SIZE-1);
    scanf("%d", row);
    printf("Enter column (0-%d): ", SIZE-1);
    scanf("%d", col);
    while (board[*row][*col] != -1) {
        printf("Invalid move. Please try again.\n");
        printf("Enter row (0-%d): ", SIZE-1);
        scanf("%d", row);
        printf("Enter column (0-%d): ", SIZE-1);
        scanf("%d", col);
    }
}

int main()
{
    int row, col;
    int done = 0;          /* flag for whether game is finished */
    srand(time(NULL));     /* initialize random number generator */
    init_board();          /* initialize game board */
    player = rand() % 2;   /* choose which player goes first */
    printf("Welcome to C Table Game!\n");
    printf("Player 1 (X) goes first.\n");
    print_board();         /* print initial game board */
    while (!done) {
        get_move(&row, &col); /* get move from current player */
        board[row][col] = player; /* update game board */
        print_board(); /* print updated game board */
        if (check_win(row, col)) { /* check for winner */
            printf("Player %d (", player+1);
            if (player == 0) printf("X");
            else printf("O");
            printf(") wins!\n");
            done = 1;
        } else if (board[0][0] != -1 && board[SIZE-1][SIZE-1] != -1) { /* check for tie */
            printf("It's a tie!\n");
            done = 1;
        }
        player = !player; /* switch players */
    }
    return 0;
}