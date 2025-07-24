//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>

#define ROWS 20
#define COLS 20

int main() {
    int arr[ROWS][COLS] = {0};  // Initialize the array with 0
    
    // Randomly initialize some cells to 1 to start the game
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            if(rand()%2 == 1) {
                arr[i][j] = 1;
            }
        }
    }
    
    int gen_count = 0;
    int prev_arr[ROWS][COLS];
    
    // Continue the game for a certain number of generations
    while(gen_count < 1000) {
        // Copy the array to previous array for comparison
        for(i=0; i<ROWS; i++) {
            for(j=0; j<COLS; j++) {
                prev_arr[i][j] = arr[i][j];
            }
        }
        
        // Apply the game rules to update the current array
        for(i=0; i<ROWS; i++) {
            for(j=0; j<COLS; j++) {
                int live_neighbours = 0;
                if(i > 0 && prev_arr[i-1][j] == 1) {
                    live_neighbours++;
                }
                if(i < ROWS-1 && prev_arr[i+1][j] == 1) {
                    live_neighbours++;
                }
                if(j > 0 && prev_arr[i][j-1] == 1) {
                    live_neighbours++;
                }
                if(j < COLS-1 && prev_arr[i][j+1] == 1) {
                    live_neighbours++;
                }
                if(i > 0 && j > 0 && prev_arr[i-1][j-1] == 1) {
                    live_neighbours++;
                }
                if(i < ROWS-1 && j < COLS-1 && prev_arr[i+1][j+1] == 1) {
                    live_neighbours++;
                }
                if(i > 0 && j < COLS-1 && prev_arr[i-1][j+1] == 1) {
                    live_neighbours++;
                }
                if(i < ROWS-1 && j > 0 && prev_arr[i+1][j-1] == 1) {
                    live_neighbours++;
                }
                
                if(prev_arr[i][j] == 1) {
                    if(live_neighbours < 2 || live_neighbours > 3) {
                        arr[i][j] = 0;
                    }
                }
                else {
                    if(live_neighbours == 3) {
                        arr[i][j] = 1;
                    }
                }
            }
        }
        
        // Print the current generation
        printf("Generation %d:\n", gen_count+1);
        for(i=0; i<ROWS; i++) {
            for(j=0; j<COLS; j++) {
                printf("%s", arr[i][j] ? "*" : " ");
            }
            printf("\n");
        }
        printf("\n");
        
        // Increment the generation count
        gen_count++;
    }

    return 0;
}