//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// function prototypes
void print_card(int bingo_card[ROWS][COLS]);
void generate_numbers(int* numbers_drawn);

int main() {
    int bingo_card[ROWS][COLS] = {0}; // initialize all elements to 0
    int numbers_drawn[75] = {0}; // initialize all elements to 0
    int num_bingo = 0; // number of bingos found

    // seed the random number generator with current time
    srand(time(NULL));

    // generate a random bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 2) && (j == 2)) { // if in center, leave blank
                continue;
            }
            int num = (j * 15) + (rand() % 15) + 1; // generate a number between 1 and 75
            // make sure the number is not already on the card
            while (1) {
                int found = 0;
                for (int k = 0; k < j; k++) {
                    if (bingo_card[i][k] == num) {
                        found = 1;
                        num = (j * 15) + (rand() % 15) + 1;
                        break;
                    }
                }
                if (!found) {
                    break;
                }
            }
            bingo_card[i][j] = num;
        }
    }

    printf("Welcome to BINGO!\n");
    printf("Here is your card:\n");
    print_card(bingo_card);

    // loop until there is at least one bingo
    while (num_bingo == 0) {
        printf("Press enter to draw the next number.\n");
        getchar();

        int num;
        // make sure the number is not already drawn
        while (1) {
            num = rand() % 75 + 1;
            if (numbers_drawn[num - 1] == 0) {
                numbers_drawn[num - 1] = 1;
                break;
            }
        }
        printf("The next number is: %d\n", num);

        // check if any number on the card matches the drawn number
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (bingo_card[i][j] == num) {
                    bingo_card[i][j] = 0; // mark as found on the card
                }
            }
        }
        print_card(bingo_card);

        // check for bingos
        int bingo_found = 0;

        // check rows
        for (int i = 0; i < ROWS; i++) {
            int row_sum = 0;
            for (int j = 0; j < COLS; j++) {
                row_sum += bingo_card[i][j];
            }
            if (row_sum == 0) {
                bingo_found = 1;
                num_bingo++;
                printf("BINGO! Row %d\n", i + 1);
            }
        }

        // check columns
        for (int j = 0; j < COLS; j++) {
            int col_sum = 0;
            for (int i = 0; i < ROWS; i++) {
                col_sum += bingo_card[i][j];
            }
            if (col_sum == 0) {
                bingo_found = 1;
                num_bingo++;
                printf("BINGO! Column %d\n", j + 1);
            }
        }

        // check diagonal from top-left to bottom-right
        int diagonal_sum = 0;
        for (int i = 0; i < ROWS; i++) {
            diagonal_sum += bingo_card[i][i];
        }
        if (diagonal_sum == 0) {
            bingo_found = 1;
            num_bingo++;
            printf("BINGO! Diagonal from top-left to bottom-right\n");
        }

        // check diagonal from bottom-left to top-right
        diagonal_sum = 0;
        for (int i = 0, j = COLS - 1; i < ROWS && j >= 0; i++, j--) {
            diagonal_sum += bingo_card[i][j];
        }
        if (diagonal_sum == 0) {
            bingo_found = 1;
            num_bingo++;
            printf("BINGO! Diagonal from bottom-left to top-right\n");
        }

        if (bingo_found) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}

// function to print the bingo card
void print_card(int bingo_card[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((i == 2) && (j == 2)) { // if in center, print blank
                printf("  ");
            }
            else {
                printf("%2d ", bingo_card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to generate 75 random numbers from 1 to 75
void generate_numbers(int* numbers_drawn) {
    for (int i = 0; i < 75; i++) {
        numbers_drawn[i] = i + 1;
    }
    // shuffle the array using Fisher-Yates algorithm
    for (int i = 74; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = numbers_drawn[i];
        numbers_drawn[i] = numbers_drawn[j];
        numbers_drawn[j] = temp;
    }
}