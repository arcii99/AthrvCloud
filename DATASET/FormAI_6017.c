//FormAI DATASET v1.0 Category: Chess engine ; Style: happy
#include <stdio.h>

// Initialize the chess board
char board[8][8] = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', ' ', '.', ' '},
                    {' ', ' ', ' ', '.', ' ', '.', ' ', '.'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

// Function to print the chess board
void print_board() {
    printf("\n  A B C D E F G H\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8 - i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8 - i);
    }
    printf("  A B C D E F G H\n\n");
}

// Function to make a move on the chess board
void make_move(int x1, int y1, int x2, int y2) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
}

int main() {
    printf("Welcome to the Happy Chess Engine Example Program!\n");
    printf("Get ready to play some happy chess!\n");
    printf("----------------------------------------------\n\n");
    
    // Print the initial chess board
    printf("Here's the starting position:\n");
    print_board();
    
    // Make a move and print the updated chess board
    printf("Let's move the pawn on A2 to A3!\n");
    make_move(6, 0, 5, 0);
    print_board();
    
    // Make another move and print the updated chess board again
    printf("Now let's move the knight on G8 to F6!\n");
    make_move(0, 6, 2, 5);
    print_board();
    
    // Game complete - print final board
    printf("The game is over. Here's the final position:\n");
    print_board();
    
    // Celebrate with a happy message
    printf("Hooray! You've played Happy Chess with our Happy Chess Engine Example Program!\n");
    return 0;
}