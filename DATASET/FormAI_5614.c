//FormAI DATASET v1.0 Category: Table Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ROWS 10
#define COLS 10

void print_board(int board[ROWS][COLS], int rows, int cols);
void place_ships(int board[ROWS][COLS], int rows, int cols, int num_ships);
void play_game(int board[ROWS][COLS], int rows, int cols);

int main(void) 
{
    int board[ROWS][COLS];
    int num_ships = 5;
    srand(time(NULL));
    
    // Initialize the board to all 0's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
    
    // Place the ships on the board
    place_ships(board, ROWS, COLS, num_ships);
    
    // Play the game
    play_game(board, ROWS, COLS);
    
    return 0;
}

void print_board(int board[ROWS][COLS], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void place_ships(int board[ROWS][COLS], int rows, int cols, int num_ships) 
{
    for (int i = 0; i < num_ships; i++) {
        int row = rand() % rows;
        int col = rand() % cols;
        board[row][col] = 1;
    }
}

void play_game(int board[ROWS][COLS], int rows, int cols) 
{
    int guesses[ROWS][COLS];
    int num_guesses = 0;
    
    // Initialize the guesses to all 0's
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            guesses[i][j] = 0;
        }
    }
    
    while (1) {
        printf("Make a guess (row column): ");
        int row, col;
        scanf("%d %d", &row, &col);
        
        // Check if the guess is already made
        if (guesses[row][col] == 1) {
            printf("You already made that guess! Try again.\n");
            continue;
        }
        
        // Mark the guess as made
        guesses[row][col] = 1;
        num_guesses++;
        
        // Check if the guess hit a ship
        if (board[row][col] == 1) {
            printf("Hit!\n");
        } else {
            printf("Miss!\n");
        }
        
        // Check if all ships were sunk
        int ships_left = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 1 && guesses[i][j] == 0) {
                    ships_left++;
                }
            }
        }
        if (ships_left == 0) {
            printf("Congratulations! You sunk all the ships in %d guesses.\n", num_guesses);
            break;
        }
    }
}