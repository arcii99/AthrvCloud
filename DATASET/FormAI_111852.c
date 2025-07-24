//FormAI DATASET v1.0 Category: Checkers Game ; Style: interoperable
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
    { ' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r' },
    { 'r', ' ', 'r', ' ', 'r', ' ', 'r', ' ' },
    { ' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ' },
    { ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b' },
    { 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ' },
};

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    printf(" +---------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("%d\n", i);
        printf(" +---------------+\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

int is_valid_move(int from_x, int from_y, int to_x, int to_y) {
    // Check if the destination is empty
    if (board[to_x][to_y] != ' ') {
        return 0;
    }
    
    // Ensure the move is diagonal and the correct distance
    if (from_x == to_x || from_y == to_y) {
        return 0;
    }
    
    if (abs(from_x - to_x) != abs(from_y - to_y)) {
        return 0;
    }
    
    if (abs(from_x - to_x) > 2) {
        return 0;
    }
    
    // Check if moving one square diagonally
    if (abs(from_x - to_x) == 1) {
        return 1;
    }
    
    // Check if jumping an opponent's piece
    int jump_x = (from_x + to_x) / 2;
    int jump_y = (from_y + to_y) / 2;
    if (board[jump_x][jump_y] == 'b' || board[jump_x][jump_y] == 'B') {
        return 1;
    }
    
    return 0;
}

void make_move(int from_x, int from_y, int to_x, int to_y) {
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = ' ';
    
    if (abs(from_x - to_x) == 2) {
        int jump_x = (from_x + to_x) / 2;
        int jump_y = (from_y + to_y) / 2;
        board[jump_x][jump_y] = ' ';
    }
}

int main() {
    print_board();
    
    while (1) {
        int from_x, from_y, to_x, to_y;
        printf("Enter move (row col): ");
        scanf("%d%d%d%d", &from_x, &from_y, &to_x, &to_y);
        
        if (is_valid_move(from_x, from_y, to_x, to_y)) {
            make_move(from_x, from_y, to_x, to_y);
            print_board();
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    
    return 0;
}