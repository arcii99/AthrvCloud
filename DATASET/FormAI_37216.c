//FormAI DATASET v1.0 Category: Memory Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare function to shuffle array
void shuffle(int arr[], int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        // Generate random index to swap current index with
        int j = rand() % (i + 1);
        // Swap the elements at current index and random index
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Declare array of numbers to match
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int numSize = sizeof(nums) / sizeof(nums[0]);
    
    // Shuffle the array
    shuffle(nums, numSize);
    
    // Declare empty game board and fill with shuffled numbers
    int board[4][4] = { { nums[0], nums[1], nums[2], nums[3] },
                        { nums[4], nums[5], nums[6], nums[7] },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
    
    // Declare game variables and timer
    int row1, col1, row2, col2;
    char temp;
    time_t startTime, endTime, elapsedTime;
    startTime = time(NULL);
    
    // Begin game loop
    while (1) {
        // Print current game board
        printf("  1 2 3 4\n");
        for (int row = 0; row < 4; row++) {
            printf("%d ", row + 1);
            for (int col = 0; col < 4; col++) {
                if (board[row][col] == 0) {
                    printf(". ");
                } else {
                    printf("%d ", board[row][col]);
                }
            }
            printf("\n");
        }
        
        // Get first input from player
        printf("Enter the row and column of the first card: ");
        scanf("%d %d", &row1, &col1);
        row1--;
        col1--;
        if (row1 < 0 || row1 > 3 || col1 < 0 || col1 > 3) {
            printf("Invalid input. Please try again.\n");
            while ((temp = getchar()) != EOF && temp != '\n');
            continue;
        }
        // Check if card has already been flipped
        if (board[row1][col1] == 0) {
            printf("That card has already been matched. Please try again.\n");
            continue;
        }
        // Reveal first card
        printf("Card at (%d,%d): %d\n", row1 + 1, col1 + 1, board[row1][col1]);
        
        // Get second input from player
        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &row2, &col2);
        row2--;
        col2--;
        if (row2 < 0 || row2 > 3 || col2 < 0 || col2 > 3) {
            printf("Invalid input. Please try again.\n");
            while ((temp = getchar()) != EOF && temp != '\n');
            continue;
        }
        // Check if card has already been flipped
        if (board[row2][col2] == 0) {
            printf("That card has already been matched. Please try again.\n");
            continue;
        }
        // Reveal second card
        printf("Card at (%d,%d): %d\n", row2 + 1, col2 + 1, board[row2][col2]);
        
        // Check if cards match
        if (board[row1][col1] == board[row2][col2]) {
            printf("Match! Removing cards...\n");
            board[row1][col1] = 0;
            board[row2][col2] = 0;
        } else {
            printf("No match. Please try again.\n");
        }
        
        // Check if game is over
        int count = 0;
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) {
                if (board[row][col] != 0) {
                    count++;
                }
            }
        }
        if (count == 0) {
            printf("Congratulations! You have won the game!\n");
            endTime = time(NULL);
            elapsedTime = endTime - startTime;
            printf("Time taken to complete game: %ld seconds\n", elapsedTime);
            break;
        }
    }
    
    return 0;
}