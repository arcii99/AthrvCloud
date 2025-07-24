//FormAI DATASET v1.0 Category: Memory Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 50

// Function to print the grid
void print_grid(int grid[][COLS]) {
    printf("    1   2   3   4   5\n");
    printf("------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d | ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == -1) {
                printf("  | ");
            }
            else {
                printf("%2d| ", grid[i][j]);
            }
        }
        printf("\n");
        printf("------------------------\n");
    }
    printf("\n");
}

// Function to generate random numbers to be placed in the grid
void gen_random_numbers(int grid[][COLS], int num_count) {
    int nums_placed = 0;
    while (nums_placed < num_count) {
        int rand_x = rand() % ROWS;
        int rand_y = rand() % COLS;
        if (grid[rand_x][rand_y] == -1) {
            grid[rand_x][rand_y] = rand() % MAX_NUM;
            nums_placed++;
        }
    }
}

// Function to check if two cells have already been matched
bool check_matched(int matched[][2], int num1_x, int num1_y, int num2_x, int num2_y) {
    for (int i = 0; i < ROWS*COLS; i++) {
        if (matched[i][0] == num1_x && matched[i][1] == num1_y) {
            return true;
        }
        if (matched[i][0] == num2_x && matched[i][1] == num2_y) {
            return true;
        }
    }
    return false;
}

// Function to check if the given two numbers are a match
bool check_match(int grid[][COLS], int num1_x, int num1_y, int num2_x, int num2_y, int matched[][2], int *matched_count) {
    if (grid[num1_x][num1_y] == grid[num2_x][num2_y] && 
        !check_matched(matched, num1_x, num1_y, num2_x, num2_y)) {
        matched[*matched_count][0] = num1_x;
        matched[*matched_count][1] = num1_y;
        (*matched_count)++;
        return true;
    }
    return false;
}

// Main function to play the game
int main() {
    int grid[ROWS][COLS];
    int matched[ROWS*COLS/2][2];
    int matched_count = 0;
    srand(time(0));

    // Initialize grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = -1;
        }
    }

    // Generate random numbers in grid
    gen_random_numbers(grid, ROWS*COLS/2);

    // Main game loop
    int num1_x, num1_y, num2_x, num2_y;
    bool first_selection = true;
    while (matched_count < ROWS*COLS/2) {
        // Print grid
        print_grid(grid);
        if (first_selection) {
            printf("Select first number (row col): ");
            scanf("%d %d", &num1_x, &num1_y);
            printf("\n");
            while (grid[num1_x-1][num1_y-1] == -1) {
                printf("Invalid selection, try again\n");
                printf("Select first number (row col): ");
                scanf("%d %d", &num1_x, &num1_y);
                printf("\n");
            }
            first_selection = false;
        }
        else {
            printf("Select second number (row col): ");
            scanf("%d %d", &num2_x, &num2_y);
            printf("\n");
            while (grid[num2_x-1][num2_y-1] == -1) {
                printf("Invalid selection, try again\n");
                printf("Select second number (row col): ");
                scanf("%d %d", &num2_x, &num2_y);
                printf("\n");
            }
            if (check_match(grid, num1_x-1, num1_y-1, num2_x-1, num2_y-1, matched, &matched_count)) {
                printf("MATCH!\n");
                grid[num1_x-1][num1_y-1] = -1;
                grid[num2_x-1][num2_y-1] = -1;
            }
            else {
                printf("NO MATCH, try again\n");
            }
            first_selection = true;
        }
    }
    printf("Congratulations, you won!\n");
    return 0;
}