//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5

int main(){
    int i, j, count, num, isBingo;
    int board[BOARD_SIZE][BOARD_SIZE];
    int rowCheck[BOARD_SIZE], colCheck[BOARD_SIZE], leftDiagCheck, rightDiagCheck;
    srand(time(NULL)); // Seed the random number generator

    // Initialize the board to zeros
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            board[i][j] = 0;
        }
    }

    // Print the initial board
    printf("--------------------------------\n");
    printf("          Welcome to\n          Bingo Simulator\n");
    printf("--------------------------------\n\n");
    printf("Here is your initial board:\n");
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Fill in random numbers on the board
    count = 0;
    while(count < BOARD_SIZE*BOARD_SIZE){
        num = rand() % 75 + 1; // Generate a random number between 1 and 75
        // Check that the number hasn't already been placed on the board
        isBingo = 0;
        for(i = 0; i < BOARD_SIZE; i++){
            for(j = 0; j < BOARD_SIZE; j++){
                if(board[i][j] == num){
                    isBingo = 1; // Number is already on board
                    break;
                }
            }
            if(isBingo) break;
        }
        if(!isBingo){
            board[count/BOARD_SIZE][count%BOARD_SIZE] = num;
            count++; // Increment count if the number is placed on the board
        }
    }

    // Print the final board
    printf("Here is your final board:\n");
    for(i = 0; i < BOARD_SIZE; i++){
        for(j = 0; j < BOARD_SIZE; j++){
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Initialize the check arrays
    for(i = 0; i < BOARD_SIZE; i++){
        rowCheck[i] = 0;
        colCheck[i] = 0;
    }
    leftDiagCheck = 0;
    rightDiagCheck = 0;

    // Play the game
    printf("Let's play Bingo!\n");
    while(1){
        printf("Enter a number (1-75): ");
        scanf("%d", &num);
        printf("\n");
        if(num < 1 || num > 75){
            printf("Invalid input. Please enter a number between 1 and 75.\n");
            continue;
        }
        // Check if the number is on the board
        isBingo = 0;
        for(i = 0; i < BOARD_SIZE; i++){
            for(j = 0; j < BOARD_SIZE; j++){
                if(board[i][j] == num){
                    isBingo = 1;
                    // Mark the number on the board
                    board[i][j] = -1;
                    // Update the check arrays
                    rowCheck[i]++;
                    colCheck[j]++;
                    if(i == j) leftDiagCheck++;
                    if(i == BOARD_SIZE-1-j) rightDiagCheck++;
                    // Check for win conditions
                    if(rowCheck[i] == BOARD_SIZE || colCheck[j] == BOARD_SIZE ||
                        leftDiagCheck == BOARD_SIZE || rightDiagCheck == BOARD_SIZE){
                        printf("BINGO! You win!\n");
                        return 0;
                    }
                    break;
                }
            }
            if(isBingo) break;
        }
        if(!isBingo) printf("Sorry, the number is not on your board.\n");
        // Print the updated board
        printf("Here is your updated board:\n");
        for(i = 0; i < BOARD_SIZE; i++){
            for(j = 0; j < BOARD_SIZE; j++){
                printf("%2d ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}