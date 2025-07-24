//FormAI DATASET v1.0 Category: Table Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void display_board(char board[ROWS][COLS]) {
    printf("\n");
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    
    printf("-----------------------------\n");
    printf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    printf("-----------------------------\n");
}

void initialize_board(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

int play_game(char board[ROWS][COLS], char player) {
    int column = -1;
    
    do {
        printf("%c's turn:\n", player);
        scanf("%d", &column);
    } while (column < 1 || column > 7);
    
    column--;
    
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][column] == '-') {
            board[i][column] = player;
            return i;
        }
    }
    
    return -1;
}

int check_win(char board[ROWS][COLS], int row, int col, char player) {
    int i, j;
    int count = 0;
    
    // Check horizontally
    for (i = col - 3; i <= col; i++) {
        if (i < 0 || i + 3 >= COLS) {
            continue;
        }
        
        count = 0;
        for (j = i; j <= i + 3; j++) {
            if (board[row][j] == player) {
                count++;
            }
        }
        
        if (count == 4) {
            return 1;
        }
    }
    
    // Check vertically
    if (row + 3 < ROWS) {
        count = 0;
        for (i = row; i <= row + 3; i++) {
            if (board[i][col] == player) {
                count++;
            }
        }
        
        if (count == 4) {
            return 1;
        }
    }
    
    // Check diagonally down-right
    for (i = col - 3; i <= col; i++) {
        if (i < 0 || i + 3 >= COLS || row + 3 >= ROWS) {
            continue;
        }
        
        count = 0;
        for (j = 0; j <= 3; j++) {
            if (board[row + j][i + j] == player) {
                count++;
            }
        }
        
        if (count == 4) {
            return 1;
        }
    }
    
    // Check diagonally down-left
    for (i = col + 3; i >= col; i--) {
        if (i + 3 >= COLS || row + 3 >= ROWS) {
            continue;
        }
        
        count = 0;
        for (j = 0; j <= 3; j++) {
            if (board[row + j][i - j] == player) {
                count++;
            }
        }
        
        if (count == 4) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    char board[ROWS][COLS];
    char players[2] = { 'X', 'O' };
    int player_index = 0;
    int row, col;
    int winner = 0;
    
    initialize_board(board);
    display_board(board);
    
    while (!winner) {
        row = play_game(board, players[player_index]);
        col = player_index + 1;
        col %= 2;
        display_board(board);
        
        winner = check_win(board, row, col, players[player_index]);
        
        if (winner) {
            printf("%c wins!", players[player_index]);
            break;
        }
        
        player_index++;
        player_index %= 2;
    }
    
    return 0;
}