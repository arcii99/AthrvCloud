//FormAI DATASET v1.0 Category: Table Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLUMNS 3

/* Function to print the board */
void print_board(int board[ROWS][COLUMNS]) {
    printf("\n  Board\n");
    printf("---------\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            printf("| %d ", board[i][j]);
        } 
        printf("|\n--------\n");
    }
}

/* Function to check if the cell is empty */
int is_cell_empty(int board[ROWS][COLUMNS], int row, int column) {
    if(board[row][column] == 0) {
        return 1;
    }
    return 0;
}

/* Function to check if all the cells are filled */
int is_board_full(int board[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

/* Function to check if the player wins */
int is_player_win(int board[ROWS][COLUMNS], int player) {
    // Check the rows
    for(int i=0; i<ROWS; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Check the columns
    for(int i=0; i<COLUMNS; i++){
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Check the diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

/* Function to get the player move */
void get_player_move(int board[ROWS][COLUMNS], int player, int *row, int *column) {
    int r, c;
    printf("Player %d, enter row and column (separated by space): ", player);
    scanf("%d %d", &r, &c);
    while(!is_cell_empty(board, r, c)) {
        printf("Invalid move! Try again.\n");
        printf("Player %d, enter row and column (separated by space): ", player);
        scanf("%d %d", &r, &c);
    }
    *row = r;
    *column = c;
}

/* Function to get the computer move */
void get_computer_move(int board[ROWS][COLUMNS], int computer, int *row, int *column) {
    srand(time(NULL));
    do {
        *row = rand() % ROWS;
        *column = rand() % COLUMNS;
    } while(!is_cell_empty(board, *row, *column));
}

/* Main function to play the game */
int main() {
    int board[ROWS][COLUMNS] = {{0,0,0},{0,0,0},{0,0,0}};
    int player = 1, computer = 2;
    int row, column;

    printf("\n\t\tWelcome to Tic Tac Toe Game\n");

    print_board(board);

    while(1) {
        // Player's turn
        do {
            get_player_move(board, player, &row, &column);
        } while(!is_cell_empty(board, row, column));
        board[row][column] = player;
        print_board(board);
        if(is_player_win(board, player)) {
            printf("Congratulations! Player %d wins!\n", player);
            break;
        }
        if(is_board_full(board)) {
            printf("Game over! It's a draw.\n");
            break;
        }

        // Computer's turn
        printf("Computer's turn...\n");
        get_computer_move(board, computer, &row, &column);
        board[row][column] = computer;
        print_board(board);
        if(is_player_win(board, computer)) {
            printf("Sorry! Computer wins.\n");
            break;
        }
        if(is_board_full(board)) {
            printf("Game over! It's a draw.\n");
            break;
        }
    }
    return 0;
}