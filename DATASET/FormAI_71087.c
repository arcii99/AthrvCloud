//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

void generate_bingo_card(int card[ROWS][COLS], int max_num);
void display_bingo_card(int card[ROWS][COLS]);
int check_for_bingo(int card[ROWS][COLS]);
void mark_number(int card[ROWS][COLS], int number);

int main(){
    int card[ROWS][COLS], number, bingo_flag = 0;

    srand(time(NULL)); // seed the random number generator

    generate_bingo_card(card, MAX_NUM);
    display_bingo_card(card);

    printf("\n\nLet's start calling the numbers!\n");

    while(1){
        number = rand() % MAX_NUM + 1;
        printf("\n\nThe next number is: %d\n", number);
        mark_number(card, number);
        display_bingo_card(card);
        bingo_flag = check_for_bingo(card);

        if (bingo_flag){
            printf("\n\nBINGO!!!\n");
            break;
        }
    }

    return 0;
}

void generate_bingo_card(int card[ROWS][COLS], int max_num){
    int numbers_drawn[max_num], r, c;

    for (int i = 0; i < max_num; i++){
        numbers_drawn[i] = 0;
    }

    for (r = 0; r < ROWS; r++){
        for (c = 0; c < COLS; c++){
            while(1){
                int num = rand() % max_num + 1;
                if (numbers_drawn[num-1] == 0){
                    numbers_drawn[num-1] = 1;
                    card[r][c] = num;
                    break;
                }
            }
        }
    }

    card[2][2] = -1; // mark the center as FREE
}

void display_bingo_card(int card[ROWS][COLS]){
    printf("\n\nCurrent Bingo Card\n\n");
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            if (card[r][c] >= 0){
                printf("%3d ", card[r][c]);
            }
            else{
                printf("  X ");
            }
        }
        printf("\n");
    }
}

int check_for_bingo(int card[ROWS][COLS]){
    int row_count, col_count, diag_count, reverse_diag_count;

    // Check rows for bingo
    for (int r = 0; r < ROWS; r++){
        row_count = 0;
        for (int c = 0; c < COLS; c++){
            if (card[r][c] < 0 || card[r][c] >= MAX_NUM) continue;
            if (card[r][c] == 0) row_count++;
            else break;
        }
        if (row_count == COLS) return 1;
    }

    // Check columns for bingo
    for (int c = 0; c < COLS; c++){
        col_count = 0;
        for (int r = 0; r < ROWS; r++){
            if (card[r][c] < 0 || card[r][c] >= MAX_NUM) continue;
            if (card[r][c] == 0) col_count++;
            else break;
        }
        if (col_count == ROWS) return 1;
    }

    // Check diagonal for bingo (left to right)
    diag_count = 0;
    for (int i = 0; i < ROWS; i++){
        if (card[i][i] < 0 || card[i][i] >= MAX_NUM) continue;
        if (card[i][i] == 0) diag_count++;
        else break;
    }
    if (diag_count == ROWS) return 1;

    // Check diagonal for bingo (right to left)
    reverse_diag_count = 0;
    for (int i = 0; i < ROWS; i++){
        if (card[i][COLS-i-1] < 0 || card[i][COLS-i-1] >= MAX_NUM) continue;
        if (card[i][COLS-i-1] == 0) reverse_diag_count++;
        else break;
    }
    if (reverse_diag_count == ROWS) return 1;

    return 0;
}

void mark_number(int card[ROWS][COLS], int number){
    for (int r = 0; r < ROWS; r++){
        for (int c = 0; c < COLS; c++){
            if (card[r][c] == number){
                card[r][c] = 0;
                return;
            }
        }
    }
}