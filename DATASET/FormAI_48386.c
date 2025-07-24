//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define BOMB_COUNT 10

int random_num() {
    return rand() % 10;
}

void print_board(char board[][COLS]) {
    printf(" ");
    for (int i = 0; i < COLS; i++) {
        printf(" %d", i+1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c|", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            printf(" %c", board[i][j]);
        }
        printf(" |\n");
    }
}

int flag_count(char board[][COLS]) {
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'F') {
                count++;
            }
        }
    }
    return count;
}

int main() {
    char board[ROWS][COLS];
    int bomb_row[BOMB_COUNT], bomb_col[BOMB_COUNT];
    int mines_left = BOMB_COUNT;
    char row, col;
    int row_num, col_num;
    int flags_placed = 0;
    int game_over = 0;

    srand(time(NULL));

    // set all cells to ' '
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    // randomly place bombs
    for (int i = 0; i < BOMB_COUNT; i++) {
        int r = random_num();
        int c = random_num();
        if (board[r][c] == '*') {
            i--;
        } else {
            board[r][c] = '*';
            bomb_row[i] = r;
            bomb_col[i] = c;
        }
    }

    printf("Welcome to Minesweeper!\n");
    print_board(board);
    while (!game_over) {
        printf("Mines left: %d\n", mines_left);
        printf("Flags placed: %d\n", flags_placed);
        printf("Please enter row letter and col number (example: A1): ");
        scanf(" %c%d", &row, &col_num);
        row_num = row - 'A';
        col_num--;
        if (row_num < 0 || row_num >= ROWS || col_num < 0 || col_num >= COLS) {
            printf("Invalid input, please try again.\n");
            continue;
        }
        if (board[row_num][col_num] == '*') {
            printf("Game over!\n");
            board[row_num][col_num] = 'X';
            print_board(board);
            game_over = 1;
            continue;
        }
        if (board[row_num][col_num] != ' ' && board[row_num][col_num] != 'F') {
            printf("Cell already revealed, please try again.\n");
            continue;
        }
        if (row_num == bomb_row[0] && col_num == bomb_col[0]) {
            board[row_num][col_num] = '1';
        } else if (row_num == bomb_row[1] && col_num == bomb_col[1]) {
            board[row_num][col_num] = '2';
        } else if (row_num == bomb_row[2] && col_num == bomb_col[2]) {
            board[row_num][col_num] = '3';
        } else if (row_num == bomb_row[3] && col_num == bomb_col[3]) {
            board[row_num][col_num] = '4';
        } else if (row_num == bomb_row[4] && col_num == bomb_col[4]) {
            board[row_num][col_num] = '5';
        } else if (row_num == bomb_row[5] && col_num == bomb_col[5]) {
            board[row_num][col_num] = '6';
        } else if (row_num == bomb_row[6] && col_num == bomb_col[6]) {
            board[row_num][col_num] = '7';
        } else if (row_num == bomb_row[7] && col_num == bomb_col[7]) {
            board[row_num][col_num] = '8';
        } else {
            int count = 0;
            if (row_num > 0 && col_num > 0 && board[row_num-1][col_num-1] == '*') {
                count++;
            }
            if (row_num > 0 && board[row_num-1][col_num] == '*') {
                count++;
            }
            if (row_num > 0 && col_num < COLS-1 && board[row_num-1][col_num+1] == '*') {
                count++;
            }
            if (col_num > 0 && board[row_num][col_num-1] == '*') {
                count++;
            }
            if (col_num < COLS-1 && board[row_num][col_num+1] == '*') {
                count++;
            }
            if (row_num < ROWS-1 && col_num > 0 && board[row_num+1][col_num-1] == '*') {
                count++;
            }
            if (row_num < ROWS-1 && board[row_num+1][col_num] == '*') {
                count++;
            }
            if (row_num < ROWS-1 && col_num < COLS-1 && board[row_num+1][col_num+1] == '*') {
                count++;
            }
            board[row_num][col_num] = '0' + count;
        }
        print_board(board);
        if (flag_count(board) == BOMB_COUNT) {
            printf("You win!\n");
            game_over = 1;
        }
    }
    return 0;
}