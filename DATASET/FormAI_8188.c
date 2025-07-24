//FormAI DATASET v1.0 Category: Chess engine ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

//defining Board length and width as well as board array
#define BOARD_LENGTH 8
#define BOARD_WIDTH 8
int board[BOARD_LENGTH][BOARD_WIDTH];

//defining pieces
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

//initializing each piece with its move pattern
int moves[7][3][3] = {
    {{0,0,0},{0,0,0},{0,0,0}},//blank
    {{-1,0,0},{-1,-1,0},{-1,1,0}},//pawn
    {{-2,-1,0},{-2,1,0},{-1,-2,0},{-1,2,0},{1,-2,0},{1,2,0},{2,-1,0},{2,1,0}},//knight
    {{-1,-1,-1},{-1,-1,1},{-1,1,-1},{-1,1,1},{1,-1,-1},{1,-1,1},{1,1,-1},{1,1,1}},//bishop
    {{-1,0,0},{0,-1,0},{0,0,-1},{0,1,0},{0,0,1},{1,0,0}},//rook
    {{-1,-1,-1},{-1,-1,0},{-1,-1,1},{-1,0,-1},{-1,0,0},{-1,0,1},{-1,1,-1},{-1,1,0},{-1,1,1},{0,-1,-1},{0,-1,0},{0,-1,1},{0,0,-1},{0,0,1},{0,1,-1},{0,1,0},{0,1,1},{1,-1,-1},{1,-1,0},{1,-1,1},{1,0,-1},{1,0,0},{1,0,1},{1,1,-1},{1,1,0},{1,1,1}},//queen
    {{-1,-1,-1},{-1,-1,0},{-1,-1,1},{-1,0,-1},{-1,0,0},{-1,0,1},{-1,1,-1},{-1,1,0},{-1,1,1},{0,-1,-1},{0,-1,0},{0,-1,1},{0,0,-1},{0,0,1},{0,1,-1},{0,1,0},{0,1,1},{1,-1,-1},{1,-1,0},{1,-1,1},{1,0,-1},{1,0,0},{1,0,1},{1,1,-1},{1,1,0},{1,1,1}}//king
};

//function to print board
void print_board() {
    printf("   A  B  C  D  E  F  G  H\n");
    for (int i=0; i<BOARD_LENGTH; i++) {
        printf("%d ", BOARD_LENGTH-i);
        for (int j=0; j<BOARD_WIDTH; j++) {
            if (board[i][j] == 0) {
                printf("|__");
            } else {
                printf("|%d_", board[i][j]);
            }
        }
        printf("|\n");
    }
    printf("   A  B  C  D  E  F  G  H\n");
}

//function to initialize board with pieces
void init_board() {
    for (int i=0; i<BOARD_LENGTH; i++) {
        for (int j=0; j<BOARD_WIDTH; j++) {
            if (i < 2) {
                board[i][j] = PAWN;
            } else if (i == 7 && (j == 0 || j == 7)) {
                board[i][j] = ROOK;
            } else if (i == 7 && (j == 1 || j == 6)) {
                board[i][j] = KNIGHT;
            } else if (i == 7 && (j == 2 || j == 5)) {
                board[i][j] = BISHOP;
            } else if (i == 7 && j == 3) {
                board[i][j] = QUEEN;
            } else if (i == 7 && j == 4) {
                board[i][j] = KING;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

//function to check if a move is valid
int check_move(int pi, int pj, int ni, int nj) {
    if (ni < 0 || ni >= BOARD_LENGTH || nj < 0 || nj >= BOARD_WIDTH) {
        return 0; //out of bounds
    }
    int pp = board[pi][pj];
    int np = board[ni][nj];
    if ((pp == PAWN && ni != pi - 1) ||
        (pp == KNIGHT && moves[KNIGHT][ni-pi+1][nj-pj+1] == 0) ||
        (pp == BISHOP && moves[BISHOP][ni-pi+1][nj-pj+1] == 0) ||
        (pp == ROOK && moves[ROOK][ni-pi+1][nj-pj+1] == 0) ||
        (pp == QUEEN && moves[QUEEN][ni-pi+1][nj-pj+1] == 0) ||
        (pp == KING && moves[KING][ni-pi+1][nj-pj+1] == 0)) {
        return 0; //invalid move
    }
    if (np == 0) {
        return 1; //valid non-attack move
    }
    if ((pp > 0 && np > 0) || (pp < 0 && np < 0)) {
        return 0; //invalid attack move
    }
    return 2; //valid attack move
}

//function to execute a move
void execute_move(int pi, int pj, int ni, int nj) {
    int pp = board[pi][pj];
    int np = board[ni][nj];
    board[pi][pj] = 0;
    board[ni][nj] = pp;
    if (pp == KING) {
        if (ni == pi && (nj == pj+2 || nj == pj-2)) {
            if (nj == pj+2) {
                execute_move(ni, 7, ni, 5);
            } else {
                execute_move(ni, 0, ni, 3);
            }
        }
    }
}

//futuristic AI function to choose a move
void choose_move() {
    printf("AI is thinking...");
    int pi, pj, ni, nj;
    pi = pj = ni = nj = 0;
    while (1) {
        pi = rand() % BOARD_LENGTH;
        pj = rand() % BOARD_WIDTH;
        if (board[pi][pj] != 0) {
            break;
        }
    }
    while (1) {
        ni = rand() % BOARD_LENGTH;
        nj = rand() % BOARD_WIDTH;
        int res = check_move(pi, pj, ni, nj);
        if (res == 1 || res == 2) {
            if (res == 2) {
                execute_move(pi, pj, ni, nj);
            } else {
                board[pi][pj] = 0;
                board[ni][nj] = PAWN;
            }
            printf("AI moves from %d,%d to %d,%d\n", pi, pj, ni, nj);
            break;
        }
    }
}

int main() {
    int turn = 0;
    init_board();
    print_board();
    while (1) {
        if (turn % 2 == 0) {
            printf("White's turn\n");
            int pi, pj, ni, nj;
            printf("Enter piece position: ");
            scanf("%d,%d", &pi, &pj);
            printf("Enter new position: ");
            scanf("%d,%d", &ni, &nj);
            int res = check_move(pi, pj, ni, nj);
            if (res == 1 || res == 2) {
                if (res == 2) {
                    execute_move(pi, pj, ni, nj);
                } else {
                    board[pi][pj] = 0;
                    board[ni][nj] = PAWN;
                }
                print_board();
                turn++;
            } else {
                printf("Invalid move!\n");
            }
        } else {
            choose_move();
            print_board();
            turn++;
        }
    }
    return 0;
}