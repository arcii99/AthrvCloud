//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 6

void generate_board(int board[][COLS], int size) {
    int nums[size * 2];
    for(int i = 0; i < size * 2; i++) {
        nums[i] = i / 2;
    }
  
    srand(time(NULL));
    for(int i = 0; i < size * 2; i++) {
        int r = rand() % (size * 2);
        int temp = nums[i];
        nums[i] = nums[r];
        nums[r] = temp;
    }

    int idx = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = nums[idx];
            idx++;
        }
    }
}

void print_board(int board[][COLS]) {
    printf("    1 2 3 4 5 6\n");
    printf("  --------------\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d |", i + 1);
        for(int j = 0; j < COLS; j++) {
            if(!board[i][j]) {
                printf(" *");
            } else {
                printf(" %d", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int size = ROWS * COLS / 2;
    int board[ROWS][COLS] = {0};
    generate_board(board, size);
    int gameboard[ROWS][COLS] = {0};
    print_board(board);
    int match_counter = 0;
    while(match_counter < size) {
        int r1, c1, r2, c2;
        printf("Enter the first row and column numbers: ");
        scanf("%d%d", &r1, &c1);
        while(r1 < 1 || r1 > ROWS || c1 < 1 || c1 > COLS || gameboard[r1 - 1][c1 - 1]) {
            printf("Invalid input. Enter the first row and column numbers: ");
            scanf("%d%d", &r1, &c1);
        }
        gameboard[r1 - 1][c1 - 1] = board[r1 - 1][c1 - 1];
        print_board(gameboard);
        printf("Enter the second row and column numbers: ");
        scanf("%d%d", &r2, &c2);
        while(r2 < 1 || r2 > ROWS || c2 < 1 || c2 > COLS || gameboard[r2 - 1][c2 - 1]) {
            printf("Invalid input. Enter the second row and column numbers: ");
            scanf("%d%d", &r2, &c2);
        }
        gameboard[r2 - 1][c2 - 1] = board[r2 - 1][c2 - 1];
        print_board(gameboard);
        if(board[r1 - 1][c1 - 1] == board[r2 - 1][c2 - 1]) {
            printf("Match found!\n");
            match_counter++;
        } else {
            printf("No match.\n");
            gameboard[r1 - 1][c1 - 1] = 0;
            gameboard[r2 - 1][c2 - 1] = 0;
        }
    }
    printf("Congratulations! You win!\n");
    return 0;
}