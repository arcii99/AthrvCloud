//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    // Initialize variables
    int i, j;
    int callNum; // The number that's been called
    bool bingo = false; // Did someone get a Bingo?
    char board[5][5] = { // Board initialization
        {'B', 'I', 'N', 'G', 'O'},
        {15, 20, 35, 57, 72},
        {6, 18, 41, 49, 62},
        {1, 24, 34, 55, 68},
        {3, 29, 44, 59, 74}
    };
    
    // Print starting message
    printf("Welcome to the Bingo Simulator!\n");
    printf("Press ENTER to begin...\n");
    getchar();
    
    // Loop through and call numbers until a Bingo is achieved
    while (!bingo) {
        // Generate random number
        callNum = rand() % 75 + 1;
        
        // Print called number
        printf("\n%d!\n", callNum);
        
        // Check if number is on the board and replace with an X if found
        for (i = 1; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (board[i][j] == callNum) {
                    board[i][j] = 'X';
                }
            }
        }
        
        // Print updated board
        printf("\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                printf("%c\t", board[i][j]);
            }
            printf("\n\n");
        }
        
        // Check for a Bingo
        for (i = 1; i < 5; i++) {
            // Horizontal row
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == 'X' && board[i][3] == 'X' && board[i][4] == 'X') {
                printf("BINGO! Horizontal row %d!\n", i);
                bingo = true;
            }
            // Vertical column
            else if (board[1][i] == 'X' && board[2][i] == 'X' && board[3][i] == 'X' && board[4][i] == 'X' && board[5][i] == 'X') {
                printf("BINGO! Vertical column %d!\n", i);
                bingo = true;
            }
            // Diagonal
            else if ((board[1][1] == 'X' && board[2][2] == 'X' && board[3][3] == 'X' && board[4][4] == 'X' && board[5][5] == 'X') ||
                     (board[1][5] == 'X' && board[2][4] == 'X' && board[3][3] == 'X' && board[4][2] == 'X' && board[5][1] == 'X')) {
                printf("BINGO! Diagonal!\n");
                bingo = true;
            }
        }
        
        // Wait for user to press ENTER before continuing
        printf("\nPress ENTER to continue...\n");
        getchar();
        
        // Clear screen
        system("clear");
    }
    
    // Print ending message
    printf("Congratulations! You won Bingo!");
    
    return 0;
}