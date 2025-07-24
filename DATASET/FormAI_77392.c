//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define HUMAN_PLAYER 'X'
#define AI_PLAYER 'O'

char board[BOARD_SIZE][BOARD_SIZE];
int depth;

void printBoard() {
    printf("\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
}

int checkWinner() {
    // Checking rows
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == AI_PLAYER) return 10;
            else if(board[i][0] == HUMAN_PLAYER) return -10;
        }
    }
    // Checking columns
    for(int i=0; i<BOARD_SIZE; i++) {
        if(board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == AI_PLAYER) return 10;
            else if(board[0][i] == HUMAN_PLAYER) return -10;
        }
    }
    // Checking diagonals
    if(board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == AI_PLAYER) return 10;
        else if(board[0][0] == HUMAN_PLAYER) return -10;
    }
    if(board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == AI_PLAYER) return 10;
        else if(board[0][2] == HUMAN_PLAYER) return -10;
    }
    // If no winner yet
    return 0;
}

int isMovesLeft() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == '-') return 1;
        }
    }
    return 0;
}

int minimax(int isMax, int alpha, int beta) {
    int score = checkWinner();  // If a terminal state has been reached
    if(score == 10 || score == -10) return score;
    if(isMovesLeft() == 0) return 0;  // Draw
    if(isMax) {
        int best = -1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = AI_PLAYER;
                    depth++;
                    int currScore = minimax(0, alpha, beta);
                    if(depth == 1) printf("AI placed %c at row %d, column %d.\n", AI_PLAYER, i+1, j+1);
                    board[i][j] = '-';
                    depth--;
                    if(currScore > best) best = currScore;
                    if(currScore > alpha) alpha = currScore;
                    if(alpha >= beta) break;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == '-') {
                    board[i][j] = HUMAN_PLAYER;
                    depth++;
                    int currScore = minimax(1, alpha, beta);
                    board[i][j] = '-';
                    depth--;
                    if(currScore < best) best = currScore;
                    if(currScore < beta) beta = currScore;
                    if(alpha >= beta) break;
                }
            }
        }
        return best;
    }
}

void play() {
    printf("Welcome to Brave Tic Tac Toe!\n");
    printf("You are X and the computer is O. Let's begin!\n");
    printf("The board is numbered from 1 to 9 as per the following:\n");
    printf(" 1 | 2 | 3 \n");
    printf("---+---+---\n");
    printf(" 4 | 5 | 6 \n");
    printf("---+---+---\n");
    printf(" 7 | 8 | 9 \n\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    while(1) {
        printBoard();
        int row, col, position;
        printf("Enter a cell number where you want to place your %c: ", HUMAN_PLAYER);
        scanf("%d", &position);
        row = (position-1) / 3;
        col = (position-1) % 3;
        if(board[row][col] == '-') {
            board[row][col] = HUMAN_PLAYER;
        } else {
            printf("Invalid cell. Try again.\n");
            continue;
        }
        int score = checkWinner();
        if(score == -10) {
            printBoard();
            printf("You win!\n");
            break;
        }
        if(score == 0 && isMovesLeft() == 0) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
        depth = 0;
        printf("AI is thinking...\n");
        minimax(1, -1000, 1000);
        score = checkWinner();
        if(score == 10) {
            printBoard();
            printf("You lose!\n");
            break;
        }
        if(score == 0 && isMovesLeft() == 0) {
            printBoard();
            printf("It's a draw!\n");
            break;
        }
    }
}

int main() {
    play();
    return 0;
}