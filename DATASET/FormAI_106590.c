//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int main()
{
    int grid[SIZE][SIZE] = {0};
    int temp[SIZE][SIZE] = {0};
    int i, j;
    srand(time(NULL));
    
    /* Randomly fill the grid */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    /* Game of Life Logic */
    while (1) {
        /* Print the grid */
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j] == 1) {
                    printf("* ");
                } else {
                    printf("- ");
                }
            }
            printf("\n");
        }
        printf("\n");
        
        /* Copy the current state to temp */
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                temp[i][j] = grid[i][j];
            }
        }
        
        /* Apply the rules of Game of Life to create the next state */
        for (i = 1; i < SIZE-1; i++) {
            for (j = 1; j < SIZE-1; j++) {
                int count = 0;
                count += grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1];
                count += grid[i][j-1] + grid[i][j+1];
                count += grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
                
                if (grid[i][j] == 1) {
                    if (count < 2 || count > 3) {
                        temp[i][j] = 0;
                    }
                } else {
                    if (count == 3) {
                        temp[i][j] = 1;
                    }
                }
            }
        }
        
        /* Copy the new state back to grid */
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                grid[i][j] = temp[i][j];
            }
        }
        
        /* Wait for a second before printing the next state */
        sleep(1);
        
        /* Clear the console */
        system("clear");
    }
    
    return 0;
}