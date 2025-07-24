//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct piece {
    char name[20];
    int x;
    int y;
};

struct board {
    struct piece pieces[24];
};

void init_board(struct board *board) {
    // Initialize red pieces
    board->pieces[0] = (struct piece) { "Red1", 1, 0 };
    board->pieces[1] = (struct piece) { "Red2", 3, 0 };
    board->pieces[2] = (struct piece) { "Red3", 5, 0 };
    board->pieces[3] = (struct piece) { "Red4", 7, 0 };
    board->pieces[4] = (struct piece) { "Red5", 0, 1 };
    board->pieces[5] = (struct piece) { "Red6", 2, 1 };
    board->pieces[6] = (struct piece) { "Red7", 4, 1 };
    board->pieces[7] = (struct piece) { "Red8", 6, 1 };
    board->pieces[8] = (struct piece) { "Red9", 1, 2 };
    board->pieces[9] = (struct piece) { "Red10", 3, 2 };
    board->pieces[10] = (struct piece) { "Red11", 5, 2 };
    board->pieces[11] = (struct piece) { "Red12", 7, 2 };

    // Initialize black pieces
    board->pieces[12] = (struct piece) { "Black1", 0, 5 };
    board->pieces[13] = (struct piece) { "Black2", 2, 5 };
    board->pieces[14] = (struct piece) { "Black3", 4, 5 };
    board->pieces[15] = (struct piece) { "Black4", 6, 5 };
    board->pieces[16] = (struct piece) { "Black5", 1, 6 };
    board->pieces[17] = (struct piece) { "Black6", 3, 6 };
    board->pieces[18] = (struct piece) { "Black7", 5, 6 };
    board->pieces[19] = (struct piece) { "Black8", 7, 6 };
    board->pieces[20] = (struct piece) { "Black9", 0, 7 };
    board->pieces[21] = (struct piece) { "Black10", 2, 7 };
    board->pieces[22] = (struct piece) { "Black11", 4, 7 };
    board->pieces[23] = (struct piece) { "Black12", 6, 7 };
}

void draw_board(struct board *board) {
    printf("\n");

    // Draw top border
    printf("   -----------------\n");

    // Draw rows
    for(int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);

        // Draw columns
        for(int j = 0; j < 8; j++) {
            int has_piece = 0;

            // Check if current position has a piece
            for(int k = 0; k < 24; k ++) {
                struct piece piece = board->pieces[k];
                if(piece.x == j && piece.y == i) {
                    printf("|%s", piece.name);
                    has_piece = 1;
                    break;
                }
            }

            // If no piece, print empty space
            if(!has_piece) {
                printf("| ");
            }
        }

        printf("|\n");
        printf("   -----------------\n");
    }

    // Draw bottom border
    printf("    A B C D E F G H\n");
}

void move_piece(struct board *board, char *from, char *to) {
    // Convert from and to to integers
    int from_x = from[0] - 'A';
    int from_y = from[1] - '1';
    int to_x = to[0] - 'A';
    int to_y = to[1] - '1';

    struct piece *piece = NULL;

    // Find piece to move
    for(int i = 0; i < 24; i++) {
        struct piece *p = &board->pieces[i];
        if(p->x == from_x && p->y == from_y) {
            piece = p;
            break;
        }
    }

    // Make move if piece found
    if(piece != NULL) {
        piece->x = to_x;
        piece->y = to_y;
    }
}

int main() {
    struct board board;
    init_board(&board);
    draw_board(&board);

    // Sample game
    move_piece(&board, "C2", "D3");
    move_piece(&board, "E7", "F6");
    move_piece(&board, "D3", "C4");
    move_piece(&board, "F6", "E5");
    move_piece(&board, "C4", "B5");
    move_piece(&board, "E5", "F4");

    draw_board(&board);

    return 0;
}