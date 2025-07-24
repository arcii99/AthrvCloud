//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to initialize the bingo card
void initialize_card(int card[][COLS], int max_num) {
    int nums[max_num];

    // Initialize the array with all the possible numbers
    for (int i = 0; i < max_num; i++) {
        nums[i] = i + 1;
    }

    // Shuffle the array
    srand(time(NULL));
    for (int i = max_num - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // Assign the numbers to the card
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = nums[index];
            index++;
        }
    }
}

// Function to print the bingo card
void print_card(int card[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is on the bingo card
int check_number(int card[][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                card[i][j] = 0; // Mark the number as used
                return 1; // Number found on card
            }
        }
    }
    return 0; // Number not on card
}

// Function to check if a bingo row or column has all zeros (i.e. filled with used numbers)
int check_bingo(int card[][COLS]) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            return 1; // Row is a bingo
        }
    }

    // Check columns
    for (int j = 0; j < COLS; j++) {
        int count = 0;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1; // Column is a bingo
        }
    }

    return 0; // No bingos found
}

int main() {
    int card[ROWS][COLS];
    int max_num = ROWS * COLS;
    int num_calls = 0;

    initialize_card(card, max_num);

    printf("BINGO SIMULATOR\n\n");

    while (1) {
        int num = rand() % max_num + 1;
        num_calls++;

        printf("Call: %d\n", num);

        if (check_number(card, num)) {
            printf("Number found on card!\n\n");
            print_card(card);
            printf("\n");
            if (check_bingo(card)) {
                printf("BINGO!!!\n");
                break;
            }
        } else {
            printf("Number not on card.\n\n");
        }
    }

    printf("Total number of calls: %d\n", num_calls);

    return 0;
}