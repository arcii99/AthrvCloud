//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char board[8][8];
    int white_king_rank, white_king_file, black_king_rank, black_king_file;
    int white_to_play;
} chess_game;


void initialize_game(chess_game* game) {
    int rank, file;
    char start_board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    memcpy(game->board, start_board, sizeof(char) * 8 * 8);

    game->white_king_rank = 7;
    game->white_king_file = 4;
    game->black_king_rank = 0;
    game->black_king_file = 4;
    game->white_to_play = 1;
}

void print_board(chess_game* game) {
    printf("  A B C D E F G H\n");
    printf("  ---------------\n");
    for (int rank = 0; rank < 8; rank++) {
        printf("%d|", rank + 1);
        for (int file = 0; file < 8; file++) {
            printf("%c|", game->board[rank][file]);
        }
        printf("%d\n", rank + 1);
    }
    printf("  ---------------\n");
    printf("  A B C D E F G H\n");
}

int main() {
    chess_game game;
    initialize_game(&game);
    print_board(&game);
    return 0;
}