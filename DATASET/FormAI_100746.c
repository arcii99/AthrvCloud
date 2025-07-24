//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: cheerful
#include <stdio.h>

char board[3][3] = { //initialize an empty board
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

void printBoard() { //print the current state of the board
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkWin(char player) { //check if a player has won
    for(int i=0; i<3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1; //winning row
        }
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1; //winning column
        }
    }
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; //winning diagonal
    }
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; //winning diagonal
    }
    return 0;
}

int countEmpty() { //count empty spaces on the board
    int count = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                count++;
            }
        }
    }
    return count;
}

int minmax(int player) { //minmax algorithm for AI moves
    if(checkWin('X')) { //if the AI has won
        return 1;
    }
    if(checkWin('O')) { //if the player has won
        return -1;
    }
    if(countEmpty() == 0) { //if the board is full
        return 0;
    }
    
    int bestScore;
    if(player == 1) { //AI player
        bestScore = -100;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') { //empty space
                    board[i][j] = 'X'; //try AI move
                    int score = minmax(0); //minmax for player move
                    board[i][j] = ' '; //undo AI move
                    if(score > bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    }
    else { //human player
        bestScore = 100;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') { //empty space
                    board[i][j] = 'O'; //try player move
                    int score = minmax(1); //minmax for AI move
                    board[i][j] = ' '; //undo player move
                    if(score < bestScore) {
                        bestScore = score;
                    }
                }
            }
        }
    }
    return bestScore;
}

void aiMove() { //AI move
    int bestMoveScore = -100; //initialize to minimum score
    int bestMoveI;
    int bestMoveJ;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') { //empty space
                board[i][j] = 'X'; //try AI move
                int moveScore = minmax(0); //minmax for player move
                board[i][j] = ' '; //undo AI move
                if(moveScore > bestMoveScore) {
                    bestMoveScore = moveScore;
                    bestMoveI = i;
                    bestMoveJ = j;
                }
            }
        }
    }
    board[bestMoveI][bestMoveJ] = 'X'; //make AI move
    printf("AI: I choose (%d,%d)!\n", bestMoveI, bestMoveJ);
}

void playerMove() { //human player move
    int i, j;
    printf("Player O: Enter row number (0~2): ");
    scanf("%d", &i);
    printf("Player O: Enter column number (0~2): ");
    scanf("%d", &j);
    if(board[i][j] != ' ') { //if the space is not empty
        printf("Invalid move! Please try again.\n");
        playerMove();
    }
    else {
        board[i][j] = 'O'; //make player move
    }
}

int main() {
    printf("Welcome to Tic Tac Toe! You are player O.\n");
    printBoard();
    while(!checkWin('X') && !checkWin('O') && countEmpty() > 0) { //while game is not over
        playerMove();
        aiMove();
        printBoard();
    }
    if(checkWin('X')) { //AI wins
        printf("AI: Hahaha! I win!\n");
    }
    else if(checkWin('O')) { //player wins
        printf("Player O: Yay! I win!\n");
    }
    else { //tie game
        printf("It's a tie! Good game.\n");
    }
    return 0;
}