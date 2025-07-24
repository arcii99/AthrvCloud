//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROWS 5
#define NUM_COLS 5
#define NUM_BINGO_NUMS 75

int main() {
    int bingo_card[NUM_ROWS][NUM_COLS];
    int selected_nums[NUM_BINGO_NUMS];
    int num_calls = 0;
    
    // Initialize bingo card
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            bingo_card[i][j] = 0;
        }
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Play bingo!
    while (num_calls < NUM_BINGO_NUMS) {
        int num = rand() % NUM_BINGO_NUMS + 1; // Generate a random number between 1 and 75
        
        // Check if number has already been called
        int already_selected = 0;
        for (int i = 0; i < num_calls; i++) {
            if (selected_nums[i] == num) {
                already_selected = 1;
                break;
            }
        }
        
        // If number has not already been called, add it to the list and update bingo card
        if (!already_selected) {
            selected_nums[num_calls] = num;
            num_calls++;
            
            // Update bingo card
            for (int i = 0; i < NUM_ROWS; i++) {
                for (int j = 0; j < NUM_COLS; j++) {
                    if (bingo_card[i][j] == num) {
                        bingo_card[i][j] = -1;
                        break;
                    }
                }
            }
            
            // Check for a bingo
            int bingo = 0;
            for (int i = 0; i < NUM_ROWS; i++) {
                int row_sum = 0;
                int col_sum = 0;
                for (int j = 0; j < NUM_COLS; j++) {
                    row_sum += bingo_card[i][j];
                    col_sum += bingo_card[j][i];
                }
                if (row_sum == -5 || col_sum == -5) {
                    bingo = 1;
                    break;
                }
            }
            if (bingo) {
                printf("BINGO!\n");
                break;
            }
        }
    }
    
    // Display completed bingo card
    printf("Bingo Card:\n");
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            if (bingo_card[i][j] == -1) {
                printf("X ");
            } else {
                printf("%d ", bingo_card[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}