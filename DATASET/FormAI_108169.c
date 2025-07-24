//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>

// Representing the board with a 2D array of characters
char board[8][8] = {
    {'-', 'w', '-', 'w', '-', 'w', '-', 'w'},
    {'w', '-', 'w', '-', 'w', '-', 'w', '-'},
    {'-', 'w', '-', 'w', '-', 'w', '-', 'w'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'-', '-', '-', '-', '-', '-', '-', '-'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
    {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
    {'r', '-', 'r', '-', 'r', '-', 'r', '-'}
};

// Function to print the current state of the board
void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < 8; i++) {
        printf("%d ", i);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move a piece from one cell to another
int move(int x1, int y1, int x2, int y2) {
    // Checking if the move is valid
    if((x2 + y2) % 2 == 0 || board[x2][y2] != '-') {
        return 0;
    }

    // Checking if the move is within the bounds of the board
    if(x2 < x1 || ((x2 - x1) % 2 != 0) || (board[x1][y1] == 'w' && x2 > x1) || (board[x1][y1] == 'r' && x2 < x1)) {
        return 0;
    }

    // Checking if the piece is a king
    if(board[x1][y1] == 'w' && x2 == 7) {
        board[x2][y2] = 'W';
    } else if(board[x1][y1] == 'r' && x2 == 0) {
        board[x2][y2] = 'R';
    } else {
        board[x2][y2] = board[x1][y1];
    }
    
    board[x1][y1] = '-';

    // Removing the jumped piece if there is one
    if(x1 - x2 == 2) {
        if(y1 - y2 == 2) {
            board[x1-1][y1-1] = '-';
        } else {
            board[x1-1][y1+1] = '-';
        }
    } else if(x1 - x2 == -2) {
        if(y1 - y2 == 2) {
            board[x1+1][y1-1] = '-';
        } else {
            board[x1+1][y1+1] = '-';
        }
    }

    return 1;
}

int main() {
    int player = 1;
    int x1, y1, x2, y2;
    while(1) {
        print_board();

        // Getting the move from the player
        printf("Player %d's move:\n", player);
        printf("Enter starting position (x, y): ");
        scanf("%d %d", &x1, &y1);
        printf("Enter ending position (x, y): ");
        scanf("%d %d", &x2, &y2);

        // Moving the piece and checking if the move was successful
        if(move(x1, y1, x2, y2)) {
            if(player == 1) {
                player = 2;
            } else {
                player = 1;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }

        // Checking if someone has won
        int r_count = 0, w_count = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 'R' || board[i][j] == 'r') {
                    r_count++;
                } else if(board[i][j] == 'W' || board[i][j] == 'w') {
                    w_count++;
                }
            }
        }

        if(r_count == 0) {
            printf("\nPlayer 2 wins!\n");
            break;
        } else if(w_count == 0) {
            printf("\nPlayer 1 wins!\n");
            break;
        }
    }

    return 0;
}