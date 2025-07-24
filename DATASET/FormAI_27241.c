//FormAI DATASET v1.0 Category: Chess AI ; Style: beginner-friendly
#include <stdio.h>

// Define the chess board numbers.
enum chessBoard {
    empty,
    wp, wr, wn, wb, wq, wk,
    bp, br, bn, bb, bq, bk
};

int chessBoardState[64] = {
    br, bn, bb, bq, bk, bb, bn, br,
    bp, bp, bp, bp, bp, bp, bp, bp,
    empty, empty, empty, empty, empty, empty, empty, empty,
    empty, empty, empty, empty, empty, empty, empty, empty,
    empty, empty, empty, empty, empty, empty, empty, empty,
    empty, empty, empty, empty, empty, empty, empty, empty,
    wp, wp, wp, wp, wp, wp, wp, wp,
    wr, wn, wb, wq, wk, wb, wn, wr
};

char pieceChar[] = {
    '.', 'p', 'r', 'n', 'b', 'q', 'k', 'P', 'R', 'N', 'B', 'Q', 'K'
};

void displayBoard(int chessBoard[64]) {
    printf("\n");
    for (int i = 0; i < 64; i++) {
        if (i % 8 == 0 && i > 0) {
            printf("\n");
        }
        printf("%3c", pieceChar[chessBoard[i]]);
    }
    printf("\n");
}

int main(void) {
    displayBoard(chessBoardState);
}