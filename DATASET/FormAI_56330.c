//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

void print_board(char board[SIZE][SIZE])
{
    int i, j;
    printf("   ");
    for (i = 0; i < SIZE; i++) {
        printf("%d  ", i+1);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d ", i+1);
        for (j = 0; j < SIZE; j++) {
            printf("|%c ", board[i][j]);
        }
        printf("|\n");
    }
}

bool in_range(int x, int y)
{
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE);
}

bool can_capture(char board[SIZE][SIZE], int x, int y, int dx, int dy)
{
    if (!in_range(x+2*dx, y+2*dy)) {
        return false;
    }
    if (board[x+dx][y+dy] == ' ' || board[x+2*dx][y+2*dy] != ' ') {
        return false;
    }
    if (board[x][y] == 'W' && board[x+dx][y+dy] != 'B' && board[x+dx][y+dy] != 'K') {
        return false;
    }
    if (board[x][y] == 'B' && board[x+dx][y+dy] != 'W' && board[x+dx][y+dy] != 'K') {
        return false;
    }
    return true;
}

bool can_move(char board[SIZE][SIZE], int x, int y, int dx, int dy)
{
    if (!in_range(x+dx, y+dy)) {
        return false;
    }
    if (board[x+dx][y+dy] != ' ') {
        return false;
    }
    return true;
}

bool can_piece_move(char board[SIZE][SIZE], int x, int y)
{
    if (board[x][y] == 'W' || board[x][y] == 'K') {
        if (can_move(board, x, y, -1, -1) || can_move(board, x, y, -1, 1)) {
            return true;
        }
        if (can_capture(board, x, y, -1, -1) || can_capture(board, x, y, -1, 1)) {
            return true;
        }
        if (board[x][y] == 'K' && (can_move(board, x, y, 1, -1) || can_move(board, x, y, 1, 1))) {
            return true;
        }
    }
    if (board[x][y] == 'B' || board[x][y] == 'K') {
        if (can_move(board, x, y, 1, -1) || can_move(board, x, y, 1, 1)) {
            return true;
        }
        if (can_capture(board, x, y, 1, -1) || can_capture(board, x, y, 1, 1)) {
            return true;
        }
        if (board[x][y] == 'K' && (can_move(board, x, y, -1, -1) || can_move(board, x, y, -1, 1))) {
            return true;
        }
    }
    return false;
}

void move_piece(char board[SIZE][SIZE], int x1, int y1, int dx, int dy)
{
    board[x1+dx][y1+dy] = board[x1][y1];
    board[x1][y1] = ' ';
}

void capture_piece(char board[SIZE][SIZE], int x1, int y1, int dx, int dy)
{
    board[x1+2*dx][y1+2*dy] = board[x1][y1];
    board[x1+dx][y1+dy] = ' ';
    board[x1][y1] = ' ';
}

void king_piece(char board[SIZE][SIZE], int x, int y)
{
    if (board[x][y] == 'W' && x == 0) {
        board[x][y] = 'K';
    }
    if (board[x][y] == 'B' && x == SIZE-1) {
        board[x][y] = 'K';
    }
}

bool check_end_game(char board[SIZE][SIZE])
{
    int i, j, white_count = 0, black_count = 0;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 'W' || board[i][j] == 'K') {
                white_count++;
            }
            else if (board[i][j] == 'B' || board[i][j] == 'K') {
                black_count++;
            }
        }
    }
    if (white_count == 0) {
        printf("Congratulations! Black wins the game!\n");
        return true;
    }
    if (black_count == 0) {
        printf("Congratulations! White wins the game!\n");
        return true;
    }
    return false;
}

int main()
{
    char board[SIZE][SIZE] = {
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
        {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'W', ' ', 'W', ' ', 'W', ' ', 'W', ' '},
        {' ', 'W', ' ', 'W', ' ', 'W', ' ', 'W'},
        {'W', ' ', 'W', ' ', 'W', ' ', 'W', ' '}
    };
    bool white_turn = true, end_game = false;

    printf("Welcome to Checkers Game!\n");
    printf("White pieces are represented by 'W' on the board.\n");
    printf("Black pieces are represented by 'B' on the board.\n");
    printf("Kings are represented by 'K' on the board.\n");
    printf("Empty squares are represented by ' ' on the board.\n");
    printf("White pieces move upwards. Black pieces move downwards.\n");

    while (!end_game) {
        print_board(board);

        if (white_turn) {
            printf("White's turn.\n");
        } else {
            printf("Black's turn.\n");
        }

        int x1, y1, x2, y2;
        printf("Enter the coordinates of the piece you want to move.\n");
        printf("x: ");
        scanf("%d", &x1);
        printf("y: ");
        scanf("%d", &y1);
        if (board[x1-1][y1-1] == ' ') {
            printf("Invalid selection. Please try again.\n");
            continue;
        }
        if (white_turn && (board[x1-1][y1-1] == 'B' || board[x1-1][y1-1] == 'K')) {
            printf("Invalid selection. Please try again.\n");            
            continue;
        }
        if (!white_turn && (board[x1-1][y1-1] == 'W' || board[x1-1][y1-1] == 'K')) {
            printf("Invalid selection. Please try again.\n");            
            continue;
        }

        printf("Enter the coordinates of the square you want to move to.\n");
        printf("x: ");
        scanf("%d", &x2);
        printf("y: ");
        scanf("%d", &y2);
        if (!in_range(x1-1, y1-1) || !in_range(x2-1, y2-1)) {
            printf("Invalid selection. Please try again.\n");
            continue;
        }

        int dx = x2-x1, dy = y2-y1;
        if (abs(dx) != abs(dy)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        if (abs(dx) == 1) {
            if (!can_move(board, x1-1, y1-1, dx, dy)) {
                printf("Invalid move. Please try again.\n");
                continue;
            }
            move_piece(board, x1-1, y1-1, dx, dy);
            king_piece(board, x2-1, y2-1);
        }
        else {
            if (!can_capture(board, x1-1, y1-1, dx/2, dy/2)) {
                printf("Invalid move. Please try again.\n");
                continue;
            }
            capture_piece(board, x1-1, y1-1, dx/2, dy/2);
            king_piece(board, x2-1, y2-1);
            if (can_capture(board, x2-1, y2-1, -1, -1) || can_capture(board, x2-1, y2-1, -1, 1) ||
                can_capture(board, x2-1, y2-1, 1, -1) || can_capture(board, x2-1, y2-1, 1, 1)) {
                printf("You can capture again!\n");
                continue;
            }
        }

        white_turn = !white_turn;
        end_game = check_end_game(board);
    }

    return 0;
}