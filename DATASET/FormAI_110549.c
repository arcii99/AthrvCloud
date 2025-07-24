//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int card[ROWS][COLS];

void generate_card() {
    int nums[25] = {0};
    int count = 0;

    // generate 25 unique random numbers
    srand(time(NULL));
    while (count < 25) {
        int num = (rand() % 75) + 1;
        int unique = 1;
        for (int i = 0; i < count; i++) {
            if (num == nums[i]) {
                unique = 0;
                break;
            }
        }

        if (unique) {
            nums[count] = num;
            count++;
        }
    }

    // fill in the card
    count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS/2 && j == COLS/2) {
                card[i][j] = 0;
            } else {
                card[i][j] = nums[count];
                count++;
            }
        }
    }
}

void print_card() {
    printf("+----+----+----+----+----+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("|");
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf(" XX |");
            } else {
                printf(" %2d |", card[i][j]);
            }
        }
        printf("\n+----+----+----+----+----+\n");
    }
}

int check_win() {
    // check each row
    for (int i = 0; i < ROWS; i++) {
        int bingo = 1;
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] != 0) {
                bingo = 0;
                break;
            }
        }

        if (bingo) {
            return 1;
        }
    }

    // check each column
    for (int j = 0; j < COLS; j++) {
        int bingo = 1;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][j] != 0) {
                bingo = 0;
                break;
            }
        }

        if (bingo) {
            return 1;
        }
    }

    // check diagonals
    int bingo1 = 1;
    int bingo2 = 1;
    for (int i = 0; i < ROWS; i++) {
        if (card[i][i] != 0) {
            bingo1 = 0;
        }

        if (card[i][COLS-i-1] != 0) {
            bingo2 = 0;
        }
    }
    if (bingo1 || bingo2) {
        return 1;
    }

    // no bingo
    return 0;
}

int main() {
    printf("Welcome to Bingo Simulator!\n");

    generate_card();
    print_card();

    int round = 1;
    while (1) {
        printf("\n");
        printf("Round %d: ", round);
        int num = (rand() % 75) + 1;
        printf("%d\n", num);

        // mark the number on the card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;
                }
            }
        }

        print_card();
        int bingo = check_win();
        if (bingo) {
            printf("\nBINGO! You win!\n");
            break;
        }

        usleep(500000);
        round++;
    }

    return 0;
}