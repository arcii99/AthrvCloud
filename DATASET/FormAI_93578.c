//FormAI DATASET v1.0 Category: Checkers Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Initialize global variables
#define BOARD_SIZE 8
#define RED 1
#define BLACK 2
#define EMPTY 0

int board[BOARD_SIZE][BOARD_SIZE];
int player = RED;

//Function to display the board
void display_board() {
    printf("\n   1 2 3 4 5 6 7 8\n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == RED)
                printf("R ");
            else if (board[i][j] == BLACK)
                printf("B ");
            else
                printf("- ");
        }
        printf("|\n");
    }
    printf("  -----------------\n");
}

//Function to initialize the board
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i < 3 && (i+j)%2 == 0)
                board[i][j] = BLACK;
            else if (i > 4 && (i+j)%2 == 0)
                board[i][j] = RED;
            else
                board[i][j] = EMPTY;
        }
    }
}

//Function to check if the move is valid or not
int check_move(int fr, int fc, int tr, int tc) {
    if (board[tr][tc] != EMPTY)
        return 0;
    if (player == RED && tr > fr)
        return 0;
    if (player == BLACK && tr < fr)
        return 0;
    if (tr != fr-1 && tr != fr+1)
        return 0;
    if (tc != fc-1 && tc != fc+1)
        return 0;
    return 1;
}

//Function to check if the jump move is valid or not
int check_jump_move(int fr, int fc, int tr, int tc) {
    int r = (tr+fr)/2;
    int c = (tc+fc)/2;
    if (board[r][c] == EMPTY)
        return 0;
    if (board[r][c] == player || board[tr][tc] != EMPTY)
        return 0;
    if (player == RED && tr > fr)
        return 0;
    if (player == BLACK && tr < fr)
        return 0;
    if (tr != fr-2 && tr != fr+2)
        return 0;
    if (tc != fc-2 && tc != fc+2)
        return 0;
    return 1;
}

//Function to make the move
void make_move(int fr, int fc, int tr, int tc) {
    board[tr][tc] = board[fr][fc];
    board[fr][fc] = EMPTY;
    if ((player == RED && tr == 0) || (player == BLACK && tr == BOARD_SIZE-1))
        board[tr][tc] = player + 2;
}

//Function to make the jump move
void make_jump_move(int fr, int fc, int tr, int tc) {
    int r = (tr+fr)/2;
    int c = (tc+fc)/2;
    board[r][c] = EMPTY;
    make_move(fr, fc, tr, tc);
}

//Function to check if the player can move
int can_move() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player+2) {
                if (i > 0 && j > 0 && check_move(i, j, i-1, j-1))
                    return 1;
                if (i > 0 && j < BOARD_SIZE-1 && check_move(i, j, i-1, j+1))
                    return 1;
                if (i < BOARD_SIZE-1 && j > 0 && check_move(i, j, i+1, j-1))
                    return 1;
                if (i < BOARD_SIZE-1 && j < BOARD_SIZE-1 && check_move(i, j, i+1, j+1))
                    return 1;
                if (i > 1 && j > 1 && check_jump_move(i, j, i-2, j-2))
                    return 1;
                if (i > 1 && j < BOARD_SIZE-2 && check_jump_move(i, j, i-2, j+2))
                    return 1;
                if (i < BOARD_SIZE-2 && j > 1 && check_jump_move(i, j, i+2, j-2))
                    return 1;
                if (i < BOARD_SIZE-2 && j < BOARD_SIZE-2 && check_jump_move(i, j, i+2, j+2))
                    return 1;
            }
        }
    }
    return 0;
}

//Function to switch the player turn
void switch_player() {
    if (player == RED)
        player = BLACK;
    else
        player = RED;
}

int main() {
    printf("Welcome to the Shape-Shifting Checkers Game!\n");
    printf("Red moves first. Good luck!\n");
    initialize_board();
    srand(time(0));
    display_board();
    int fr, fc, tr, tc;
    while (1) {
        if (!can_move()) {
            printf("Game over! ");
            if (player == RED)
                printf("Black wins!\n");
            else
                printf("Red wins!\n");
            break;
        }
        printf("-----------------------\n");
        printf("%s", (player == RED) ? "Red's move: " : "Black's move: ");
        if (player == RED || rand() % 2 == 0) {
            printf("Enter the from position: row and column (e.g., 3 2): ");
            scanf("%d %d", &fr, &fc);
            printf("Enter the to position: row and column (e.g., 4 3): ");
            scanf("%d %d", &tr, &tc);
        } else {
            int found_move = 0;
            do {
                fr = rand() % BOARD_SIZE;
                fc = rand() % BOARD_SIZE;
                if (board[fr][fc] == player || board[fr][fc] == player+2) {
                    if (fr > 0 && fc > 0 && check_move(fr, fc, fr-1, fc-1)) {
                        found_move = 1;
                        tr = fr-1;
                        tc = fc-1;
                    }
                    if (fr > 0 && fc < BOARD_SIZE-1 && check_move(fr, fc, fr-1, fc+1)) {
                        found_move = 1;
                        tr = fr-1;
                        tc = fc+1;
                    }
                    if (fr < BOARD_SIZE-1 && fc > 0 && check_move(fr, fc, fr+1, fc-1)) {
                        found_move = 1;
                        tr = fr+1;
                        tc = fc-1;
                    }
                    if (fr < BOARD_SIZE-1 && fc < BOARD_SIZE-1 && check_move(fr, fc, fr+1, fc+1)) {
                        found_move = 1;
                        tr = fr+1;
                        tc = fc+1;
                    }
                    if (fr > 1 && fc > 1 && check_jump_move(fr, fc, fr-2, fc-2)) {
                        found_move = 1;
                        tr = fr-2;
                        tc = fc-2;
                    }
                    if (fr > 1 && fc < BOARD_SIZE-2 && check_jump_move(fr, fc, fr-2, fc+2)) {
                        found_move = 1;
                        tr = fr-2;
                        tc = fc+2;
                    }
                    if (fr < BOARD_SIZE-2 && fc > 1 && check_jump_move(fr, fc, fr+2, fc-2)) {
                        found_move = 1;
                        tr = fr+2;
                        tc = fc-2;
                    }
                    if (fr < BOARD_SIZE-2 && fc < BOARD_SIZE-2 && check_jump_move(fr, fc, fr+2, fc+2)) {
                        found_move = 1;
                        tr = fr+2;
                        tc = fc+2;
                    }
                }
            } while (!found_move);
            printf("%d %d %d %d\n", fr+1, fc+1, tr+1, tc+1);
        }
        if (check_jump_move(fr, fc, tr, tc))
            make_jump_move(fr, fc, tr, tc);
        else if (check_move(fr, fc, tr, tc))
            make_move(fr, fc, tr, tc);
        else {
            printf("Invalid move. Try again.\n");
            continue;
        }
        display_board();
        if (board[tr][tc] == player+2) {
            int found_jump = 0;
            do {
                printf("You have another jump option! Enter the to position: row and column (e.g., 4 3): ");
                scanf("%d %d", &tr, &tc);
                if (check_jump_move(fr, fc, tr, tc)) {
                    found_jump = 1;
                    make_jump_move(fr, fc, tr, tc);
                    display_board();
                    if (board[tr][tc] == player+2)
                        found_jump = 0;
                    else
                        switch_player();
                } else {
                    printf("Invalid move. Try again.\n");
                }
            } while (found_jump);
        } else {
            switch_player();
        }
    }
    return 0;
}