//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3
#define MIN_NUM 1
#define MAX_NUM 9

void generate_card(int card[ROWS][COLS]);
void print_card(int card[ROWS][COLS]);
void generate_call(int *call);
int check_win(int card[ROWS][COLS], int num);

int main() {
    int card[ROWS][COLS];
    int call, count, row, col, check, winner;

    srand(time(0));

    printf("\tWelcome to C Bingo Simulator\n\n");

    generate_card(card);
    print_card(card);

    printf("\n\nPress ENTER to start the game...");
    getchar();

    for(count = 1; count <= 9; count++) {
        generate_call(&call);

        printf("\n\nCall: %d\n\n", call);

        for(row = 0; row < ROWS; row++) {
            for(col = 0; col < COLS; col++) {
                if(card[row][col] == call) {
                    card[row][col] = 0;
                }
            }
        }

        print_card(card);

        check = check_win(card, call);

        if(check) {
            printf("\n\nBINGO! You win!\n");
            winner = 1;
            break;
        }

        printf("\n\nPress ENTER for next call...");
        getchar();
    }

    if(!winner) {
        printf("\n\nGame over. No more calls. You Lose.\n");
    }

    return 0;
}

void generate_card(int card[ROWS][COLS]) {
    int nums[9], i, j, k;

    for(i = 0; i < 9; i++) {
        nums[i] = i + 1;
    }

    for(i = 0; i < 9; i++) {
        k = rand() % 9;

        j = nums[i];
        nums[i] = nums[k];
        nums[k] = j;
    }

    k = 0;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            card[i][j] = nums[k++];
        }
    }
}

void print_card(int card[ROWS][COLS]) {
    int i, j;

    printf("\n\tB I N G O\n");

    for(i = 0; i < ROWS; i++) {
        printf("\t");
        for(j = 0; j < COLS; j++) {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }
}

void generate_call(int *call) {
    *call = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
}

int check_win(int card[ROWS][COLS], int num) {
    int i, j, row, col, diag1 = 1, diag2 = 1;

    for(i = 0; i < ROWS; i++) {
        row = 1;
        col = 1;

        for(j = 0; j < COLS; j++) {
            if(card[i][j] != 0) {
                row = 0;
            }
            if(card[j][i] != 0) {
                col = 0;
            }
        }

        if(row || col) {
            return 1;
        }

        if(card[i][i] != 0) {
            diag1 = 0;
        }
        if(card[i][2 - i] != 0) {
            diag2 = 0;
        }
    }

    if(diag1 || diag2) {
        return 1;
    }

    return 0;
}