//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_board(char board[3][3]) {
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            printf("| %c ", board[row][col]);
        }
        printf("|\n");
    }
}

int check_win(char board[3][3]) {
    // Check rows
    for(int row = 0; row < 3; row++) {
        if(board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if(board[row][0] == 'X') {
                return 1;
            } else if (board[row][0] == 'O') {
                return 2;
            }
        }
    }
    // Check columns
    for(int col = 0; col < 3; col++) {
        if(board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if(board[0][col] == 'X') {
                return 1;
            } else if (board[0][col] == 'O') {
                return 2;
            }
        }
    }
    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'X') {
            return 1;
        } else if (board[0][0] == 'O') {
            return 2;
        }
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'X') {
            return 1;
        } else if (board[0][2] == 'O') {
            return 2;
        }
    }
    // Check if game is a tie
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            if(board[row][col] == '.') {
                return 0;
            }
        }
    }
    return 3; // Game is a tie
}

int minimax(char board[3][3], int depth, int max_player) {
    int score;
    int result = check_win(board);
    if(result == 1) {
        return 10 - depth;
    } else if (result == 2) {
        return depth - 10;
    } else if (result == 3) {
        return 0;
    }
    if(max_player) { // maximizing player (AI)
        int maxEval = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '.') {
                    board[i][j] = 'X';
                    score = minimax(board, depth + 1, 0);
                    board[i][j] = '.';
                    if(score > maxEval) {
                        maxEval = score;
                    }
                }
            }
        }
        return maxEval;
    } else { // minimizing player (human)
        int minEval = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == '.') {
                    board[i][j] = 'O';
                    score = minimax(board, depth + 1, 1);
                    board[i][j] = '.';
                    if(score < minEval) {
                        minEval = score;
                    }
                }
            }
        }
        return minEval;
    }
}

void computer_move(char board[3][3]) {
    int maxEval = -1000;
    int move_row, move_col;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '.') {
                board[i][j] = 'X';
                int score = minimax(board, 0, 0);
                board[i][j] = '.';
                if(score > maxEval) {
                    maxEval = score;
                    move_row = i;
                    move_col = j;
                }
            }
        }
    }
    board[move_row][move_col] = 'X';
}

void player_move(char board[3][3]) {
    int move_row, move_col;
    printf("Enter row and column (1-3) separated by space: ");
    scanf("%d %d", &move_row, &move_col);
    move_row--;
    move_col--;
    while(board[move_row][move_col] != '.') {
        printf("Invalid move. Enter row and column again: ");
        scanf("%d %d", &move_row, &move_col);
        move_row--;
        move_col--;
    }
    board[move_row][move_col] = 'O';
}

int main() {
    char board[3][3];
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 3; col++) {
            board[row][col] = '.';
        }
    }
    int turn = 0; // 0 for player, 1 for computer
    int winner;
    while(1) {
        print_board(board);
        if(turn == 0) {
            player_move(board);
        } else {
            printf("Computer is thinking...\n");
            srand(time(0));
            int delay = rand() % 3 + 1;
            while(delay > 0) {
                printf("%d...\n", delay);
                delay--;
                sleep(1);
            }
            computer_move(board);
        }
        winner = check_win(board);
        if(winner != 0) {
            printf("Game over.\n");
            print_board(board);
            if(winner == 1) {
                printf("You win!\n");
            } else if (winner == 2) {
                printf("Computer wins.\n");
            } else {
                printf("Tie game.\n");
            }
            break;
        }
        turn = !turn;
    }
    return 0;
}