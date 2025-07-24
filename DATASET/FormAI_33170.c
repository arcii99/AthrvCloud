//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

int card[ROWS][COLS];
int numbers_drawn[MAX_NUM];

void print_card() {
    printf("\nB   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == -1) {
                printf("X   ");
            } else {
                printf("%d   ", card[i][j]);
            }
        }
        printf("\n");
    }
}

void initialize_card() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == ROWS / 2 && j == COLS / 2) {
                card[i][j] = -1;
            } else {
                card[i][j] = (j + 1) + i * COLS;
            }
        }
    }
}

int draw_number() {
    int num = rand() % MAX_NUM + 1;
    while (numbers_drawn[num - 1]) {
        num = rand() % MAX_NUM + 1;
    }
    numbers_drawn[num - 1] = 1;
    return num;
}

int check_bingo() {
    int bingo = 0;
    int sum;

    for (int i = 0; i < ROWS; i++) {
        sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += card[i][j];
        }
        if (sum == -5) {
            bingo = 1;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        sum = 0;
        for (int j = 0; j < COLS; j++) {
            sum += card[j][i];
        }
        if (sum == -5) {
            bingo = 1;
        }
    }

    sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += card[i][i];
    }
    if (sum == -5) {
        bingo = 1;
    }

    sum = 0;
    for (int i = 0; i < ROWS; i++) {
        sum += card[i][COLS - i - 1];
    }
    if (sum == -5) {
        bingo = 1;
    }

    return bingo;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    initialize_card();
    print_card();

    int num_drawn = 0;
    while (num_drawn < MAX_NUM) {
        getchar(); // wait for user to press enter before drawing number
        printf("\nDrawing number %d...\n", num_drawn + 1);
        int num = draw_number();
        printf("The number drawn is: %d\n", num);
        int bingo = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = -1;
                    bingo = check_bingo();
                    break;
                }
            }
            if (bingo) {
                break;
            }
        }

        print_card();

        if (bingo) {
            printf("\nBINGO! You won!\n");
            break;
        }

        num_drawn++;
    }

    if (num_drawn == MAX_NUM) {
        printf("\nSorry, all numbers drawn. You lost :(\n");
    }

    return 0;
}