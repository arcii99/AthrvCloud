//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void initialize_board(int board[][COL]) {
    int i, j, num = 1;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            board[i][j] = num;
            num++;
        }
    }
}

void shuffle_board(int board[][COL]) {
    srand(time(NULL));
    int i, j, temp;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            int rand_row = rand() % ROW;
            int rand_col = rand() % COL;
            temp = board[i][j];
            board[i][j] = board[rand_row][rand_col];
            board[rand_row][rand_col] = temp;
        }
    }
}

void print_board(int board[][COL], int called_numbers[], int counter) {
    int i, j;
    printf("B   I   N   G   O\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (called_numbers[counter-1] == board[i][j]) {
                printf(" X  ");
            } else {
                printf("%-3d ", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROW][COL];
    int called_numbers[25] = {0};
    int counter = 0;
    initialize_board(board);
    shuffle_board(board);
    printf("Let's start playing BINGO!\n");
    while (1) {
        printf("Press Enter to call a number.\n");
        getchar();
        int number = board[counter/5][counter%5];
        called_numbers[counter] = number;
        counter++;
        print_board(board, called_numbers, counter);
        if (counter >= 5 && (counter%5) == 0) {
            int row, col, diag1, diag2;
            row = col = diag1 = diag2 = 0;
            for (int i = 0; i < counter; i++) {
                if (i/5 == (counter-1)/5) {
                    row++;
                }
                if (i%5 == (counter-1)%5) {
                    col++;
                }
                if (i%6 == 0 && i < counter) {
                    diag1++;
                }
                if (i%4 == 0 && i > 0 && i < counter-1) {
                    diag2++;
                }
            }
            if (row == 5 || col == 5 || diag1 == 5 || diag2 == 5) {
                printf("BINGO! You win!\n");
                break;
            }
        }
    }
    return 0;
}