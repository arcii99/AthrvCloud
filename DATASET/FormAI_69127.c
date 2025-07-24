//FormAI DATASET v1.0 Category: Table Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 2048

void print_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

int get_random_number(int min, int max) {
    return min + rand() % (max-min+1);
}

void add_random_value(int board[ROWS][COLS]) {
    int i, j;
    do {
        i = get_random_number(0, ROWS-1);
        j = get_random_number(0, COLS-1);
    } while(board[i][j] != 0);
    
    int value = get_random_number(1, 2) * 2;
    board[i][j] = value;
}

void initialize_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = 0;
        }
    }
    add_random_value(board);
    add_random_value(board);
}

int is_board_full(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int move_left(int board[ROWS][COLS]) {
    int moved = 0;
    for(int i=0; i<ROWS; i++) {
        int new_row[COLS] = {0};
        int k = 0;
        int prev = 0;
        for(int j=0; j<COLS; j++) {
            int value = board[i][j];
            if(value != 0) {
                if(value == prev) {
                    new_row[k-1] *= 2;
                    moved = 1;
                    prev = 0;
                } else {
                    new_row[k++] = value;
                    prev = value;
                }
            }
        }
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_row[j];
        }
    }
    return moved;
}

int move_right(int board[ROWS][COLS]) {
    int moved = 0;
    for(int i=0; i<ROWS; i++) {
        int new_row[COLS] = {0};
        int k = COLS-1;
        int prev = 0;
        for(int j=COLS-1; j>=0; j--) {
            int value = board[i][j];
            if(value != 0) {
                if(value == prev) {
                    new_row[k+1] *= 2;
                    moved = 1;
                    prev = 0;
                } else {
                    new_row[k--] = value;
                    prev = value;
                }
            }
        }
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_row[j];
        }
    }
    return moved;
}

int move_up(int board[ROWS][COLS]) {
    int moved = 0;
    for(int j=0; j<COLS; j++) {
        int new_col[ROWS] = {0};
        int k = 0;
        int prev = 0;
        for(int i=0; i<ROWS; i++) {
            int value = board[i][j];
            if(value != 0) {
                if(value == prev) {
                    new_col[k-1] *= 2;
                    moved = 1;
                    prev = 0;
                } else {
                    new_col[k++] = value;
                    prev = value;
                }
            }
        }
        for(int i=0; i<ROWS; i++) {
            board[i][j] = new_col[i];
        }
    }
    return moved;
}

int move_down(int board[ROWS][COLS]) {
    int moved = 0;
    for(int j=0; j<COLS; j++) {
        int new_col[ROWS] = {0};
        int k = ROWS-1;
        int prev = 0;
        for(int i=ROWS-1; i>=0; i--) {
            int value = board[i][j];
            if(value != 0) {
                if(value == prev) {
                    new_col[k+1] *= 2;
                    moved = 1;
                    prev = 0;
                } else {
                    new_col[k--] = value;
                    prev = value;
                }
            }
        }
        for(int i=0; i<ROWS; i++) {
            board[i][j] = new_col[i];
        }
    }
    return moved;
}

void play_game() {
    int game_board[ROWS][COLS];
    initialize_board(game_board);
    while(1) {
        printf("\n");
        print_board(game_board);
        if(is_board_full(game_board)) {
            printf("GAME OVER!\n");
            return;
        }
        int moved = 0;
        printf("Enter Move (L/R/U/D): ");
        char move;
        scanf(" %c", &move);
        switch(move) {
            case 'L': moved = move_left(game_board); break;
            case 'R': moved = move_right(game_board); break;
            case 'U': moved = move_up(game_board); break;
            case 'D': moved = move_down(game_board); break;
            default: printf("Wrong Move! Try Again.\n"); break;
        }
        if(moved) {
            add_random_value(game_board);
        }
        if(game_board[0][0] == MAX_VALUE) {
            printf("CONGRATULATIONS! YOU WIN!\n");
            return;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    play_game();
    return 0;
}