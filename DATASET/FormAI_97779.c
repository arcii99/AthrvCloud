//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to display the game board
void displayBoard(int board[], int size) {
    printf("\n");

    // Loop over every element in the board array
    for(int i = 0; i < size; i++) {
        // If the current element is not the first element in a row, add a vertical line
        if(i % 3 == 0 && i != 0) {
            printf("|");
        }

        // If the current element is 0, print an underscore. Otherwise, print the value of the element
        if(board[i] == 0) {
            printf("_");
        } else {
            printf("%d", board[i]);
        }

        // If the current element is the last element in a row, add a new line character
        if((i + 1) % 9 == 0) {
            printf("\n");
        }
    }

    printf("\n");
}

// Function to check if a move is valid
int isValidMove(int board[], int position, int value) {
    // Check if the row already contains the value
    for(int i = (position / 9) * 9; i < (position / 9) * 9 + 9; i++) {
        if(board[i] == value) {
            return 0;
        }
    }

    // Check if the column already contains the value
    for(int i = position % 9; i < position % 9 + 81; i += 9) {
        if(board[i] == value) {
            return 0;
        }
    }

    // Check if the 3x3 box already contains the value
    int boxX = (position % 9) / 3;
    int boxY = (position / 9) / 3;
    for(int i = boxY * 27 + boxX * 3; i < boxY * 27 + boxX * 3 + 3; i++) {
        for(int j = i; j < i + 19; j += 9) {
            if(board[j] == value) {
                return 0;
            }
        }
    }

    // If the move is valid, return 1
    return 1;
}

int main() {
    // Define the size of the board
    int boardSize = 81;

    // Initialize the game board
    int board[boardSize];

    // Seed the random number generator
    srand(time(NULL));

    // Loop over every element in the board array and set it to 0
    for(int i = 0; i < boardSize; i++) {
        board[i] = 0;
    }

    // Generate a random number of starting cells
    int numStartingCells = rand() % 11 + 20;

    // Loop over the number of starting cells and randomly select cells to fill in with a random value
    for(int i = 0; i < numStartingCells; i++) {
        int position = rand() % boardSize;
        int value = rand() % 9 + 1;

        // Check if the move is valid. If it is, fill in the cell with the value. If not, try again.
        if(isValidMove(board, position, value)) {
            board[position] = value;
        } else {
            i--;
        }
    }

    // Display the game board
    displayBoard(board, boardSize);

    // Loop over the game until the board is full or the user quits
    int numFilled = 0;
    while(numFilled < boardSize) {
        // Prompt the user for a move
        printf("> ");
        int position, value;
        scanf("%d %d", &position, &value);

        // Check if the user wants to quit
        if(position == -1 && value == -1) {
            break;
        }

        // Check if the move is valid. If it is, fill in the cell with the value. If not, tell the user the move is invalid.
        if(isValidMove(board, position, value)) {
            board[position] = value;
            numFilled++;
        } else {
            printf("Invalid move!\n");
        }

        // Display the game board
        displayBoard(board, boardSize);
    }

    // Print a message indicating the end of the game
    printf("Game Over!\n");

    return 0;
}