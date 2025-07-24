//FormAI DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{
    printf("\n   ");
    for(int j=0;j<BOARD_SIZE;j++){
      printf(" %c ",'a'+j);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" %d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0)
                printf("|_|");
            else
                printf("|%c|", board[i][j]);
        }
        printf(" %d\n", i + 1);
    }
    printf("   ");
    for(int j=0;j<BOARD_SIZE;j++){
      printf(" %c ",'a'+j);
    }
    printf("\n");
}

bool check_valid_move(int board[BOARD_SIZE][BOARD_SIZE], int x_start, int y_start, int x_end, int y_end, char player)
{
    if (board[x_end][y_end] != 0 || x_end>=BOARD_SIZE || y_end>=BOARD_SIZE)
        return false;
    if (player == 'r') {
        if (board[x_start][y_start] == 'r') {
            if (x_end - x_start == 1 && abs(y_end - y_start) == 1)
                return true;
            else if (x_end - x_start == 2 && abs(y_end - y_start) == 2 &&
                     board[(x_start + x_end) / 2][(y_start + y_end) / 2] == 'b')
                return true;
            else
                return false;
        } else if (board[x_start][y_start] == 'R') {
            if ((x_end - x_start == 1 || x_end - x_start == -1) && abs(y_end - y_start) == 1)
                return true;
            else if ((x_end - x_start == 2 || x_end - x_start == -2) && abs(y_end - y_start) == 2 &&
                     board[(x_start + x_end) / 2][(y_start + y_end) / 2] == 'b')
                return true;
            else
                return false;
        }
    }
    else if (player == 'b') {
        if (board[x_start][y_start] == 'b') {
            if (x_end - x_start == -1 && abs(y_end - y_start) == 1)
                return true;
            else if (x_end - x_start == -2 && abs(y_end - y_start) == 2 &&
                     board[(x_start + x_end) / 2][(y_start + y_end) / 2] == 'r')
                return true;
            else
                return false;
        } else if (board[x_start][y_start] == 'B') {
            if ((x_end - x_start == 1 || x_end - x_start == -1) && abs(y_end - y_start) == 1)
                return true;
            else if ((x_end - x_start == 2 || x_end - x_start == -2) && abs(y_end - y_start) == 2 &&
                     board[(x_start + x_end) / 2][(y_start + y_end) / 2] == 'r')
                return true;
            else
                return false;
        }
    }
    return false;
}

bool check_forced_move(int board[BOARD_SIZE][BOARD_SIZE], char player)
{
    bool has_forced_move = false;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == 'r' && (board[i][j] == 'r' || board[i][j] == 'R')) {
                if (i + 2 < BOARD_SIZE && j + 2 < BOARD_SIZE && board[i + 1][j + 1] == 'b' &&
                    board[i + 2][j + 2] == 0)
                    has_forced_move = true;
                if (i + 2 < BOARD_SIZE && j - 2 >= 0 && board[i + 1][j - 1] == 'b' && board[i + 2][j - 2] == 0)
                    has_forced_move = true;
                if (i - 2 >= 0 && j + 2 < BOARD_SIZE && board[i - 1][j + 1] == 'b' && board[i - 2][j + 2] == 0)
                    has_forced_move = true;
                if (i - 2 >= 0 && j - 2 >= 0 && board[i - 1][j - 1] == 'b' && board[i - 2][j - 2] == 0)
                    has_forced_move = true;
            } else if (player == 'b' && (board[i][j] == 'b' || board[i][j] == 'B')) {
                if (i + 2 < BOARD_SIZE && j + 2 < BOARD_SIZE && board[i + 1][j + 1] == 'r' &&
                    board[i + 2][j + 2] == 0)
                    has_forced_move = true;
                if (i + 2 < BOARD_SIZE && j - 2 >= 0 && board[i + 1][j - 1] == 'r' && board[i + 2][j - 2] == 0)
                    has_forced_move = true;
                if (i - 2 >= 0 && j + 2 < BOARD_SIZE && board[i - 1][j + 1] == 'r' && board[i - 2][j + 2] == 0)
                    has_forced_move = true;
                if (i - 2 >= 0 && j - 2 >= 0 && board[i - 1][j - 1] == 'r' && board[i - 2][j - 2] == 0)
                    has_forced_move = true;
            }
        }
    }
    return has_forced_move;
}

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    board[1][0] = 'r';
    board[3][0] = 'r';
    board[5][0] = 'r';
    board[7][0] = 'r';
    board[0][1] = 'r';
    board[2][1] = 'r';
    board[4][1] = 'r';
    board[6][1] = 'r';
    board[1][2] = 'r';
    board[3][2] = 'r';
    board[5][2] = 'r';
    board[7][2] = 'r';

    board[0][5] = 'b';
    board[2][5] = 'b';
    board[4][5] = 'b';
    board[6][5] = 'b';
    board[1][6] = 'b';
    board[3][6] = 'b';
    board[5][6] = 'b';
    board[7][6] = 'b';
    board[0][7] = 'b';
    board[2][7] = 'b';
    board[4][7] = 'b';
    board[6][7] = 'b';
    
    printf("Welcome to our Surreal Checkers Game!\n");
    printf("To play, enter the starting and ending coordinates of the piece you want to move, separated by a space.\n");
    printf("For example, to move the piece at a1 to b2, type 'a1 b2' without quotes and press Enter.\n");
    printf("'r' moves first!\n");
    while (true) {
        print_board(board);
        char player = 'r';
        while (true) {
            printf("%c's move: ", player);
            int x_start, y_start, x_end, y_end;
            scanf("%d %d %d %d", &x_start, &y_start, &x_end, &y_end);
            if (check_valid_move(board, x_start - 1, y_start - 1, x_end - 1, y_end - 1, player)) {
                board[x_end - 1][y_end - 1] = board[x_start - 1][y_start - 1];
                board[x_start - 1][y_start - 1] = 0;
                if (abs(x_end - x_start) == 2)
                    board[(x_start + x_end) / 2 - 1][(y_start + y_end) / 2 - 1] = 0;
                if (player == 'r' && x_end == BOARD_SIZE) {
                    board[x_end - 1][y_end - 1] = 'R';
                } else if (player == 'b' && x_end == 1) {
                    board[x_end - 1][y_end - 1] = 'B';
                }
                break;
            } else {
                printf("Invalid move.\n");
            }
        }
        if (player == 'r')
            player = 'b';
        else
            player = 'r';

        if (!check_forced_move(board, player)) {
            printf("Player %c has no moves left. Game over!\n", player);
            break;
        }
    }
    print_board(board);
    return 0;
}