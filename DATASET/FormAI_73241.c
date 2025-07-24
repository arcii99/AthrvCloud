//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

// function to display the current state of the board
void display_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ')
                printf("   ");
            else
                printf(" %c ", board[i][j]);

            if (j < BOARD_SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1)
            printf("-----------\n");
    }
    printf("\n");
}

// function to get the move from the player
void get_player_move(int *row, int *col) {
    printf("Enter row number (1-3) and column number (1-3): ");
    scanf("%d %d", row, col);
    (*row)--;
    (*col)--;
}

// function to check if the current board state is a win for the given player
int check_win(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

// function to get the best possible move for the computer
void get_computer_move(int *row, int *col) {
    int best_score = -1000;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(0, 0, -1000, 1000, 0);
                board[i][j] = ' ';
                if(score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

// function to minimize the score in minimax algorithm
int min(int a, int b) {
    if(a < b)
        return a;
    else
        return b;
}

// function to maximize the score in minimax algorithm
int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

// function to evaluate the score of the board state
int evaluate() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X')
                return -10;
            else if (board[i][0] == 'O')
                return 10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X')
                return -10;
            else if (board[0][i] == 'O')
                return 10;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X')
            return -10;
        else if (board[0][0] == 'O')
            return 10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X')
            return -10;
        else if (board[0][2] == 'O')
            return 10;
    }
    return 0;
}

// function to implement the minimax algorithm
int minimax(int row, int col, int alpha, int beta, int depth) {
    int score = evaluate();
    if(score == 10)
        return score - depth;
    else if(score == -10)
        return score + depth;
    else if(score == 0 && depth == 9)
        return score;

    if(depth % 2 == 0) {
        // maximizing player
        int best_score = -1000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(i, j, alpha, beta, depth+1);
                    board[i][j] = ' ';
                    best_score = max(best_score, score);
                    alpha = max(alpha, best_score);
                    if(beta <= alpha)
                        break;
                }
            }
        }
        return best_score;
    }
    else {
        // minimizing player
        int best_score = 1000;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(i, j, alpha, beta, depth+1);
                    board[i][j] = ' ';
                    best_score = min(best_score, score);
                    beta = min(beta, best_score);
                    if(beta <= alpha)
                        break;
                }
            }
        }
        return best_score;
    }
}

int main() {
    int row, col, player_turn;
    char play_again = 'y';
    srand(time(NULL));

    printf("\nGrateful Tic Tac Toe AI\n");
    printf("-----------------------\n\n");

    while (play_again == 'y' || play_again == 'Y') {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                board[i][j] = ' ';
            }
        }
        player_turn = rand() % 2;
        printf("Player %c goes first.\n", player_turn == 0 ? 'X' : 'O');
        display_board();
        while (1) {
            if (player_turn == 0) {
                get_player_move(&row, &col);
                if (board[row][col] == ' ') {
                    board[row][col] = 'X';
                    player_turn = 1;
                } else {
                    printf("That spot is already taken. Select another one.\n");
                    continue;
                }
            } else {
                get_computer_move(&row, &col);
                printf("Computer chooses row %d, column %d\n", row+1, col+1);
                board[row][col] = 'O';
                player_turn = 0;
            }
            display_board();
            if (check_win('X')) {
                printf("Player X wins!\n");
                break;
            } else if (check_win('O')) {
                printf("Player O wins!\n");
                break;
            } else if (player_turn == 0) {
                printf("It's your turn.\n");
            }
            if(board[0][0] != ' ' && board[0][1] != ' ' && board[0][2] != ' ' &&
                board[1][0] != ' ' && board[1][1] != ' ' && board[1][2] != ' ' &&
                board[2][0] != ' ' && board[2][1] != ' ' && board[2][2] != ' ') {
                printf("It's a tie!\n");
                break;
            }
        }
        printf("Play again? (Y/n): ");
        scanf("%s", &play_again);
    }

    return 0;
}