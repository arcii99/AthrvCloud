//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3

// Function to check if the game is over or not
bool is_game_over(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;

    // Check if any row has same values
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // Check if any column has same values
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }

    // Check if any of the diagonal has same values
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }

    if (board[2][0] != ' ' && board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return true;
    }

    // Check if board is full
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Function to print the current board state
void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c | %c | %c\n", board[i][0], board[i][1], board[i][2]);
        if (i != BOARD_SIZE - 1) {
            printf("---------\n");
        }
    }
    printf("\n");
}

// Function to get the move from the player
void player_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int row, col;
    printf("Enter your move (row, col): ");
    scanf("%d %d", &row, &col);

    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        printf("Invalid move. Try again.\n");
        player_move(board);
        return;
    }

    if (board[row][col] != ' ') {
        printf("Cell already occupied. Try again.\n");
        player_move(board);
        return;
    }

    board[row][col] = 'X';
}

// Function to get the move from the computer
void computer_move(char board[BOARD_SIZE][BOARD_SIZE])
{
    int i, j;
    // Check if computer can win
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (is_game_over(board)) {
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Check if player can win
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (is_game_over(board)) {
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // Choose any random cell to pick
    do {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
    } while (board[i][j] != ' ');

    board[i][j] = 'O';
}

// Main function
int main()
{
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    while (!is_game_over(board)) {
        print_board(board);
        player_move(board);
        if (!is_game_over(board)) {
            computer_move(board);
        }
    }

    print_board(board);

    printf("Game over.\n");

    return 0;
}