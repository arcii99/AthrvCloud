//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generate_card(int card[ROWS][COLS]) {
    int nums[15];
    int row, col, num;

    // Initialize array with zeros
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            card[row][col] = 0;
        }
    }

    // Generate random numbers for each column
    for (col = 0; col < COLS; col++) {
        // Generate unique random numbers
        for (num = 0; num < 15; num++) {
            nums[num] = num + 1;
        }
        srand(time(NULL)); // Seed random number generator
        for (num = 0; num < 15; num++) {
            int index = rand() % 15;
            int temp = nums[num];
            nums[num] = nums[index];
            nums[index] = temp;
        }
        // Assign numbers to card
        for (row = 0; row < ROWS; row++) {
            if (col == 2 && row == 2) { // "Free" space
                continue;
            }
            card[row][col] = nums[row];
        }
    }
}

void print_card(int card[ROWS][COLS]) {
    int row, col;
    printf("+----+----+----+----+----+\n");
    for (row = 0; row < ROWS; row++) {
        printf("|");
        for (col = 0; col < COLS; col++) {
            if (col == 2 && row == 2) { // "Free" space
                printf("  X |");
            } else if (card[row][col] == 0) {
                printf("    |");
            } else {
                printf(" %2d |", card[row][col]);
            }
        }
        printf("\n+----+----+----+----+----+\n");
    }
}

int check_bingo(int card[ROWS][COLS], int *row, int *col) {
    int bingo = 0;

    // Check rows for bingo
    for (*row = 0; *row < ROWS; (*row)++) {
        int count = 0;
        for (*col = 0; *col < COLS; (*col)++) {
            if (card[*row][*col] == 0) {
                count++;
            }
        }
        if (count == 5) {
            bingo = 1;
            break;
        }
    }

    // Check columns for bingo
    if (!bingo) {
        for (*col = 0; *col < COLS; (*col)++) {
            int count = 0;
            for (*row = 0; *row < ROWS; (*row)++) {
                if (card[*row][*col] == 0) {
                    count++;
                }
            }
            if (count == 5) {
                bingo = 1;
                break;
            }
        }
    }

    // Check diagonal for bingo
    if (!bingo) {
        int count = 0;
        for (*row = 0, *col = 0; *row < ROWS && *col < COLS; (*row)++, (*col)++) {
            if (card[*row][*col] == 0) {
                count++;
            }
        }
        if (count == 5) {
            bingo = 1;
        }
    }

    // Check reverse diagonal for bingo
    if (!bingo) {
        int count = 0;
        for (*row = 0, *col = COLS-1; *row < ROWS && *col >= 0; (*row)++, (*col)--) {
            if (card[*row][*col] == 0) {
                count++;
            }
        }
        if (count == 5) {
            bingo = 1;
        }
    }

    return bingo;
}

int main() {
    int card[ROWS][COLS];
    int row, col;
    char name[50];
    printf("Welcome to C Bingo Simulator!\n");
    printf("What is your name? ");
    scanf("%s", name);

    // Generate card and print
    generate_card(card);
    printf("\n%s's Bingo Card:\n", name);
    print_card(card);

    // Play game
    int num, found = 0, calls = 0, bingo = 0;
    srand(time(NULL)); // Seed random number generator
    while (!bingo) {
        num = rand() % 75 + 1; // Generate random number between 1 and 75
        calls++;
        printf("\nNext call: %d\n", num);

        // Check if number is on card
        for (row = 0; row < ROWS; row++) {
            for (col = 0; col < COLS; col++) {
                if (card[row][col] == num) {
                    card[row][col] = 0;
                    found++;
                }
            }
        }

        // Print updated card
        printf("\n%s's Bingo Card (calls: %d, found: %d):\n", name, calls, found);
        print_card(card);

        // Check for bingo
        if (check_bingo(card, &row, &col)) {
            printf("\nBINGO! %s won after %d calls!\n", name, calls);
            printf("%s's winning card (row: %d, column: %d):\n", name, row+1, col+1);
            print_card(card);
            bingo = 1;
        }
    }

    return 0;
}