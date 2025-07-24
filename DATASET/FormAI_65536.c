//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int rows, cols, choice_row, choice_col, guess_row, guess_col;
    srand(time(0)); // Initialize the random number generator
    
    printf("Welcome to the C Table Game!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Initialize the table with random numbers between 0 and 9
    int table[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            table[i][j] = rand() % 10;
        }
    }

    // Print the table
    printf("\nHere is the table:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    // Ask the user to choose a cell
    printf("\nChoose a cell to reveal (Row Column): ");
    scanf("%d %d", &choice_row, &choice_col);
    printf("The value in the cell you chose is: %d\n", table[choice_row][choice_col]);

    // Ask the user to guess the value of another cell
    printf("\nGuess the value of another cell (Row Column): ");
    scanf("%d %d", &guess_row, &guess_col);

    // Check if the guess is correct
    if(table[guess_row][guess_col] == table[choice_row][choice_col]) {
        printf("Congratulations! You guessed correctly.\n");
    } else {
        printf("Sorry, that's not correct. The value of the cell you chose was: %d\n", table[choice_row][choice_col]);
    }

    return 0;
}