//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main()
{
    char board[ROWS][COLS] = {' '};  // Initialize the game board with empty spaces
    int row, col, num_of_ships = 5, num_of_guesses = 0;

    srand(time(NULL));  // Initialize random number generator

    // Place ships randomly
    for(int i = 0; i < num_of_ships; i++){
        row = rand() % ROWS;
        col = rand() % COLS;
        board[row][col] = 'S';
    }

    // Game Loop
    while(num_of_ships > 0){
        // Display the game board
        printf("\n");
        for(int i = 0; i < ROWS; i++){
            printf("  %d ", i+1);
        }
        printf("\n");
        for(int i = 0; i < ROWS; i++){
            printf("%d ", i+1);
            for(int j = 0; j < COLS; j++){
                printf("[ %c ]", board[i][j]);
            }
            printf("\n");
        }

        // Take User Input
        printf("\nEnter your guess (row column): ");
        scanf("%d %d", &row, &col);

        // Check if user hit a ship
        if(board[row-1][col-1] == 'S'){
            printf("\nYou Hit a Ship!\n");
            board[row-1][col-1] = 'H';
            num_of_ships--;
        }
        else if(board[row-1][col-1] == 'H' || board[row-1][col-1] == 'M'){
            printf("\nYou have already guessed this location, try again.\n");
        }
        else{
            printf("\nYou Missed!\n");
            board[row-1][col-1] = 'M';
        }

        num_of_guesses++;
    }

    // Game Over
    printf("\nCongratulations! You sunk all the ships with %d guesses!\n", num_of_guesses);
    return 0;
}