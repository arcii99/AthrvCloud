//FormAI DATASET v1.0 Category: Chess engine ; Style: complex
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

bool is_valid_move(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE ||
        x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return false;
    }
    
    // Check if move is diagonal
    if (x1 != x2 && y1 != y2) {
        return false;
    }
    
    // Check if there are any pieces blocking the move
    if (x1 == x2) {
        int i;
        for (i = y1 + 1; i < y2; i++) {
            if (board[x1][i] != ' ') {
                return false;
            }
        }
        for (i = y1 - 1; i > y2; i--) {
            if (board[x1][i] != ' ') {
                return false;
            }
        }
    } else if (y1 == y2) {
        int i;
        for (i = x1 + 1; i < x2; i++) {
            if (board[i][y1] != ' ') {
                return false;
            }
        }
        for (i = x1 - 1; i > x2; i--) {
            if (board[i][y1] != ' ') {
                return false;
            }
        }
    }
    
    return true;
}

void draw_board() {
    printf("   ");
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("  %c ", 'a' + i);
    }
    printf("\n");
    
    printf("  +");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("---+");
    }
    printf("\n");
    
    int j;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %d|", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf(" %d\n", BOARD_SIZE - i);
        
        printf("  +");
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("---+");
        }
        printf("\n");
    }
    
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("  %c ", 'a' + i);
    }
    printf("\n");
}

int main() {
    // Initialize board with pieces
    board[0][0] = 'R';
    board[0][1] = 'N';
    board[0][2] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    board[0][5] = 'B';
    board[0][6] = 'N';
    board[0][7] = 'R';
    board[1][0] = 'P';
    board[1][1] = 'P';
    board[1][2] = 'P';
    board[1][3] = 'P';
    board[1][4] = 'P';
    board[1][5] = 'P';
    board[1][6] = 'P';
    board[1][7] = 'P';
    board[6][0] = 'p';
    board[6][1] = 'p';
    board[6][2] = 'p';
    board[6][3] = 'p';
    board[6][4] = 'p';
    board[6][5] = 'p';
    board[6][6] = 'p';
    board[6][7] = 'p';
    board[7][0] = 'r';
    board[7][1] = 'n';
    board[7][2] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    board[7][5] = 'b';
    board[7][6] = 'n';
    board[7][7] = 'r';
    
    draw_board();
    
    // Game loop
    int turn = 1;
    while (true) {
        printf("Turn %d:\n", turn);
        
        // Get input
        printf("Enter start position: ");
        char start_pos[3];
        scanf("%s", start_pos);
        int start_x = BOARD_SIZE - (start_pos[1] - '0');
        int start_y = start_pos[0] - 'a';
        
        printf("Enter end position: ");
        char end_pos[3];
        scanf("%s", end_pos);
        int end_x = BOARD_SIZE - (end_pos[1] - '0');
        int end_y = end_pos[0] - 'a';
        
        // Check if move is valid
        if (!is_valid_move(start_x, start_y, end_x, end_y)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        // Make move
        board[end_x][end_y] = board[start_x][start_y];
        board[start_x][start_y] = ' ';
        
        draw_board();
        
        // Increment turn
        turn++;
    }
    
    return 0;
}