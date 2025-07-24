//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 25

void fill_card(int card[ROWS][COLS]) {
    int nums[MAX_NUM], rand_num, current_row, current_col;
    
    // Generate sorted array of possible numbers
    for (int i=1; i<=MAX_NUM; i++) {
        nums[i-1] = i;
    }
    
    // Shuffle array of possible numbers
    srand(time(0));
    for (int i=0; i<MAX_NUM; i++) {
        int rand_idx = rand() % MAX_NUM;
        int temp = nums[i];
        nums[i] = nums[rand_idx];
        nums[rand_idx] = temp;
    }
    
    // Fill card with shuffled numbers
    current_row = 0;
    current_col = 0;
    for (int i=0; i<MAX_NUM; i++) {
        card[current_row][current_col] = nums[i];
        
        current_col++;
        if (current_col == COLS) {
            current_row++;
            current_col = 0;
        }
    }
}

void print_card(int card[ROWS][COLS]) {
    printf("B  I  N  G  O\n");
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

void simulate_game(int card[ROWS][COLS]) {
    int count = 0, num;
    while (count < MAX_NUM) {
        num = rand() % MAX_NUM + 1;
        printf("The current number is %d.\n", num);
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;
                    count++;
                }
            }
        }
        print_card(card);
        printf("\n");
    }
    printf("BINGO! You win!\n");
}

int main() {
    int card[ROWS][COLS];
    
    fill_card(card);
    print_card(card);
    printf("\n");
    
    simulate_game(card);
    
    return 0;
}