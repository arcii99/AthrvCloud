//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Function to display Tic Tac Toe Board
void display_board(char board[][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
    }
}

// Function to check if the game has ended with either a draw or a win
int check_game_over(char board[][3]) {
    // Check for diagonal win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return board[1][1];
    }
    for (int i = 0; i < 3; i++) {
        // Check for horizontal win
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        // Check for vertical win
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check for draw
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == 9) {
        return 'D';
    }
    return -1;
}

// Function to get the AI's move
void ai_move(char board[][3], int* row, int* col) {
    // Check for winning move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                if (check_game_over(board) == 'O') {
                    *row = i;
                    *col = j;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Check for blocking move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (check_game_over(board) == 'X') {
                    *row = i;
                    *col = j;
                    board[i][j] = 'O';
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }
    // Move to a random spot
    do {
        *row = rand() % 3;
        *col = rand() % 3;
    } while (board[*row][*col] != ' ');
}

// Function to get the player's move
void player_move(char board[][3], int* row, int* col) {
    do {
        printf("Enter Row (1-3): ");
        scanf("%d", row);
        printf("Enter Column (1-3): ");
        scanf("%d", col);
        (*row)--;
        (*col)--;
    } while (*row < 0 || *row > 2 || *col < 0 || *col > 2 || board[*row][*col] != ' ');
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int row, col, game_over = -1;

    while (game_over == -1) {
        display_board(board);

        player_move(board, &row, &col);
        board[row][col] = 'X';
        game_over = check_game_over(board);
        if (game_over != -1) {
            break;
        }

        ai_move(board, &row, &col);
        board[row][col] = 'O';
        game_over = check_game_over(board);
    }

    display_board(board);

    if (game_over == 'X') {
        printf("You Win!\n");
    } else if (game_over == 'O') {
        printf("You Lose!\n");
    } else {
        printf("Draw!\n");
    }

    return 0;
}