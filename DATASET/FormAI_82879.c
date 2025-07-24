//FormAI DATASET v1.0 Category: Table Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int rows, cols, num, row_guess, col_guess, guess_count = 0;
    printf("Welcome to the Surreal C Table Game!\n");
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    num = rand() % (rows * cols) + 1; // pick a random number from 1 to rows*cols
    printf("Great! Here's your %d x %d table with a random number hidden inside:\n", rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%2d ", rand() % 100);
        }
        printf("\n");
    }
    printf("Can you guess which cell the number is in?\n");
    do {
        printf("Guess row (1-%d): ", rows);
        scanf("%d", &row_guess);
        printf("Guess column (1-%d): ", cols);
        scanf("%d", &col_guess);
        guess_count++;
        if (row_guess < 1 || row_guess > rows || col_guess < 1 || col_guess > cols) {
            printf("Invalid guess, try again.");
        } else if ((row_guess - 1) * cols + col_guess == num) {
            printf("Congratulations, you found the hidden number in %d guesses!\n", guess_count);
        } else {
            printf("Nope, not there. Keep guessing!\n");
        }
    } while ((row_guess - 1) * cols + col_guess != num);
    return 0;
}