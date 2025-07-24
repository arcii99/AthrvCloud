//FormAI DATASET v1.0 Category: Chess engine ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef struct {
    char piece;
    int rank;
    int file;
} Square;

void initialise_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    char pieces[] = {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'};
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        for (int file = 0; file < BOARD_SIZE; file++) {
            if (rank == 1) {
                board[rank][file].piece = 'P';
            } else if (rank == 6) {
                board[rank][file].piece = 'p';
            } else if (rank == 0) {
                board[rank][file].piece = pieces[file];
            } else if (rank == 7) {
                board[rank][file].piece = pieces[file] + ('a' - 'A');
            } else {
                board[rank][file].piece = '-';
            }
            board[rank][file].rank = rank;
            board[rank][file].file = file;
        }
    }
}

void display_board(Square board[BOARD_SIZE][BOARD_SIZE]) {
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        printf("%d ", BOARD_SIZE - rank);
        for (int file = 0; file < BOARD_SIZE; file++) {
            printf("%c ", board[rank][file].piece);
        }
        printf("\n");
    }
    printf("  ");
    for (char file = 'a'; file < 'a' + BOARD_SIZE; file++) {
        printf("%c ", file);
    }
    printf("\n");
}

int main() {
    Square board[BOARD_SIZE][BOARD_SIZE];
    initialise_board(board);
    display_board(board);

    return EXIT_SUCCESS;
}