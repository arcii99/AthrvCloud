//FormAI DATASET v1.0 Category: Checkers Game ; Style: energetic
#include <stdio.h>

char board[8][8] = { // initialize the game board
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
    {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'}
};

void print_board() { // print the game board state
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int x1, int y1, int x2, int y2) { // check if the move is valid
    if ((board[x2][y2] != '_') || (x1 < 0) || (y1 < 0) || (x2 < 0) || (y2 < 0))
        return 0;
    if ((x2 > 7) || (y2 > 7) || (x1 > 7) || (y1 > 7))
        return 0;
    if ((x2 - x1 == 2 || x2 - x1 == -2) && (y2 - y1 == 2 || y2 - y1 == -2)) {
        int x = (x1 + x2) / 2;
        int y = (y1 + y2) / 2;
        if (board[x][y] != '_')
            return 0;
        if (board[x1][y1] == 'r' && x2 > x1)
            return 0;
        if (board[x1][y1] == 'b' && x2 < x1)
            return 0;
        return 1;
    } else if ((x2 - x1 == 1 || x2 - x1 == -1) && (y2 - y1 == 1 || y2 - y1 == -1)) {
        if (board[x1][y1] == 'r' && x2 > x1)
            return 0;
        if (board[x1][y1] == 'b' && x2 < x1)
            return 0;
        return 1;
    }
    return 0;
}

void make_move(int x1, int y1, int x2, int y2) { // make the move
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '_';
    if (x1 - x2 == 2 || x1 - x2 == -2) {
        int x = (x1 + x2) / 2;
        int y = (y1 + y2) / 2;
        board[x][y] = '_';
    }
}

int main() {
    printf("Welcome to the C Checkers Game!\n");
    int player = 1;
    int x1, y1, x2, y2;
    while (1) {
        print_board();
        do {
            printf("Player %d, enter move (x1 y1 x2 y2): ", player);
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        } while (!is_valid_move(x1, y1, x2, y2));
        make_move(x1, y1, x2, y2);
        if (player == 1)
            player = 2;
        else
            player = 1;
    }
    return 0;
}