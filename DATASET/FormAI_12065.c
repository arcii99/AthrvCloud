//FormAI DATASET v1.0 Category: Chess engine ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define BOARD_SIZE 8
#define CAPITAL 'A'
#define PAWN 'P'

char game_board[BOARD_SIZE][BOARD_SIZE];

// Initialize the game board
void initialize_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            game_board[i][j] = '-';
        }
    }
    
    for(int i=0; i<BOARD_SIZE; i++) {
        game_board[1][i] = PAWN;
        game_board[6][i] = tolower(PAWN);
    }

    game_board[0][0] = game_board[0][7] = CAPITAL;
    game_board[7][0] = game_board[7][7] = tolower(CAPITAL);
}

// Print the game board
void print_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d", BOARD_SIZE-i);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf(" %c", game_board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%c ", CAPITAL+i);
    }
    printf("\n");
}

// Convert unicode to int
int convert(char c) {
    return c - CAPITAL;
}

// Check if a move is valid
int valid_move(int x1, int y1, int x2, int y2) {
    char piece = game_board[y1][x1];
    if(islower(piece)) { // Only lowercase pieces can move upwards
        if(y1 >= y2) {
            return 0;
        }
    } else if(isupper(piece)) { // Only uppercase pieces can move downwards
        if(y1 <= y2) {
            return 0;
        }
    }

    int dx = x2 - x1;
    int dy = y2 - y1;
    switch(tolower(piece)) {
        case PAWN:
            if((dx == 0) && (dy == 1) && game_board[y2][x2] == '-') {
                // Pawn can move one forward if the space is empty
                return 1;
            } else {
                return 0;
            }
        case CAPITAL: case 'k':
            if((abs(dx) == 1 || dx == 0) && (abs(dy) == 1 || dy == 0)) {
                // King can move one space in any direction
                return 1;
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

int main() {
    initialize_board();
    print_board();

    while(1) {
        int x1, y1, x2, y2;
        printf("Enter move <x1 y1 x2 y2>: ");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(valid_move(x1, y1, x2, y2)) {
            game_board[y2][x2] = game_board[y1][x1];
            game_board[y1][x1] = '-';
            print_board();
        } else {
            printf("Invalid move!\n");
        }
    }

    return 0;
}