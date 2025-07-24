//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 75

void generate_card(int card[ROWS][COLS], int nums[], int num_count) {
    int i, j, num_index;
    int used_nums[MAX_NUM] = {0}; // array to keep track of used numbers
    srand(time(NULL));  // set random seed based on current time

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            // make sure each column has at least one non-zero number
            if (i == 2 && j == 2) {
                card[i][j] = 0;
                continue;
            }

            // randomly select a number that hasn't been used yet
            do {
                num_index = rand() % num_count;
            } while (used_nums[nums[num_index] - 1]);

            card[i][j] = nums[num_index];
            used_nums[nums[num_index] - 1] = 1;
        }
    }
}

void print_card(int card[ROWS][COLS]) {
    int i, j;

    printf("B\tI\tN\tG\tO\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf(" \t");
            } else {
                printf("%d\t", card[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n");
}

int check_bingo(int card[ROWS][COLS]) {
    int i, j, count, line;

    // check rows
    for (i = 0; i < ROWS; i++) {
        count = 0;
        for (j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == COLS) {
            return 1; // bingo
        }
    }

    // check columns
    for (j = 0; j < COLS; j++) {
        count = 0;
        for (i = 0; i < ROWS; i++) {
            if (card[i][j] == 0) {
                count++;
            }
        }
        if (count == ROWS) {
            return 1; // bingo
        }
    }

    // check diagonal (top-left to bottom-right)
    count = 0;
    for (i = 0; i < ROWS; i++) {
        j = i;
        if (card[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // bingo
    }

    // check diagonal (top-right to bottom-left)
    count = 0;
    for (i = 0, j = COLS-1; i < ROWS && j >= 0; i++, j--) {
        if (card[i][j] == 0) {
            count++;
        }
    }
    if (count == ROWS) {
        return 1; // bingo
    }

    return 0; // no bingo
}

void simulate_game(int nums[], int num_count) {
    int card[ROWS][COLS];
    int called[MAX_NUM] = {0}; // array to keep track of called numbers
    int num_index, num, i, j, winner;

    generate_card(card, nums, num_count);
    print_card(card);

    // keep calling numbers until someone wins
    winner = 0;
    while (!winner) {
        do {
            num_index = rand() % num_count;
            num = nums[num_index];
        } while (called[num - 1]); // make sure the number hasn't been called

        printf("Calling number: %d\n", num);
        called[num - 1] = 1;

        // mark number on card
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;
                }
            }
        }

        print_card(card);
        winner = check_bingo(card);
    }

    printf("Bingo! Game over.\n");
}

int main() {
    int nums[MAX_NUM];
    int num_count, i;

    // initialize array of numbers
    for (i = 0; i < MAX_NUM; i++) {
        nums[i] = i + 1;
    }
    num_count = MAX_NUM;

    simulate_game(nums, num_count);

    return 0;
}