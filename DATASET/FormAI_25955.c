//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: imaginative
#include <stdio.h>

// Function to draw the Tic Tac Toe board
void draw_board(char board[3][3]) {
    printf("\t  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("\t----|---|----\n");
    printf("\t  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("\t----|---|----\n");
    printf("\t  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to check if there is a winner or not
int check_winner(char board[3][3], char player) {
    // Checking for horizontal win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }
    // Checking for vertical win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    // Checking for diagonal win
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// Function to implement the AI logic
void ai_move(char board[3][3], char player) {
    // First, check for a winning move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Check if the position is empty
            if (board[i][j] == '-') {
                // Try to make the winning move
                board[i][j] = player;
                if (check_winner(board, player)) {
                    printf("AI Plays Move (%d, %d)\n", i+1, j+1);
                    return;
                }
                // If not, undo the move
                board[i][j] = '-';
            }
        }
    }
    // If no winning move, try to block player's winning move
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Check if the position is empty
            if (board[i][j] == '-') {
                // Try to block the player's move
                board[i][j] = (player == 'X') ? 'O' : 'X'; // change player
                if (check_winner(board,  (player == 'X') ? 'O' : 'X')) {
                    board[i][j] = player; // make the move
                    printf("AI Plays Move (%d, %d)\n", i+1, j+1);
                    return;
                }
                // If not, undo the move
                board[i][j] = '-';
            }
        }
    }
    // If no winning move, no blocking move, play randomly
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = player;
                printf("AI Plays Move (%d, %d)\n", i+1, j+1);
                return;
            }
        }
    }
}

int main() {
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    draw_board(board);
    int turn = 0;
    printf("AI is O, You are X\n");
    while (1) {
        if (turn % 2 == 0) {
            int row, col;
            while (1) {
                printf("Enter Row (1, 2, or 3): ");
                scanf("%d", &row);
                if (row < 1 || row > 3) {
                    printf("Invalid Row\n");
                    continue;
                }
                printf("Enter Column (1, 2, or 3): ");
                scanf("%d", &col);
                if (col < 1 || col > 3) {
                    printf("Invalid Column\n");
                    continue;
                }
                if (board[row-1][col-1] != '-') {
                    printf("Position Already Filled\n");
                    continue;
                }
                board[row-1][col-1] = 'X';
                break;
            }
        } else {
            ai_move(board, 'O');
        }
        draw_board(board);
        if (check_winner(board, 'X')) {
            printf("You Won!\n");
            break;
        }
        if (check_winner(board, 'O')) {
            printf("AI Won!\n");
            break;
        }
        if (turn == 8) {
            printf("It's a Tie!\n");
            break;
        }
        turn++;
    }
    return 0;
}