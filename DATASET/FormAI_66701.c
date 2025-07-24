//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY    ' '
#define PLAYER1  'O'
#define PLAYER2  'X'

// Function to print the board
void print_board(char board[][BOARD_SIZE])
{
    int row, col;
    printf("\n   ");
    for(col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col+1);
    }
    printf("\n");
    printf("  +");
    for(col = 0; col < BOARD_SIZE; col++) {
        printf("--");
    }
    printf("+\n");
    for(row = 0; row < BOARD_SIZE; row++) {
        printf("%c |", 'A'+row);
        for(col = 0; col < BOARD_SIZE; col++) {
            printf("%c|", board[row][col]);
        }
        printf(" %c\n", 'A'+row);
    }
    printf("  +");
    for(col = 0; col < BOARD_SIZE; col++) {
        printf("--");
    }
    printf("+\n");
    printf("   ");
    for(col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col+1);
    }
    printf("\n");
}

// Function to initialize the board
void init_board(char board[][BOARD_SIZE])
{
    int row, col;
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            if((row+col) % 2 == 0) {
                board[row][col] = EMPTY;
            } else {
                if(row < 3) board[row][col] = PLAYER1;
                else if(row > 4) board[row][col] = PLAYER2;
                else board[row][col] = EMPTY;
            }
        }
    }
}

// Function to check if a move is valid
int valid_move(char board[][BOARD_SIZE], int player, int r1, int c1, int r2, int c2)
{
    if(r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE || board[r2][c2] != EMPTY) {
        return 0;
    }
    int dr, dc, jump_r, jump_c;
    if(player == 1) {
        if(board[r1][c1] != PLAYER1 && board[r1][c1] != 'K') {
            return 0;
        }
        if(r2 >= r1) {
            return 0;
        }
        dr = r1 - r2;
    } else {
        if(board[r1][c1] != PLAYER2 && board[r1][c1] != 'K') {
            return 0;
        }
        if(r2 <= r1) {
            return 0;
        }
        dr = r2 - r1;
    }
    dc = abs(c2 - c1);
    if(dr == 1 && dc == 1) {
        return 1;
    } else if(dr == 2 && dc == 2) {
        jump_r = (r1 + r2) / 2;
        jump_c = (c1 + c2) / 2;
        if(board[jump_r][jump_c] == EMPTY || (player == 1 && board[jump_r][jump_c] == PLAYER2) || (player == 2 && board[jump_r][jump_c] == PLAYER1)) {
            return 0;
        }
        return 1;
    } else {
        return 0;
    }
}

// Recursive function to find all possible jumps
void jumps(char board[][BOARD_SIZE], int player, int r, int c, int depth, int *jumps_count)
{
    int i, j;
    if(depth > 1) {
        (*jumps_count)++;
        return;
    }
    int dr[] = { 1, -1, 1, -1};
    int dc[] = { 1, 1, -1, -1 };
    for(i = 0; i < 4; i++) {
        int r2 = r + 2*dr[i];
        int c2 = c + 2*dc[i];
        if(valid_move(board, player, r, c, r2, c2)) {
            board[r2-dr[i]][c2-dc[i]] = EMPTY;
            board[r2][c2] = player == 1 ? PLAYER1 : PLAYER2;
            jumps(board, player, r2, c2, depth+1, jumps_count);
            board[r2-dr[i]][c2-dc[i]] = player == 1 ? PLAYER2 : PLAYER1;
            board[r2][c2] = EMPTY;
        }
    }
}

// Function to check if a player can jump
int can_jump(char board[][BOARD_SIZE], int player)
{
    int row, col, jumps_count;
    for(row = 0; row < BOARD_SIZE; row++) {
        for(col = 0; col < BOARD_SIZE; col++) {
            if(player == 1 && (board[row][col] == PLAYER1 || board[row][col] == 'K')) {
                jumps_count = 0;
                jumps(board, player, row, col, 0, &jumps_count);
                if(jumps_count > 0) {
                    return 1;
                }
            } else if(player == 2 && (board[row][col] == PLAYER2 || board[row][col] == 'K')) {
                jumps_count = 0;
                jumps(board, player, row, col, 0, &jumps_count);
                if(jumps_count > 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Function to make a move
int make_move(char board[][BOARD_SIZE], int player, int r1, int c1, int r2, int c2)
{
    if(valid_move(board, player, r1, c1, r2, c2)) {
        board[r2][c2] = board[r1][c1];
        board[r1][c1] = EMPTY;
        if(player == 1 && r2 == 0 && board[r2][c2] == PLAYER1) {
            board[r2][c2] = 'K';
        } else if(player == 2 && r2 == BOARD_SIZE-1 && board[r2][c2] == PLAYER2) {
            board[r2][c2] = 'K';
        }
        if(abs(r2-r1) == 2) {
            board[(r1+r2)/2][(c1+c2)/2] = EMPTY;
            if(!can_jump(board, player)) {
                return 0;
            }
        }
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    char board[BOARD_SIZE][BOARD_SIZE];
    int player = 1;
    init_board(board);
    print_board(board);
    while(1) {
        int r1, c1, r2, c2;
        printf("Player %d enter move (row1 col1 row2 col2): ", player);
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--;
        if(make_move(board, player, r1, c1, r2, c2)) {
            print_board(board);
            if(player == 1 && board[r2][c2] == 'K') {
                printf("Player 1 wins!\n");
                break;
            } else if(player == 2 && board[r2][c2] == 'K') {
                printf("Player 2 wins!\n");
                break;
            }
            if(!can_jump(board, player)) {
                player = 3 - player;
            }
        } else {
            printf("Invalid move, try again\n");
        }
    }
    return 0;
}