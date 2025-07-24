//FormAI DATASET v1.0 Category: Table Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("\nWelcome to the Ephemeral Table Game!\n\n");
    
    // Initialize variables
    srand(time(NULL));
    int table[10][10], playerScore = 0, computerScore = 0;
    
    // Fill table with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = rand() % 10;
        }
    }
    
    printf("The table has been created. Here it is:\n\n");
    
    // Print the table
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\n");
    
    // Start game loop
    while (1) {
        // Player's turn
        printf("It's your turn!\n");
        printf("Enter the row and column of an element to add to your score (Separate with space): ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 10 || col < 1 || col > 10) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        playerScore += table[row - 1][col - 1];
        printf("Your current score is %d.\n\n", playerScore);
        
        // Computer's turn
        printf("It's the computer's turn!\n");
        int computerRow = rand() % 10 + 1;
        int computerCol = rand() % 10 + 1;
        computerScore += table[computerRow - 1][computerCol - 1];
        printf("The computer chose row %d and column %d. Its current score is %d.\n\n", computerRow, computerCol, computerScore);
        
        // Check for winner
        if (playerScore >= 100) {
            printf("Congratulations! You won with a score of %d to %d.\n", playerScore, computerScore);
            break;
        }
        if (computerScore >= 100) {
            printf("Sorry, you lost with a score of %d to %d.\n", playerScore, computerScore);
            break;
        }
    }
    
    return 0;
}