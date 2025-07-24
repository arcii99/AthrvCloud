//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print the game board
void print_board(int n, char board[]) {
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            printf("%c", board[i*n+j]);
        }
        printf("\n");
    }
}

// function to check if the game is finished
int is_finished(int n, char board[]) {
    int i, j;
    int count_x = 0;
    int count_o = 0;

    // check for horizontal win
    for (i=0; i<n; i++) {
        count_x = 0;
        count_o = 0;
        for (j=0; j<n; j++) {
            if (board[i*n+j] == 'X') {
                count_x++;
            }
            else if (board[i*n+j] == 'O') {
                count_o++;
            }
        }
        if (count_x == n) {
            printf("\nPlayer X wins!\n");
            return 1;
        }
        if (count_o == n) {
            printf("\nPlayer O wins!\n");
            return 1;
        }
    }

    // check for vertical win
    for (i=0; i<n; i++) {
        count_x = 0;
        count_o = 0;
        for (j=0; j<n; j++) {
            if (board[j*n+i] == 'X') {
                count_x++;
            }
            else if (board[j*n+i] == 'O') {
                count_o++;
            }
        }
        if (count_x == n) {
            printf("\nPlayer X wins!\n");
            return 1;
        }
        if (count_o == n) {
            printf("\nPlayer O wins!\n");
            return 1;
        }
    }

    // check for diagonal win
    count_x = 0;
    count_o = 0;
    for (i=0; i<n; i++) {
        if (board[i*n+i] == 'X') {
            count_x++;
        }
        else if (board[i*n+i] == 'O') {
            count_o++;
        }
    }
    if (count_x == n) {
        printf("\nPlayer X wins!\n");
        return 1;
    }
    if (count_o == n) {
        printf("\nPlayer O wins!\n");
        return 1;
    }

    // check for reverse diagonal win
    count_x = 0;
    count_o = 0;
    for (i=0; i<n; i++) {
        if (board[(n-i-1)*n+i] == 'X') {
            count_x++;
        }
        else if (board[(n-i-1)*n+i] == 'O') {
            count_o++;
        }
    }
    if (count_x == n) {
        printf("\nPlayer X wins!\n");
        return 1;
    }
    if (count_o == n) {
        printf("\nPlayer O wins!\n");
        return 1;
    }

    // check for tie
    int count_empty = 0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (board[i*n+j] == ' ') {
                count_empty++;
            }
        }
    }
    if (count_empty == 0) {
        printf("\nTie game!\n");
        return 1;
    }

    return 0;
}

int main() {
    int n = 3; // size of the game board
    char board[n*n]; // the game board

    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            board[i*n+j] = ' '; // initialize game board with spaces
        }
    }

    int player = 1; // player 1 is X, player 2 is O
    int input_row = 0;
    int input_col = 0;
    srand(time(NULL)); // initialize random number generator
    int computer_input_row;
    int computer_input_col;

    printf("Welcome to the game of Tic Tac Toe!\n");
    print_board(n, board);

    // game loop
    while (1) {
        if (player == 1) {
            printf("\nPlayer X, enter row and column (e.g. '1 2'): ");
            scanf("%d %d", &input_row, &input_col);
            if (board[(input_row-1)*n+(input_col-1)] != ' ') {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            board[(input_row-1)*n+(input_col-1)] = 'X';
            player = 2;
        }
        else {
            printf("\nPlayer O, enter row and column (e.g. '1 2'): ");
            scanf("%d %d", &input_row, &input_col);
            if (board[(input_row-1)*n+(input_col-1)] != ' ') {
                printf("\nInvalid move. Please try again.\n");
                continue;
            }
            board[(input_row-1)*n+(input_col-1)] = 'O';
            player = 1;
        }

        print_board(n, board);

        if (is_finished(n, board)) {
            break;
        }

        // computer's turn
        printf("\nComputer's turn:\n");
        while (1) {
            computer_input_row = rand() % n + 1;
            computer_input_col = rand() % n + 1;
            if (board[(computer_input_row-1)*n+(computer_input_col-1)] == ' ') {
                board[(computer_input_row-1)*n+(computer_input_col-1)] = 'O';
                break;
            }
        }        

        print_board(n, board);

        if (is_finished(n, board)) {
            break;
        }
    }

    return 0;
}