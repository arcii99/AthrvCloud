//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    // prompt user to enter grid size
    int size;
    printf("Enter the size of the grid (max 10): ");
    scanf("%d", &size);
    
    // create grid
    int grid[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = rand() % 75 + 1; // fill grid with random numbers 1-75
        }
    }

    // print grid
    printf("\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%-3d ", grid[i][j]);
        }
        printf("\n");
    }

    // play bingo
    int count = 0;
    while (count < size*size) {
        // prompt user to enter number
        int num;
        printf("\n\nEnter a number between 1 and 75: ");
        scanf("%d", &num);
        if (num < 1 || num > 75) {
            printf("Invalid input. Try again.\n");
            continue;
        }

        // check if number is in grid
        int found = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == num) {
                    grid[i][j] = 0; // mark number as found
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }

        if (found) {
            count++;
            printf("Number found! %d remaining.\n", size*size-count);
        } else {
            printf("Number not found. Try again.\n");
        }

        // check for bingo
        int bingo = 0;
        for (int i = 0; i < size; i++) {
            int row_sum = 0;
            int col_sum = 0;
            for (int j = 0; j < size; j++) {
                row_sum += grid[i][j];
                col_sum += grid[j][i];
            }
            if (row_sum == 0 || col_sum == 0) {
                bingo = 1;
                break;
            }
        }
        if (bingo) {
            printf("\n\nBINGO! You win!");
            break;
        }
    }

    if (count == size*size) {
        printf("\n\nOut of moves. Game over.");
    }

    return 0;
}