//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// Chess Board 
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to print the Chess Board 
void print_board() {
    for(int i=0; i<8; i++) {
        printf("\t%c %c %c %c %c %c %c %c\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7]);
    }
    printf("\n");
}

// Main Function
int main() {
    int turn = 1;   // Turn 0 for black and 1 for white
    
    // Print Initial board
    printf("Initial Board: \n");
    print_board();
    
    // Loop until game ends
    while(1) {
        // Get input coordinates from user
        int x1, x2, y1, y2;
        printf("Enter move for Player %d: ", turn+1);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
 
        // Move the piece
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
 
        // Print new board
        print_board();
 
        // Change turn
        turn = (turn + 1) % 2;
    }
}