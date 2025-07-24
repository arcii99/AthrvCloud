//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Tic Tac Toe AI Example

// Function prototype
void display_board(char board[3][3]);
int get_input(char board[3][3]);
int check_win(char board[3][3], char symbol);
int minimax(char board[3][3], int depth, int isMaximizing, char computer, char player);
int best_move(char board[3][3], char computer, char player);

// Main function
int main() {
    // Initialize the board
    char board[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };
    
    // Display the board
    display_board(board);
    
    // Run the game loop
    char computer = 'O';
    char player = 'X';
    int moves = 0;
    int gameover = 0;
    while(!gameover && moves < 9) {
        // Player turn
        int row, col;
        printf("\nYour Turn (Enter coordinates in the format: row column): ");
        while(get_input(board) == 0);
        row = get_input(board) - 1;
        col = get_input(board+1) - 1;
        board[row][col] = player;
        moves++;
        display_board(board);
        // Check for player win
        if(check_win(board, player)) {
            printf("\nCongratulations! You have won the game.\n");
            gameover = 1;
            break;
        }
        // If no more moves left, break the loop
        if(moves >= 9)
            break;
        // Computer turn
        printf("\nComputer's Turn:\n");
        int bestmove = best_move(board, computer, player);
        row = bestmove / 3;
        col = bestmove % 3;
        board[row][col] = computer;
        moves++;
        display_board(board);
        // Check for computer win
        if(check_win(board, computer)) {
            printf("\nOh no! The computer has won the game.\n");
            gameover = 1;
            break;
        }
    }
    // If the game is tied
    if(!gameover)
        printf("\nOops! The game ended in a tie.\n");
    return 0;
}

// Function to display the tic tac toe board
void display_board(char board[3][3]) {
    printf("\n");
    for(int i = 0; i<3; ++i) {
        for(int j = 0; j<3; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the user input
int get_input(char board[3][3]) {
    int input;
    scanf("%d", &input);
    if(input < 1 || input > 3 || board[input-1][input-1] != '-') {
        printf("\nInvalid input or box already occupied. Please try again.\n");
        return 0;
    }
    return input;
}

// Function to check for win
int check_win(char board[3][3], char symbol) {
    // Check rows
    for(int i = 0; i<3; ++i) {
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return 1;
    }
    // Check columns
    for(int j = 0; j<3; ++j) {
        if(board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
            return 1;
    }
    // Check diagonal 1
    if(board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
        return 1;
    // Check diagonal 2
    if(board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
        return 1;
    return 0;
}

// Function to calculate the minimax score
int minimax(char board[3][3], int depth, int isMaximizing, char computer, char player) {
    int score = 0;
    // Check for winner
    if(check_win(board, computer)) {
        score = 10;
        return score;
    }
    if(check_win(board, player)) {
        score = -10;
        return score;
    }
    // Check for tie
    if(depth == 0) {
        score = 0;
        return score;
    }
    // Maximizing player
    if(isMaximizing == 1) {
        int bestScore = -1000;
        for(int i = 0; i<3; ++i) {
            for(int j = 0; j<3; ++j) {
                // Check if cell is empty
                if(board[i][j] == '-') {
                    board[i][j] = computer;
                    int tempScore = minimax(board, depth-1, !isMaximizing, computer, player);
                    board[i][j] = '-';
                    if(tempScore > bestScore)
                        bestScore = tempScore;
                }
            }
        }
        return bestScore;
    }
    // Minimizing player
    else {
        int bestScore = 1000;
        for(int i = 0; i<3; ++i) {
            for(int j = 0; j<3; ++j) {
                // Check if cell is empty
                if(board[i][j] == '-') {
                    board[i][j] = player;
                    int tempScore = minimax(board, depth-1, !isMaximizing, computer, player);
                    board[i][j] = '-';
                    if(tempScore < bestScore)
                        bestScore = tempScore;
                }
            }
        }
        return bestScore;
    }
}

// Function to find the best move for the computer
int best_move(char board[3][3], char computer, char player) {
    int bestScore = -1000;
    int bestMove = -1;
    for(int i = 0; i<3; ++i) {
        for(int j = 0; j<3; ++j) {
            // Check if cell is empty
            if(board[i][j] == '-') {
                board[i][j] = computer;
                int tempScore = minimax(board, 3, 0, computer, player);
                board[i][j] = '-';
                if(tempScore > bestScore) {
                    bestScore = tempScore;
                    bestMove = i*3+j;
                }
            }
        }
    }
    return bestMove;
}