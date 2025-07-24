//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>

// function declarations
int minimax(char board[3][3], char player);
int is_winner(char board[3][3], char player);
void print_board(char board[3][3]);

int main() {
    char board[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    int move[2];
    char player = 'X';
    printf("Welcome to Tic Tac Toe!\n");
    while (1) {
        print_board(board);
        printf("%c's turn\n", player);
        printf("Enter row: ");
        scanf("%d", &move[0]); // input row
        printf("Enter column: ");
        scanf("%d", &move[1]); // input column
        board[move[0]][move[1]] = player;
        if (is_winner(board, player)) {
            printf("%c is the winner!\n", player);
            break;
        }
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
        if (minimax(board, player) == -1) {
            printf("Tie game!\n");
            break;
        }
    }
    return 0;
}

// recursive function to determine best move for AI
int minimax(char board[3][3], char player) {
    int i, j, score, max_score = -2, min_score = 2;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (is_winner(board, player)) {
                    score = 1;
                } else if (minimax(board, (player == 'X') ? 'O' : 'X') == 1) {
                    score = -1;
                } else {
                    score = 0;
                }
                board[i][j] = ' '; // undo move
                if (score > max_score) {
                    max_score = score;
                }
                if (score < min_score) {
                    min_score = score;
                }
            }
        }
    }
    if (max_score == -2) { // no moves available
        return -1;
    }
    if (player == 'X') {
        return max_score;
    } else {
        return min_score;
    }
}

// function to check if a player has won
int is_winner(char board[3][3], char player) {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }
    return 0;
}

// function to print current state of the game board
void print_board(char board[3][3]) {
    int i, j;
    printf("   0 1 2\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i);
        for (j = 0; j < 3; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}