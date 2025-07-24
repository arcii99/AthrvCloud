//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

void print_board(int board[ROWS][COLS], int num_drawn) {
    printf("-----------------------\n");
    printf("| B | I | N | G | O |\n");
    printf("-----------------------\n");

    for(int i=0; i<ROWS; i++) {
        printf("|");
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                printf("   |");
            } else if(board[i][j] == num_drawn) {
                printf(" * |");
            } else {
                printf(" %2d|", board[i][j]);
            }
        }
        printf("\n");
        printf("-----------------------\n");
    }
}

void shuffle_array(int *arr, int n) {
    srand(time(NULL));
    for(int i=n-1; i>0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int board[ROWS][COLS] = {0};
    int nums[MAX_NUM] = {0};
    int num_drawn = 0;

    // initialize array with numbers 1-25
    for(int i=0; i<MAX_NUM; i++) {
        nums[i] = i+1;
    }

    shuffle_array(nums, MAX_NUM); // shuffle the array

    // set the center value to 0
    board[ROWS/2][COLS/2] = 0;

    while(num_drawn < MAX_NUM) {
        printf("Press Enter to draw next number: ");
        char c = getchar();
        if(c == '\n') {
            printf("Drawing Number...\n\n");
            printf("The next number is: %d\n", nums[num_drawn]);
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(board[i][j] == nums[num_drawn]) {
                        board[i][j] = 0; // mark drawn number as 0
                    }
                }
            }
            board[ROWS/2][COLS/2] = 0; // center value is always 0
            print_board(board, nums[num_drawn]);
            num_drawn++;
        }
    }

    printf("All numbers have been drawn.\n");

    return 0;
}