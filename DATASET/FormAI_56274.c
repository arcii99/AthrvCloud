//FormAI DATASET v1.0 Category: Memory Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
void shuffle_board(int board[ROWS][COLS]);
void reveal_card(int row, int col, int board[ROWS][COLS], int mask[ROWS][COLS]);
int is_match(int card1_row, int card1_col, int card2_row, int card2_col, int board[ROWS][COLS]);
int check_win(int mask[ROWS][COLS]);

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int mask[ROWS][COLS] = {0};
    int win = 0;
    int card1_row, card1_col, card2_row, card2_col;
    
    init_board(board);
    shuffle_board(board);
    
    while (!win) {
        print_board(mask);
        
        printf("Enter row and column of first card:\n");
        scanf("%d %d", &card1_row, &card1_col);
        
        reveal_card(card1_row, card1_col, board, mask);
        print_board(mask);
        
        printf("Enter row and column of second card:\n");
        scanf("%d %d", &card2_row, &card2_col);
        
        reveal_card(card2_row, card2_col, board, mask);
        print_board(mask);
        
        if (is_match(card1_row, card1_col, card2_row, card2_col, board)) {
            printf("MATCH!\n");
            mask[card1_row][card1_col] = 1;
            mask[card2_row][card2_col] = 1;
        } else {
            printf("No match, try again.\n");
            mask[card1_row][card1_col] = 0;
            mask[card2_row][card2_col] = 0;
        }
        
        win = check_win(mask);
    }
    
    printf("Congratulations, you won!\n");
    
    return 0;
}

void init_board(int board[ROWS][COLS]) {
    int count = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = count / 2;
            count++;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    printf("    ");
    for (int i = 0; i < COLS; i++) {
        printf("%d   ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d | ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%d | ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(int board[ROWS][COLS]) {
    int temp;
    int rand_row1, rand_col1, rand_row2, rand_col2;
    for (int i = 0; i < ROWS * COLS; i++) {
        rand_row1 = rand() % ROWS;
        rand_col1 = rand() % COLS;
        rand_row2 = rand() % ROWS;
        rand_col2 = rand() % COLS;
        temp = board[rand_row1][rand_col1];
        board[rand_row1][rand_col1] = board[rand_row2][rand_col2];
        board[rand_row2][rand_col2] = temp;
    }
}

void reveal_card(int row, int col, int board[ROWS][COLS], int mask[ROWS][COLS]) {
    mask[row][col] = 1;
}

int is_match(int card1_row, int card1_col, int card2_row, int card2_col, int board[ROWS][COLS]) {
    if (board[card1_row][card1_col] == board[card2_row][card2_col]) {
        return 1;
    } else {
        return 0;
    }
}

int check_win(int mask[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mask[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}