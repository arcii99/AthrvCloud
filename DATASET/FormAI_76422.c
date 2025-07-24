//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Board {
    char actual_board[8][8]; //the actual board
    int last_move[2]; //last move played by black
    char turn; //whose turn it is now
    bool game_over; //if the game has ended
};

void init_board(struct Board* board) {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (i % 2 == j % 2) {
                if (i < 3) board -> actual_board[i][j] = 'b';
                else if (i > 4) board -> actual_board[i][j] = 'w';
                else board -> actual_board[i][j] = ' ';
            } else board -> actual_board[i][j] = ' ';
        }
    }
    board -> last_move[0] = board -> last_move[1] = -1;
    board -> turn = 'w';
    board -> game_over = false;
}

void display_board(struct Board board) {
    int i, j;
    printf("      1  2  3  4  5  6  7  8\n");
    printf("     -----------------------\n");
    for (i = 0; i < 8; i++) {
        printf(" %d  |", i+1);
        for (j = 0; j < 8; j++) {
            printf(" %c |", board.actual_board[i][j]);
        }
        printf(" %d ", i+1);
        printf("\n     -----------------------\n");
    }
    printf("      1  2  3  4  5  6  7  8\n");
}

bool valid_move_black(struct Board board, int si, int sj, int di, int dj) {
    if (board.actual_board[si][sj] != 'B' && si > di) return false; //regular pieces can't move back
    if (board.actual_board[si][sj] != 'b' && (abs(si - di) != 2 || abs(sj - dj) != 2)) return false;
    if (board.actual_board[di][dj] != ' ' || (si - di == 1 && abs(sj - dj) == 1)) return false; //target square must be empty
    if (abs(sj - dj) == 2) { //jumping over a piece
        int midi = (si + di) / 2, midj = (sj + dj) / 2;
        if (board.actual_board[midi][midj] == ' ' || board.actual_board[midi][midj] == 'b' || board.actual_board[midi][midj] == 'B') return false; //can't jump over empty squares or own pieces
    }
    return true;
}

bool valid_move_white(struct Board board, int si, int sj, int di, int dj) {
    if (board.actual_board[si][sj] != 'W' && di > si) return false; //regular pieces can't move back
    if (board.actual_board[si][sj] != 'w' && (abs(si - di) != 2 || abs(sj - dj) != 2)) return false;
    if (board.actual_board[di][dj] != ' ' || (di - si == 1 && abs(sj - dj) == 1)) return false; //target square must be empty
    if (abs(sj - dj) == 2) { //jumping over a piece
        int midi = (si + di) / 2, midj = (sj + dj) / 2;
        if (board.actual_board[midi][midj] == ' ' || board.actual_board[midi][midj] == 'w' || board.actual_board[midi][midj] == 'W') return false; //can't jump over empty squares or own pieces
    }
    return true;
}

bool can_jump_black(struct Board board, int i, int j) {
    if (board.actual_board[i][j] != 'B' && i > 1 && j < 6 && (board.actual_board[i-1][j+1] == 'w' || board.actual_board[i-1][j+1] == 'W') && board.actual_board[i-2][j+2] == ' ') return true;
    if (board.actual_board[i][j] != 'B' && i > 1 && j > 1 && (board.actual_board[i-1][j-1] == 'w' || board.actual_board[i-1][j-1] == 'W') && board.actual_board[i-2][j-2] == ' ') return true;
    if (board.actual_board[i][j] == 'B' && i < 6 && j < 6 && (board.actual_board[i+1][j+1] == 'w' || board.actual_board[i+1][j+1] == 'W') && board.actual_board[i+2][j+2] == ' ') return true;
    if (board.actual_board[i][j] == 'B' && i < 6 && j > 1 && (board.actual_board[i+1][j-1] == 'w' || board.actual_board[i+1][j-1] == 'W') && board.actual_board[i+2][j-2] == ' ') return true;
    return false;
}

bool can_jump_white(struct Board board, int i, int j) {
    if (board.actual_board[i][j] == 'W' && i > 1 && j < 6 && (board.actual_board[i-1][j+1] == 'b' || board.actual_board[i-1][j+1] == 'B') && board.actual_board[i-2][j+2] == ' ') return true;
    if (board.actual_board[i][j] == 'W' && i > 1 && j > 1 && (board.actual_board[i-1][j-1] == 'b' || board.actual_board[i-1][j-1] == 'B') && board.actual_board[i-2][j-2] == ' ') return true;
    if (board.actual_board[i][j] != 'W' && i < 6 && j < 6 && (board.actual_board[i+1][j+1] == 'b' || board.actual_board[i+1][j+1] == 'B') && board.actual_board[i+2][j+2] == ' ') return true;
    if (board.actual_board[i][j] != 'W' && i < 6 && j > 1 && (board.actual_board[i+1][j-1] == 'b' || board.actual_board[i+1][j-1] == 'B') && board.actual_board[i+2][j-2] == ' ') return true;
    return false;
}

bool can_move_black(struct Board board, int i, int j) {
    if (board.actual_board[i][j] != 'B' && i > 0 && j < 7 && board.actual_board[i-1][j+1] == ' ') return true; //move up-right
    if (board.actual_board[i][j] != 'B' && i > 0 && j > 0 && board.actual_board[i-1][j-1] == ' ') return true; //move up-left
    if (board.actual_board[i][j] == 'B' && i < 7 && j < 7 && board.actual_board[i+1][j+1] == ' ') return true; //move down-right
    if (board.actual_board[i][j] == 'B' && i < 7 && j > 0 && board.actual_board[i+1][j-1] == ' ') return true; //move down-left
    return false;
}

bool can_move_white(struct Board board, int i, int j) {
    if (board.actual_board[i][j] == 'W' && i > 0 && j < 7 && board.actual_board[i-1][j+1] == ' ') return true; //move up-right
    if (board.actual_board[i][j] == 'W' && i > 0 && j > 0 && board.actual_board[i-1][j-1] == ' ') return true; //move up-left
    if (board.actual_board[i][j] != 'W' && i < 7 && j < 7 && board.actual_board[i+1][j+1] == ' ') return true; //move down-right
    if (board.actual_board[i][j] != 'W' && i < 7 && j > 0 && board.actual_board[i+1][j-1] == ' ') return true; //move down-left
    return false;
}

bool move_is_valid(struct Board board, int si, int sj, int di, int dj) {
    int i, j;
    if (board.game_over || di < 0 || dj < 0 || di > 7 || dj > 7 || board.actual_board[si][sj] == ' ') return false;
    if ((board.turn == 'b' && board.actual_board[si][sj] != 'b' && board.actual_board[si][sj] != 'B') || (board.turn == 'w' && board.actual_board[si][sj] != 'w' && board.actual_board[si][sj] != 'W')) return false;
    if (board.turn == 'b' && !valid_move_black(board, si, sj, di, dj)) return false;
    if (board.turn == 'w' && !valid_move_white(board, si, sj, di, dj)) return false;
    if (abs(si - di) == 2) { //a jump
        int midi = (si + di) / 2, midj = (sj + dj) / 2;
        if (board.turn == 'b' && !can_jump_black(board, si, sj)) return false;
        if (board.turn == 'w' && !can_jump_white(board, si, sj)) return false;
        board.actual_board[midi][midj] = ' ';
    }
    board.actual_board[di][dj] = board.actual_board[si][sj];
    board.actual_board[si][sj] = ' ';
    board.last_move[0] = di;
    board.last_move[1] = dj;
    board.turn = board.turn == 'b' ? 'w' : 'b';
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board.actual_board[i][j] != ' ' && board.actual_board[i][j] != 'B' && board.actual_board[i][j] != 'W') {
                if ((board.turn == 'b' && (board.actual_board[i][j] == 'b' || board.actual_board[i][j] == 'B') && (can_jump_black(board, i, j) || can_move_black(board, i, j))) || (board.turn == 'w' && (board.actual_board[i][j] == 'w' || board.actual_board[i][j] == 'W') && (can_jump_white(board, i, j) || can_move_white(board, i, j)))) return true;
            }
        }
    }
    board.game_over = true;
    return true;
}

int main() {
    struct Board board;
    init_board(&board);
    while (true) {
        display_board(board);
        int si, sj, di, dj;
        printf("%c's move\n", board.turn);
        printf("Enter source row and source column: ");
        scanf("%d %d", &si, &sj);
        printf("Enter destination row and destination column: ");
        scanf("%d %d", &di, &dj);

        if (!move_is_valid(board, si-1, sj-1, di-1, dj-1)) {
            printf("Invalid move\n");
        }

        if (board.game_over) {
            if (board.turn == 'w') printf("Black wins!\n");
            else printf("White wins!\n");
            break;
        }
    }
    return 0;
}