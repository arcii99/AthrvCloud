//FormAI DATASET v1.0 Category: Chess AI ; Style: beginner-friendly
#include <stdio.h>

// Function that prints the board
void printBoard(char board[][8]){

    printf("\nThe Board:\n");

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(){

    // Initial Chess Board
    char board[][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                       {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                       {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                       {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                       {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                       {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                       {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
                     };

    printBoard(board);
    
    return 0;
}