//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the game board
void initializeBoard(int board[][4]) {
    int i, j;    
    // Set all values to 0
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            board[i][j] = 0;
        }
    }    
    // Place the cards randomly on the board
    int count = 0, num;    
    while(count < 8) {        
        num = rand() % 8 + 1;
        i = rand() % 4;
        j = rand() % 4;        
        if(board[i][j] == 0) {
            board[i][j] = num;
            count++;
        }
    }
}

// Function to print the game board
void printBoard(int board[][4]) {
    int i, j;    
    printf("\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(board[i][j] == 0) {
                printf("  -  ");
            }
            else {
                printf("  %d ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to reveal the selected card
void revealCard(int board[][4], int i, int j) {
    board[i][j] = abs(board[i][j]);
}

// Function to hide the selected card
void hideCard(int board[][4], int i, int j) {
    board[i][j] = abs(board[i][j]) * -1;
}

// Function to check if the game is over
int checkGameOver(int board[][4]) {
    int i, j, count = 0;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            if(board[i][j] <= 0) {
                count++;
            }
        }
    }
    if(count == 16) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to get the user's input
void getUserInput(int *row, int *col) {
    printf("Enter the row and column of the card you want to reveal: ");
    scanf("%d %d", row, col);
    printf("\n");
}

int main() {
    int board[4][4], i, j, firstRow, firstCol, secondRow, secondCol, turns = 0;
    // Seed the random number generator
    srand(time(NULL));
    // Initialize the game board
    initializeBoard(board);
    // Print the game board
    printBoard(board);
    // Loop until the game is over
    while(!checkGameOver(board)) {
        // Get the user's input for the first card
        getUserInput(&firstRow, &firstCol);
        // Reveal the first card
        revealCard(board, firstRow, firstCol);
        // Print the game board
        printBoard(board);
        // Get the user's input for the second card
        getUserInput(&secondRow, &secondCol);
        // Reveal the second card
        revealCard(board, secondRow, secondCol);
        // Print the game board
        printBoard(board);
        // Compare the cards
        if(board[firstRow][firstCol] == board[secondRow][secondCol]) {
            printf("You found a match!\n");
            // Hide the matched cards
            hideCard(board, firstRow, firstCol);
            hideCard(board, secondRow, secondCol);
        }
        else {
            printf("Sorry, those cards do not match.\n");
            // Hide the unmatched cards
            hideCard(board, firstRow, firstCol);
            hideCard(board, secondRow, secondCol);
        }
        // Increment the number of turns
        turns++;
        // Print the game board
        printBoard(board);
    }
    // Print the game over message
    printf("Congratulations, you won the game in %d turns!\n", turns);
    return 0;
}