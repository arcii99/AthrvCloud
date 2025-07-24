//FormAI DATASET v1.0 Category: Chess AI ; Style: paranoid
#include <stdio.h>

int pawnW[8][8], pawnB[8][8], rookW[8][8], rookB[8][8], knightW[8][8], knightB[8][8], bishopW[8][8], bishopB[8][8];
int queenW[8][8], queenB[8][8], kingW[8][8], kingB[8][8];
int Wscore = 0, Bscore = 0;
int player = 1;

void init_board() {
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            pawnW[i][j] = 0;
            pawnB[i][j] = 0;
            rookW[i][j] = 0;
            rookB[i][j] = 0;
            knightW[i][j] = 0;
            knightB[i][j] = 0;
            bishopW[i][j] = 0;
            bishopB[i][j] = 0;
            queenW[i][j] = 0;
            queenB[i][j] = 0;
            kingW[i][j] = 0;
            kingB[i][j] = 0;
        }
    }
}

void init_game() {
    init_board();
    // Add pieces to the board
    // ...
}

void print_board() {
    // Print the board
    // ...
}

void evaluate_board() {
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (pawnW[i][j]) {
                Wscore += 1;
            } else if (pawnB[i][j]) {
                Bscore += 1;
            } else if (rookW[i][j]) {
                Wscore += 5;
            } else if (rookB[i][j]) {
                Bscore += 5;
            } else if (knightW[i][j]) {
                Wscore += 3;
            } else if (knightB[i][j]) {
                Bscore += 3;
            } else if (bishopW[i][j]) {
                Wscore += 3;
            } else if (bishopB[i][j]) {
                Bscore += 3;
            } else if (queenW[i][j]) {
                Wscore += 9;
            } else if (queenB[i][j]) {
                Bscore += 9;
            } else if (kingW[i][j]) {
                Wscore += 4;
            } else if (kingB[i][j]) {
                Bscore += 4;
            }
        }
    }
}

int main() {
    init_game();
    print_board();
    evaluate_board();
    if (player == 1) {
        printf("White score: %d\n", Wscore);
        printf("Black score: %d\n", Bscore);
    } else {
        printf("Black score: %d\n", Bscore);
        printf("White score: %d\n", Wscore);
    }
    return 0;
}