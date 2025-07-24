//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>

char board[3][3]; //the tic-tac-toe board

//Function to print the current state of the board
void printBoard() {
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

//Function to check if the game has been won by a player
char checkWin() {
    //Check rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0]; //return the character in the winning row
        }
    }
    //Check columns
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i]; //return the character in the winning column
        }
    }
    //Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0]; //return the character in the diagonal
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2]; //return the character in the diagonal
    }
    return ' '; //return a space if the game has not been won
}

//Function to check if the game has ended in a tie
int checkTie() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                return 0; //if there are any empty spaces, the game is not tied
            }
        }
    }
    return 1; //if all spaces are filled and no one has won, the game is tied
}

//Function for the AI to make a move
void aiMove() {
    int row = -1, col = -1;
    //Try to win
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'O';
                if(checkWin() == 'O') {
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    //Try to block
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                if(checkWin() == 'X') {
                    board[i][j] = 'O';
                    return;
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
    //Make a random move
    while(row == -1 && col == -1) {
        int r = rand() % 3;
        int c = rand() % 3;
        if(board[r][c] == ' ') {
            row = r;
            col = c;
        }
    }
    board[row][col] = 'O';
}

int main() {
    //Setup game
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    printBoard();
    //Game loop
    while(1) {
        //User move
        int row, col;
        printf("Enter row (1,2,3): ");
        scanf("%d", &row);
        printf("Enter column (1,2,3): ");
        scanf("%d", &col);
        if(board[row-1][col-1] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        } else {
            board[row-1][col-1] = 'X';
        }
        printBoard();
        if(checkWin() == 'X') {
            printf("You win!\n");
            break;
        }
        if(checkTie()) {
            printf("Tie game!\n");
            break;
        }
        //AI move
        printf("AI is thinking...\n");
        aiMove();
        printBoard();
        if(checkWin() == 'O') {
            printf("You lose!\n");
            break;
        }
        if(checkTie()) {
            printf("Tie game!\n");
            break;
        }
    }
    return 0;
}