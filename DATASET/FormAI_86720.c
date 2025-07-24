//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void print_card(int(*card)[COLS], int(*mask)[COLS]) {
    printf("B\tI\tN\tG\tO\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mask[i][j])
                printf("%d*\t", card[i][j]);
            else
                printf("%d\t", card[i][j]);
        }
        printf("\n");
    }
}

int check_card(int(*card)[COLS], int(*mask)[COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                mask[i][j] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int check_bingo(int(*mask)[COLS]) {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        int sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += mask[i][j];
        }
        if (sum == COLS)
            return 1;
    }
    // check columns
    for (int j = 0; j < COLS; j++) {
        int sum = 0;
        for (int i = 0; i < ROWS; i++) {
            sum += mask[i][j];
        }
        if (sum == ROWS)
            return 1;
    }
    // check diagonals
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < ROWS; i++) {
        sum1 += mask[i][i];
        sum2 += mask[i][COLS - i - 1];
    }
    if (sum1 == ROWS || sum2 == ROWS)
        return 1;
    // no bingo
    return 0;
}

int main() {
    int card[ROWS][COLS] = { {1, 10, 20, 30, 40},
                             {2, 11, 21, 31, 41},
                             {3, 12, 22, 32, 42},
                             {4, 13, 23, 33, 43},
                             {5, 14, 24, 34, 44} };
    int mask[ROWS][COLS] = { 0 };

    srand(time(NULL));

    printf("Welcome to Bingo Simulator!\n");
    printf("You have a Bingo card with numbers ranging from 1-45.\n");
    printf("B\tI\tN\tG\tO\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }

    int num_of_calls = 0;
    while (!check_bingo(mask)) {
        int num = rand() % 45 + 1;
        printf("The next number called is: %d\n", num);
        if (check_card(card, mask, num)) {
            printf("You have the number %d on your card!\n", num);
            print_card(card, mask);
        }
        num_of_calls++;
    }

    printf("Bingo! It took %d calls to win.\n", num_of_calls);

    return 0;
}