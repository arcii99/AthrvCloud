//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>

//define constants
#define BOARD_SIZE 8
#define EMPTY 0
#define RED 1
#define BLACK 2

//define type for gameboard
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int current_turn;
    int red_remaining;
    int black_remaining;
} gameboard_t;

//initialize the gameboard
void init_gameboard(gameboard_t *gb) {
    //initialize the gameboard to all empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            gb->board[i][j] = EMPTY;
        }
    }
    
    //set up the red pieces
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                gb->board[i][j] = RED;
                gb->red_remaining++;
            }
        }
    }
    
    //set up the black pieces
    for (int i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                gb->board[i][j] = BLACK;
                gb->black_remaining++;
            }
        }
    }
    
    //set current turn to red
    gb->current_turn = RED;
}

//print the gameboard
void print_gameboard(gameboard_t *gb) {
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (gb->board[i][j]) {
                case EMPTY:
                    printf(". ");
                    break;
                case RED:
                    printf("R ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }
    printf("Red remaining pieces: %d\n", gb->red_remaining);
    printf("Black remaining pieces: %d\n", gb->black_remaining);
}

//check if a move is valid
int is_valid_move(gameboard_t *gb, int x1, int y1, int x2, int y2) {
    //check if move is within the bounds of the gameboard
    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) {
        return 0;
    }
    
    //check if end position is empty
    if (gb->board[x2][y2] != EMPTY) {
        return 0;
    }
    
    //calculate the change in x and y
    int dx = x2 - x1;
    int dy = y2 - y1;
    
    //determine if move is valid based on current turn
    if (gb->current_turn == RED) {
        //check if move is diagonal and forward
        if ((dx == 1 || dx == -1) && dy == 1) {
            return 1;
        }
        //check if move is a jump
        else if ((dx == 2 || dx == -2) && dy == 2) {
            //check if jumped over a black piece
            if (gb->board[x1 + dx/2][y1 + dy/2] == BLACK) {
                return 1;
            }
        }
    }
    else if (gb->current_turn == BLACK) {
        //check if move is diagonal and forward
        if ((dx == 1 || dx == -1) && dy == -1) {
            return 1;
        }
        //check if move is a jump
        else if ((dx == 2 || dx == -2) && dy == -2) {
            //check if jumped over a red piece
            if (gb->board[x1 + dx/2][y1 + dy/2] == RED) {
                return 1;
            }
        }
    }
    
    return 0;
}

//make a move on the gameboard
int make_move(gameboard_t *gb, int x1, int y1, int x2, int y2) {
    //check if move is valid
    if (!is_valid_move(gb, x1, y1, x2, y2)) {
        return 0;
    }
    
    //move piece
    gb->board[x2][y2] = gb->board[x1][y1];
    gb->board[x1][y1] = EMPTY;
    
    //check if move was a jump and remove jumped piece
    if (abs(x2 - x1) == 2) {
        gb->board[x1 + (x2 - x1)/2][y1 + (y2 - y1)/2] = EMPTY;
        if (gb->current_turn == RED) {
            gb->black_remaining--;
        }
        else if (gb->current_turn == BLACK) {
            gb->red_remaining--;
        }
    }
    
    //switch current turn
    if (gb->current_turn == RED) {
        gb->current_turn = BLACK;
    }
    else if (gb->current_turn == BLACK) {
        gb->current_turn = RED;
    }
    
    return 1;
}

//play the game
void play_game(gameboard_t *gb) {
    int x1, y1, x2, y2;
    printf("Welcome to Checkers!\n");
    while (gb->red_remaining > 0 && gb->black_remaining > 0) {
        print_gameboard(gb);
        printf("%s's turn: ", gb->current_turn == RED ? "Red" : "Black");
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if (!make_move(gb, x1, y1, x2, y2)) {
            printf("Invalid move!\n");
        }
    }
    printf("%s wins!\n", gb->red_remaining == 0 ? "Black" : "Red");
}

int main() {
    gameboard_t gb;
    init_gameboard(&gb);
    play_game(&gb);
    return 0;
}