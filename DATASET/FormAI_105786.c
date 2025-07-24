//FormAI DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int board[10][10], rows=10, cols=10, player1=1, player2=2, row, col, turn=0, winner=0, i, j, move;
    srand(time(NULL)); // Initialize random number generator

    // Initialize game board with random numbers
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            board[i][j] = rand() % 100; 
        }
    }

    // Game loop
    while(winner == 0){
        // Print game board
        printf("Player %d:\n", turn+1);
        for(i=0; i<rows; i++){
            for(j=0; j<cols; j++){
                printf("%2d ", board[i][j]);
            }
            printf("\n");
        }

        // Get move from player
        printf("Enter the row and column number (between 0 and 9) where you want to make a move.\n");
        scanf("%d %d", &row, &col);

        // Check validity of move
        if(row < 0 || row >= rows || col < 0 || col >= cols){
            printf("Invalid move! Please enter a row and column number between 0 and 9.\n");
            continue;
        }
        if(board[row][col] == -1){
            printf("This position has already been uncovered! Please choose a different position.\n");
            continue;
        }

        // Check if move results in winning condition
        move = board[row][col];
        for(i=row-move; i<=row+move; i++){
            if(i >= 0 && i < rows && board[i][col] != -1){
                break;
            }
            if(i == row+move){
                winner = turn+1;
                break;
            }
        }
        for(j=col-move; j<=col+move; j++){
            if(j >= 0 && j < cols && board[row][j] != -1){
                break;
            }
            if(j == col+move){
                winner = turn+1;
                break;
            }
        }

        // Update game board and next turn
        if(winner == 0){
            board[row][col] = -1;
            turn = (turn + 1) % 2;
        }
    }

    // Print winner
    printf("Player %d wins!\n", winner);

    return 0;
}