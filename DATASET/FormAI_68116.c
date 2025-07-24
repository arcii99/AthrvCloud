//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The Tic Tac Toe game board
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to check if the game is over
int gameOver(){
    int i, j;

    // Check rows
    for(i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
    }

    // Check columns
    for(j=0; j<3; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
            return 1;
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    // Check if the board is full
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == ' ')
                return 0;
        }
    }

    // If it gets here, it means that it's a tie
    return 2;
}

// Function to print the board
void printBoard(){
    printf("   1   2   3\n");
    printf("1  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  -----------\n");
    printf("2  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  -----------\n");
    printf("3  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

// Function to let the player make a move
void playerMove() {
    int row, col;

    do{
        printf("Enter a row and a column (1-3): ");
        scanf("%d %d", &row, &col);
    }while(row<1 || row>3 || col<1 || col>3 || board[row-1][col-1] != ' ');

    board[row-1][col-1] = 'X';
}

// Function that returns the score of the current board
int score() {
    int i, j;

    // Check rows
    for(i=0; i<3; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if(board[i][0] == 'X')
                return -10;
            else if(board[i][0] == 'O')
                return 10;
        }
    }

    // Check columns
    for(j=0; j<3; j++){
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]){
            if(board[0][j] == 'X')
                return -10;
            else if(board[0][j] == 'O')
                return 10;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if(board[0][0] == 'X')
            return -10;
        else if(board[0][0] == 'O')
            return 10;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if(board[0][2] == 'X')
            return -10;
        else if(board[0][2] == 'O')
            return 10;
    }

    // If it gets here, it means that it's a tie
    return 0;
}

// Function to let the AI make a move
void aiMove(){
    int i, j;
    int bestScore = -1000;
    int moveScore;
    int bestRow = -1;
    int bestCol = -1;

    // The AI evaluates each possible move and chooses the best one
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(board[i][j] == ' '){
                board[i][j] = 'O';
                moveScore = minimax(0, 0);
                board[i][j] = ' ';

                if(moveScore > bestScore){
                    bestScore = moveScore;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    board[bestRow][bestCol] = 'O';
}

// Function that implements the minimax algorithm with alpha-beta pruning
int minimax(int depth, int isMaximizing) {
    int i, j;
    int result = score();

    // Check if the game is over
    if(result != 0)
        return result;

    // If not, recursively call the function to evaluate each possible move
    int bestScore;
    if(isMaximizing){
        bestScore = -1000;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'O';
                    bestScore = max(bestScore, minimax(depth+1, !isMaximizing));
                    board[i][j] = ' ';

                    // Alpha-beta pruning
                    if(bestScore >= depth+20)
                        return bestScore;
                }
            }
        }
    }
    else{
        bestScore = 1000;
        for(i=0; i<3; i++){
            for(j=0; j<3; j++){
                if(board[i][j] == ' '){
                    board[i][j] = 'X';
                    bestScore = min(bestScore, minimax(depth+1, !isMaximizing));
                    board[i][j] = ' ';

                    // Alpha-beta pruning
                    if(bestScore <= depth-20)
                        return bestScore;
                }
            }
        }
    }

    return bestScore;
}

// Function to find the maximum of two numbers
int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

// Function to find the minimum of two numbers
int min(int a, int b){
    if(a < b)
        return a;
    else
        return b;
}

// The main function
int main() {
    int gameResult;
    int turn;
    srand(time(NULL)); // Initialize the random number generator

    // Choose who goes first
    turn = rand() % 2;

    printf("Welcome to Tic Tac Toe! You are X and the AI is O.\n");
    printf("You can make a move by entering a row and a column (1-3).\n");

    while(!gameOver()){
        printBoard();

        if(turn == 0){
            playerMove();
        }
        else{
            aiMove();
        }

        turn = !turn;
    }

    printBoard();

    gameResult = gameOver();

    if(gameResult == 1)
        printf("Game over. The AI wins.\n");
    else if(gameResult == 2)
        printf("Game over. It's a tie.\n");
    else
        printf("Game over. You win!\n");

    return 0;
}