//FormAI DATASET v1.0 Category: Checkers Game ; Style: surrealist
#include <stdio.h>

// Checkerpiece structure
typedef struct {
    int x;
    int y;
    char symbol;
    int king;
} Checkerpiece;

// Function to move a checker piece
void move_piece(Checkerpiece *piece, int x, int y) {
    printf("The checker piece moves to position (%d, %d)\n", x, y);
    piece->x = x;
    piece->y = y;
}

// Function to king a checker piece
void king_piece(Checkerpiece *piece) {
    printf("The checker piece is now a king!\n");
    piece->king = 1;
    piece->symbol = '&';
}

int main() {
    // Initialize checker pieces
    Checkerpiece piece1 = {4, 5, 'o', 0};
    Checkerpiece piece2 = {5, 6, 'x', 0};

    // Display initial board state
    printf("Initial board state:\n");
    printf("   1 2 3 4 5 6 7 8\n");
    printf("  -----------------\n");
    for (int i = 1; i <= 8; i++) {
        printf("%d |", i);
        for (int j = 1; j <= 8; j++) {
            if (i == piece1.x && j == piece1.y) {
                printf("%c|", piece1.symbol);
            } else if (i == piece2.x && j == piece2.y) {
                printf("%c|", piece2.symbol);
            } else {
                printf(" |");
            }
        }
        printf("\n");
        printf("  -----------------\n");
    }

    // Move and king the checker pieces
    move_piece(&piece2, 4, 5);
    king_piece(&piece1);

    // Display updated board state
    printf("Updated board state:\n");
    printf("   1 2 3 4 5 6 7 8\n");
    printf("  -----------------\n");
    for (int i = 1; i <= 8; i++) {
        printf("%d |", i);
        for (int j = 1; j <= 8; j++) {
            if (i == piece1.x && j == piece1.y) {
                printf("%c|", piece1.symbol);
            } else if (i == piece2.x && j == piece2.y) {
                printf("%c|", piece2.symbol);
            } else {
                printf(" |");
            }
        }
        printf("\n");
        printf("  -----------------\n");
    }

    return 0;
}