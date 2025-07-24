//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

typedef struct {
    int row;
    int col;
} cell;

cell calls[MAX_NUM];
int nums[MAX_NUM];
int card[ROWS][COLS];

void init() {
    // initialize calls
    for (int i = 0; i < MAX_NUM; i++) {
        calls[i].row = i / 15;
        calls[i].col = i % 15;
    }

    // shuffle calls
    srand(time(NULL));
    for (int i = MAX_NUM - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        cell temp = calls[i];
        calls[i] = calls[j];
        calls[j] = temp;
    }

    // initialize nums
    for (int i = 0; i < MAX_NUM; i++) {
        nums[i] = i + 1;
    }

    // shuffle nums
    for (int i = MAX_NUM - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    // initialize card
    int nums_per_col = ROWS - 1;
    for (int c = 0; c < COLS; c++) {
        int nums_in_col[nums_per_col];
        for (int i = 0; i < nums_per_col; i++) {
            nums_in_col[i] = i + 1 + c * nums_per_col;
        }
        for (int i = nums_per_col; i > 0; i--) {
            int j = rand() % i;
            int temp = nums_in_col[i - 1];
            nums_in_col[i - 1] = nums_in_col[j];
            nums_in_col[j] = temp;
        }
        for (int r = 0; r < ROWS - 1; r++) {
            card[r][c] = nums_in_col[r];
        }
    }
    card[ROWS / 2][COLS / 2] = 0;
}

void print_card() {
    printf("╔════╦════╦════╦════╦════╗\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            printf("║");
            if (card[r][c] == 0) {
                printf(" XX ");
            } else {
                printf(" %2d ", card[r][c]);
            }
        }
        printf("║\n");
        if (r < ROWS - 1) {
            printf("╠════╬════╬════╬════╬════╣\n");
        }
    }
    printf("╚════╩════╩════╩════╩════╝\n");
}

void play() {
    int num_called = 0;
    while (num_called < MAX_NUM) {
        printf("Press ENTER to call a number...");
        getchar();
        int num = nums[num_called++];
        printf("Calling %d!\n", num);
        for (int i = 0; i < MAX_NUM; i++) {
            if (nums[i] == num) {
                int row = calls[i].row;
                int col = calls[i].col;
                card[row][col] = 0;
                break;
            }
        }
        print_card();
    }
}

int main() {
    printf("Welcome to Cyberpunk Bingo!\n");
    printf("Generating your card...\n");
    init();
    print_card();
    printf("Let's play!\n");
    play();
    printf("Thanks for playing Cyberpunk Bingo!\n");
    return 0;
}