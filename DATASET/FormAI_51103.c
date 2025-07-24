//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare the board and size
char board[3][3];
const int size = 3;

// print the board
void print_board() {
    int i, j;
    printf("\n  0 1 2\n");
    for (i = 0; i < size; i++) {
        printf("%d ", i);
        for (j = 0; j < size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// check if there is a winner
char check_winner() {
    int i, j;
    // check rows
    for (i = 0; i < size; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // check columns
    for (j = 0; j < size; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // check for tie
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j] == '-') {
                return '-';
            }
        }
    }
    return 'T';
}

// get the position to make a move
void get_move(int* row, int* col) {
    printf("Enter row and column for move (separated by space): ");
    scanf("%d %d", row, col);
}

// make a random move for the AI
void ai_move(int* row, int* col) {
    srand(time(NULL));
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != '-');
    printf("AI makes move: %d %d\n", *row, *col);
}

int main() {
    int row, col;
    char player = 'X';
    int moves = 0;
    // initialize the board
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j] = '-';
        }
    }
    // play the game
    while (1) {
        print_board();
        if (player == 'X') {
            get_move(&row, &col);
        } else {
            ai_move(&row, &col);
        }
        if (board[row][col] != '-') {
            printf("Invalid move, try again.\n");
            continue;
        }
        board[row][col] = player;
        moves++;
        char winner = check_winner();
        if (winner != '-') {
            if (winner == 'T') {
                printf("It's a tie!\n");
            } else {
                printf("%c wins!\n", winner);
            }
            break;
        } else if (moves == 9) {
            printf("It's a tie!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}