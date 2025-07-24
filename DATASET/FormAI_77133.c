//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define ROWS 5
#define COLS 5

int main() {
    srand(time(NULL)); 
    
    int bingo_card[ROWS][COLS];
    
    // Initialize the bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) {
                bingo_card[i][j] = 0;
            }
            else {
                bingo_card[i][j] = rand() % 15 + j * 15 + 1;
            }
        }
    }
    
    // Print out the bingo card
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (j == 0) {
                printf("%2d ", bingo_card[i][j]);
            }
            else {
                printf("| %2d ", bingo_card[i][j]);
            }
        }
        printf("\n");
    }
    
    int numbers_called[75] = {0};
    int number_of_called_numbers = 0;
    int bingo = 0;
    
    // Keep calling numbers until someone gets a bingo
    while (bingo == 0) {
        int number_called = rand() % 75 + 1;
        
        // Check if the number has already been called
        int already_called = 0;
        for (int i = 0; i < number_of_called_numbers; i++) {
            if (numbers_called[i] == number_called) {
                already_called = 1;
                break;
            }
        }
        
        // Add the number to the list of called numbers
        if (already_called == 0) {
            numbers_called[number_of_called_numbers] = number_called;
            number_of_called_numbers++;
        }
        
        // Check if anyone has a bingo
        for (int i = 0; i < ROWS; i++) {
            int row_match = 0;
            int col_match = 0;
            int diag_match1 = 0;
            int diag_match2 = 0;
            
            for (int j = 0; j < COLS; j++) {
                // Check row
                if (bingo_card[i][j] == number_called) {
                    row_match++;
                }
                
                // Check column
                if (bingo_card[j][i] == number_called) {
                    col_match++;
                }
                
                // Check diagonal 1
                if (i == j && bingo_card[i][j] == number_called) {
                    diag_match1++;
                }
                
                // Check diagonal 2
                if (i + j == 4 && bingo_card[i][j] == number_called) {
                    diag_match2++;
                }
            }
            
            // Check for bingo
            if (row_match == 5 || col_match == 5 || diag_match1 == 5 || diag_match2 == 5) {
                bingo = 1;
                printf("BINGO!\n");
                break;
            }
        }
    }
    
    return 0;
}