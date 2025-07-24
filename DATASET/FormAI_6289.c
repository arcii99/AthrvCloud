//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: synchronous
#include <stdio.h>

char board[3][3]; // Make a 3x3 tic tac toe board
char current_player = 'X'; // Start with player X

void printBoard()
{
    printf("\n");
    for (int i=0; i<3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int checkWin()
{
    // Check rows
    for (int i=0; i<3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
    }
    
    // Check columns
    for (int i=0; i<3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    // Check for tie
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Not a tie yet
            }
        }
    }
    return 2; // Tie game
}

int minimax(int depth, char player)
{
    int score;
    int best_score;
    
    if (checkWin() == 1) {
        if (player == 'X') {
            return 10 - depth; // Player X wins
        }
        else {
            return -10 + depth; // Player O wins
        }
    }
    else if (checkWin() == 2) {
        return 0; // Tie game
    }
    
    if (player == 'X') {
        // Maximizing player X
        best_score = -1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    score = minimax(depth+1, 'O');
                    if (score > best_score) {
                        best_score = score;
                    }
                    board[i][j] = ' ';
                }
            }
        }
    }
    else {
        // Minimizing player O
        best_score = 1000;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    score = minimax(depth+1, 'X');
                    if (score < best_score) {
                        best_score = score;
                    }
                    board[i][j] = ' ';
                }
            }
        }
    }
    return best_score;
}

void makeMove()
{
    int row, col;
    int best_score = -1000;
    int score;
    
    // Find the best move for player X using minimax algorithm
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                score = minimax(0, 'O');
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    
    // Make the best move for player X
    board[row][col] = 'X';
}

int main()
{
    // Initialize the board
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    
    // Play the game
    printBoard();
    while (checkWin() == 0) {
        if (current_player == 'X') {
            makeMove();
            current_player = 'O';
        }
        else {
            printf("Please enter row and column (e.g. 1 2): ");
            int row, col;
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (board[row][col] == ' ') {
                board[row][col] = 'O';
                current_player = 'X';
            }
            else {
                printf("That spot is already taken. Please try another spot.\n");
            }
        }
        printBoard();
    }
    
    // Print the result of the game
    if (checkWin() == 1) {
        printf("Player %c wins!\n", current_player == 'X' ? 'O' : 'X');
    }
    else {
        printf("It's a tie!\n");
    }
    
    return 0;
}