//FormAI DATASET v1.0 Category: Memory Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define MAX_MOVES 20

// Function to print the game board
void print_board(int board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int is_game_over(int board[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(board[i][j] == 0){
                return 0; // Not game over
            }
        }
    }
    return 1; // Game over
}

// Function to randomly place the numbers on the board
void place_numbers(int board[SIZE][SIZE]){
    int count = 0;
    int max_count = SIZE * SIZE / 2; // Half of the board size

    while(count < max_count){
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        // Check if the position is empty
        if(board[i][j] == 0){
            // Generate a random number (either 1 or 2)
            int num = (rand() % 2) + 1;

            // Place the number in the position
            board[i][j] = num;
            count++;
        }
    }
}

// Function to get the user's move
void get_move(int board[SIZE][SIZE], int *row, int *col){
    printf("Enter your move (row col): ");
    scanf("%d %d", row, col);

    // Keep asking for the move until a valid move is given
    while(board[*row][*col] == 0 || *row < 0 || *row >= SIZE || *col < 0 || *col >= SIZE){
        printf("Invalid move. Try again (row col): ");
        scanf("%d %d", row, col);
    }
}

// Function to perform the user's move
void do_move(int board[SIZE][SIZE], int row, int col){
    // Move the number to the left
    if(col > 0 && board[row][col-1] == 0){
        board[row][col-1] = board[row][col];
        board[row][col] = 0;
    }
    // Move the number to the right
    else if(col < SIZE-1 && board[row][col+1] == 0){
        board[row][col+1] = board[row][col];
        board[row][col] = 0;
    }
    // Move the number up
    else if(row > 0 && board[row-1][col] == 0){
        board[row-1][col] = board[row][col];
        board[row][col] = 0;
    }
    // Move the number down
    else if(row < SIZE-1 && board[row+1][col] == 0){
        board[row+1][col] = board[row][col];
        board[row][col] = 0;
    }
}

// Main function
int main(){
    int board[SIZE][SIZE] = {0}; // Initialize the board to all zeros
    int moves = 0; // Initialize the number of moves to 0

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Place the numbers on the board
    place_numbers(board);

    // Print the initial board
    printf("Initial Board:\n");
    print_board(board);

    // Play the game
    while(!is_game_over(board) && moves < MAX_MOVES){
        int row, col;

        // Get the user's move
        get_move(board, &row, &col);

        // Do the user's move
        do_move(board, row, col);

        // Increment the number of moves
        moves++;

        // Print the updated board
        printf("Updated Board:\n");
        print_board(board);
    }

    // Check if the game is over or the maximum number of moves has been reached
    if(is_game_over(board)){
        printf("Congratulations! You won the game!\n");
    }
    else{
        printf("Game over. You lost!\n");
    }

    return 0;
}