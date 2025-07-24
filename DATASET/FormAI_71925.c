//FormAI DATASET v1.0 Category: Game of Life ; Style: Claude Shannon
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 50
#define COLS 50

char board[ROWS][COLS];
char temp_board[ROWS][COLS];
int generation = 1;

void initialize_board() {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(rand() % 2 == 0)
                board[i][j] = '.';
            else
                board[i][j] = '*';
        }
    }
}

int get_neighbors(int row, int col) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i == row && j == col)
                continue;
            if(i < 0 || i >= ROWS)
                continue;
            if(j < 0 || j >= COLS)
                continue;
            if(board[i][j] == '*')
                count++;
        }
    }
    return count;
}

void update_board() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int count = get_neighbors(i, j);
            if(board[i][j] == '*') {
                if(count < 2)
                    temp_board[i][j] = '.';
                else if(count == 2 || count == 3)
                    temp_board[i][j] = '*';
                else if(count > 3)
                    temp_board[i][j] = '.';
            }
            else {
                if(count == 3)
                    temp_board[i][j] = '*';
                else
                    temp_board[i][j] = '.';
            }
        }
    }
    memcpy(board, temp_board, sizeof(board));
    generation++;
}

void display_board() {
    printf("Generation: %d\n", generation);
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++)
            printf("%c", board[i][j]);
        printf("\n");
    }
}

int main() {
    initialize_board();
    while(1) {
        system("clear");
        display_board();
        update_board();
        getchar();
    }
    return 0;
}