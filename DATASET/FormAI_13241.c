//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

void print_board(int board[ROWS][COLS], int marked[ROWS][COLS]) {
    printf("  B  I  N  G  O\n\n");
    for(int row=0; row<ROWS; row++) {
        for(int col=0; col<COLS; col++) {
            if(marked[row][col]) {
                printf("  * ");
            } else {
                printf("%3d ", board[row][col]);
            }
        }
        printf("\n");
    }
}

int check_bingo(int marked[ROWS][COLS]) {
    for(int row=0; row<ROWS; row++) {
        int count = 0;
        for(int col=0; col<COLS; col++) {
            if(marked[row][col]) {
                count++;
            }
            if(count == ROWS) {
                return 1;
            }
        }
    }
    for(int col=0; col<COLS; col++) {
        int count = 0;
        for(int row=0; row<ROWS; row++) {
            if(marked[row][col]) {
                count++;
            }
            if(count == ROWS) {
                return 1;
            }
        }
    }
    int count = 0;
    for(int diag=0; diag<ROWS; diag++) {
        if(marked[diag][diag]) {
            count++;
        }
        if(count == ROWS) {
            return 1;
        }
    }
    count = 0;
    for(int diag=0; diag<ROWS; diag++) {
        if(marked[ROWS-1-diag][diag]) {
            count++;
        }
        if(count == ROWS) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    int board[ROWS][COLS] = {0};
    int used_numbers[ROWS * COLS] = {0};
    int marked[ROWS][COLS] = {0};
    for(int row=0; row<ROWS; row++) {
        for(int col=0; col<COLS; col++) {
            int valid_number = 0;
            while(!valid_number) {
                int number = rand() % (ROWS * COLS) + 1;
                valid_number = 1;
                for(int i=0; i<ROWS * COLS; i++) {
                    if(used_numbers[i] == number) {
                        valid_number = 0;
                        break;
                    }
                }
                if(valid_number) {
                    board[row][col] = number;
                    used_numbers[row * COLS + col] = number;
                }
            }
        }
    }
    print_board(board, marked);
    printf("\nLet's play Bingo!\n\n");
    int game_over = 0;
    while(!game_over) {
        int number = rand() % (ROWS * COLS) + 1;
        printf("The next number is: %d\n", number);
        for(int row=0; row<ROWS; row++) {
            for(int col=0; col<COLS; col++) {
                if(board[row][col] == number) {
                    printf("Bingo! %d found at row %d, column %d\n\n", number, row+1, col+1);
                    marked[row][col] = 1;
                    game_over = check_bingo(marked);
                    if(game_over) {
                        printf("Congratulations, you won!\n");
                        print_board(board, marked);
                        return 0;
                    } else {
                        print_board(board, marked);
                    }
                }
            }
        }
    }
    return 0;
}