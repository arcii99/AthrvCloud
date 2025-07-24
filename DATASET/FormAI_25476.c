//FormAI DATASET v1.0 Category: Table Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>     // for rand() function
#include <time.h>       // for time() function

#define ROWS 3
#define COLS 3

// Function to print the Tic Tac Toe game board
void print_board(char board[ROWS][COLS]) {
    printf("\nTic Tac Toe Board:\n");
    printf("     1   2   3  \n");
    printf("   ------------\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d |", i+1);
        for(int j = 0; j < COLS; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("   ------------\n");
    }
}

// Function to check if any player wins
char check_win(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        // Check horizontally
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        // Check vertically
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    // Check diagonally
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if(board[2][0] == board[1][1] && board[1][1] == board[0][2])
        return board[2][0];
    
    // Check if it is a draw
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == ' ')
                return ' ';
        }
    }
    return 'D';
}

int main() {
    char board[ROWS][COLS];
    char player[2] = {'X', 'O'};
    int row, col;
    char winner = ' ';
    
    // Initialize the board with empty spaces
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }
    
    printf("\nWelcome to Tic Tac Toe Game!\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("The first player to get 3 in a row wins!\n");
    
    // Randomize who goes first
    srand(time(NULL));
    int first_player = rand() % 2;
    printf("\n");
    printf("Player %d goes first.\n", first_player+1);
    
    // Game loop
    while(winner == ' ') {
        print_board(board);
        printf("\nPlayer %d's turn.\n", first_player+1);
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &col);
        
        // Check if the move is valid
        if(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("Invalid move!\n");
            continue;
        }
        
        // Update the board
        board[row-1][col-1] = player[first_player];
        
        // Check if any player wins or if it is a draw
        winner = check_win(board);
        if(winner == 'X' || winner == 'O' || winner == 'D')
            break;
        
        // Switch players
        first_player = (first_player+1)%2;
    }
    
    // Game over
    print_board(board);
    if(winner == 'X' || winner == 'O')
        printf("\nPlayer %d wins!\n", (winner == 'X') ? 1 : 2);
    else
        printf("\nIt's a draw!\n");
    
    return 0;
}