//FormAI DATASET v1.0 Category: Checkers Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, WHITE, BLACK } Square;

Square board[BOARD_SIZE][BOARD_SIZE] = {
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY},
    {EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE},
    {WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY}
};

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == BLACK) {
                printf("B ");
            } else if(board[i][j] == WHITE) {
                printf("W ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    int turn = 0; // 0 for White and 1 for Black
    
    while(1) {
        printf("Current board:\n");
        print_board();
        
        if(turn == 0) {
            printf("White's turn:\n");
        } else {
            printf("Black's turn:\n");
        }
        
        // Code for checking if game is over goes here
        
        // Code for getting player input goes here
        
        // Code for updating the board goes here
        
        turn = (turn + 1) % 2; // Switch turns
    }
    
    return 0;
}