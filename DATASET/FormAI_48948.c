//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>

char board[8][8] = { { ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },
                     { 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ' },
                     { ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },
                     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
                     { 'w', ' ', 'w', ' ', 'w', ' ', 'w', ' ' },
                     { ' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w' },
                     { 'w', ' ', 'w', ' ', 'w', ' ', 'w', ' ' } };

void display_board() {
    int row, col;
    printf("\n");
    printf("    1  2  3  4  5  6  7  8\n");
    for(row = 0; row < 8; row++) {
        printf("%d ", row + 1);
        for(col = 0; col < 8; col++) {
            printf("[%c]", board[row][col]);
        }
        printf("\n");
    }
}

int move_piece(int row, int col, int drow, int dcol) {
    if((row + drow) < 0 || (row + drow) > 7 || (col + dcol) < 0 || (col + dcol) > 7) {
        printf("Invalid move. Please enter another move.\n");
        return 0;
    }
    if(board[row + drow][col + dcol] == ' ') {
        board[row + drow][col + dcol] = board[row][col];
        board[row][col] = ' ';
        return 1;
    }
    printf("Invalid move. Please enter another move.\n");
    return 0;
}

int check_endgame() {
    int row, col;
    int black_pieces = 0;
    int white_pieces = 0;
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            if(board[row][col] == 'b' || board[row][col] == 'B') {
                black_pieces += 1;
            }
            else if(board[row][col] == 'w' || board[row][col] == 'W') {
                white_pieces += 1;
            }
        }
    }
    if(black_pieces == 0 || white_pieces == 0) {
        return 1;
    }
    return 0;
}

int main() {
    int row, col, drow, dcol;
    int game_end = 0;
    printf("Welcome to Checkers!\n");
    while(!game_end) {
        display_board();
        printf("\n");
        printf("Player 1 (black), enter your move. (row, col, drow, dcol): ");
        scanf("%d %d %d %d", &row, &col, &drow, &dcol);
        if(board[row - 1][col - 1] == 'b' || board[row - 1][col - 1] == 'B') {
            if(drow == 1 && (dcol == 1 || dcol == -1)) {
                if(board[row + drow - 1][col + dcol - 1] == 'w' || board[row + drow - 1][col + dcol - 1] == 'W') {
                    board[row + drow - 1][col + dcol - 1] = ' ';
                }
                move_piece(row - 1, col - 1, drow, dcol);
            }
            else if(drow == 2 && (dcol == 2 || dcol == -2)) {
                if(board[row + drow - 1][col + dcol - 1] == 'w' || board[row + drow - 1][col + dcol - 1] == 'W') {
                    board[row + drow - 1][col + dcol - 1] = ' ';
                    move_piece(row - 1, col - 1, drow, dcol);
                }
                else {
                    printf("Invalid move. Please enter another move.\n");
                }
            }
            else {
                printf("Invalid move. Please enter another move.\n");
            }
        }
        else if(board[row - 1][col - 1] == ' ') {
            printf("Invalid move. Please enter another move.\n");
        }
        else {
            printf("Invalid move. Please enter another move.\n");
        }
        if(check_endgame()) {
            printf("Game over!\n");
            game_end = 1;
        }
        display_board();
        printf("\n");
        printf("Player 2 (white), enter your move. (row, col, drow, dcol): ");
        scanf("%d %d %d %d", &row, &col, &drow, &dcol);
        if(board[row - 1][col - 1] == 'w' || board[row - 1][col - 1] == 'W') {
            if(drow == -1 && (dcol == 1 || dcol == -1)) {
                if(board[row + drow - 1][col + dcol - 1] == 'b' || board[row + drow - 1][col + dcol - 1] == 'B') {
                    board[row + drow - 1][col + dcol - 1] = ' ';
                }
                move_piece(row - 1, col - 1, drow, dcol);
            }
            else if(drow == -2 && (dcol == 2 || dcol == -2)) {
                if(board[row + drow - 1][col + dcol - 1] == 'b' || board[row + drow - 1][col + dcol - 1] == 'B') {
                    board[row + drow - 1][col + dcol - 1] = ' ';
                    move_piece(row - 1, col - 1, drow, dcol);
                }
                else {
                    printf("Invalid move. Please enter another move.\n");
                }
            }
            else {
                printf("Invalid move. Please enter another move.\n");
            }
        }
        else if(board[row - 1][col - 1] == ' ') {
            printf("Invalid move. Please enter another move.\n");
        }
        else {
            printf("Invalid move. Please enter another move.\n");
        }
        if(check_endgame()) {
            printf("Game over!\n");
            game_end = 1;
        }
    }
    return 0;
}