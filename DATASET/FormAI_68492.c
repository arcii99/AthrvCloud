//FormAI DATASET v1.0 Category: Checkers Game ; Style: brave
#include <stdio.h>

char board[8][8] = { 				// The game board with starting positions
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
    {'_', 'r', '_', 'r', '_', 'r', '_', 'r'},
    {'r', '_', 'r', '_', 'r', '_', 'r', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', '_', '_', '_', '_', '_', '_', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
    {'b', '_', 'b', '_', 'b', '_', 'b', '_'},
    {'_', 'b', '_', 'b', '_', 'b', '_', 'b'},
};

void display_board() { 				// Displays the game board
    printf("   -------------------------\n");
    for (int i = 0; i < 8; i++) {
        printf("%d  |", i+1);
        for (int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n   -------------------------\n");
    }
    printf("     a   b   c   d   e   f   g   h\n");
}

int is_valid_move(int sx, int sy, int dx, int dy) { // Checks if the move is valid or not
    if (board[dy][dx] != '_') {
        return 0;
    }
    if (board[sy][sx] == 'r' && dy > sy) {
        return 0;
    }
    if (board[sy][sx] == 'b' && dy < sy) {
        return 0;
    }
    int dxabs = dx - sx;
    int dyabs = dy - sy;
    if (dxabs == dyabs || dxabs == -dyabs) { // diagonal move
        if (dyabs == 1) { // non-capturing move
            return 1;
        } else if (dyabs == 2) { // capturing move
            int mx = sx + (dx - sx) / 2;
            int my = sy + (dy - sy) / 2;
            if (board[my][mx] == 'r' || board[my][mx] == 'R') {
                board[my][mx] = '_';
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int make_move(char player) { // Function to make a move
    int valid_move = 0;
    int sx, sy, dx, dy;
    while (!valid_move) { // loop until a valid move is made
        printf("Player %c's turn:\n", player);
        printf("Enter the x and y coordinates of the piece you want to move (eg. a3): ");
        char input[2];
        scanf("%s", input);
        sx = input[0]-97; // converting a to 0, b to 1 and so on
        sy = input[1]-49; // converting 1 to 0, 2 to 1 and so on
        printf("Enter the x and y coordinates of the destination (eg. b4): ");
        scanf("%s", input);
        dx = input[0]-97;
        dy = input[1]-49;
        valid_move = is_valid_move(sx, sy, dx, dy);
        if (!valid_move) {
            printf("Invalid move!\n");
        }
    }
    board[dy][dx] = board[sy][sx];
    board[sy][sx] = '_';
    if (dy == 0 || dy == 7) { // checking if the piece has become a king
        board[dy][dx] = (board[dy][dx] == 'b' ? 'B' : 'R');
    }
    return (player == 'r' ? 'b' : 'r'); // returns the next player
}

int main() {
    char player = 'r';
    while (1) { // infinite loop until the game ends
        display_board();
        player = make_move(player);
    }
    return 0;
}