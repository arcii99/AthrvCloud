//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>

// Chess board representation
char board[8][8] = {
    {'r', 'h', 'b', 'q', 'k', 'b', 'h', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'}
};

// Function to print the chess board
void print_board() {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(int x, int y, int x_new, int y_new) {
    // Check if out of board bounds
    if(x_new < 0 || x_new > 7 || y_new < 0 || y_new > 7) {
        return 0;
    }
    
    // Check if same position
    if(x == x_new && y == y_new) {
        return 0;
    }
    
    // Check if piece to move exists
    if(board[x][y] == ' ' || board[x][y] == '.') {
        return 0;
    }
    
    // Check if piece to move is same color as destination piece
    if((board[x][y] > 'a' && board[x_new][y_new] > 'a') || (board[x][y] < 'a' && board[x_new][y_new] < 'a')) {
        return 0;
    }
    
    // TODO add more checks for individual pieces
    
    // All checks passed
    return 1;
}

int main() {
    print_board();
    
    // Example move
    if(is_valid_move(6, 4, 4, 4)) {
        board[4][4] = board[6][4];
        board[6][4] = ' ';
    }
    
    printf("\nAfter move:\n\n");
    print_board();
    
    return 0;
}