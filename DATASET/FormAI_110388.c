//FormAI DATASET v1.0 Category: Chess engine ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void print_board() {
    int i, j;
    printf("\n\n");

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int moves[4];
    srand(time(NULL));
    int move_count = 0;
    while (move_count < 20) {
        printf("Move count: %d\n", move_count + 1);
        moves[0] = rand() % 8;
        moves[1] = rand() % 8;
        moves[2] = rand() % 8;
        moves[3] = rand() % 8;

        if (board[moves[0]][moves[1]] == ' ') {
            printf("No piece found at [%d, %d]...\n", moves[0], moves[1]);
            continue;
        }

        if (board[moves[2]][moves[3]] == ' ') {
            printf("Moving %c from [%d, %d] to [%d, %d]...\n",
                    board[moves[0]][moves[1]], moves[0], moves[1], moves[2], moves[3]);
            board[moves[2]][moves[3]] = board[moves[0]][moves[1]];
            board[moves[0]][moves[1]] = ' ';
            print_board();
            move_count++;
        } else {
            printf("Piece already exists at [%d, %d], skipping move...\n", moves[2], moves[3]);
        }
    }

    printf("Game finished in %d moves! Thanks for playing.\n", move_count);
    return 0;
}