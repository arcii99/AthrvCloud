//FormAI DATASET v1.0 Category: Memory Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6
#define MAX_MOVES 15

/* Represents a tile on the board */
typedef struct {
    int x; /* x-coordinate */
    int y; /* y-coordinate */
    char value; /* the value shown on the tile */
    int is_matched; /* 1 if the tile has been matched, 0 otherwise */
} Tile;

/* Initialize the board with random tile values */
void init_board(Tile board[][BOARD_SIZE]) {
    int i, j;
    char values[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'};
    int values_len = sizeof(values)/sizeof(char);
    
    /* Seed the random number generator */
    srand(time(NULL));
    
    /* Assign random values to the tiles */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            int index = rand() % values_len;
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].value = values[index];
            board[i][j].is_matched = 0;
        }
    }
}

/* Print the current state of the board */
void print_board(Tile board[][BOARD_SIZE]) {
    int i, j;
    
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_matched) {
                printf("%c ", board[i][j].value);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

/* Get user input for a move */
void get_move(Tile board[][BOARD_SIZE], int *x1, int *y1, int *x2, int *y2) {
    printf("\nEnter two coordinates to reveal the tiles (e.g. 0 0 1 2): ");
    scanf("%d %d %d %d", x1, y1, x2, y2);
    
    /* Make sure the moves are within the game board */
    while (*x1 < 0 || *y1 < 0 || *x1 >= BOARD_SIZE || *y1 >= BOARD_SIZE ||
           *x2 < 0 || *y2 < 0 || *x2 >= BOARD_SIZE || *y2 >= BOARD_SIZE) {
        printf("\nInvalid move. Enter two coordinates to reveal the tiles (e.g. 0 0 1 2): ");
        scanf("%d %d %d %d", x1, y1, x2, y2);
    }
}

/* Check if two tiles match */
int do_tiles_match(Tile t1, Tile t2) {
    return (t1.value == t2.value && t1.x != t2.x && t1.y != t2.y);
}

/* Check if the game is over */
int is_game_over(Tile board[][BOARD_SIZE]) {
    int i, j;
    int num_matched_tiles = 0;
    
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].is_matched) {
                num_matched_tiles++;
            }
        }
    }
    
    return (num_matched_tiles == BOARD_SIZE*BOARD_SIZE);
}

int main() {
    Tile board[BOARD_SIZE][BOARD_SIZE];
    int num_moves = 0;
    
    /* Initialize the board */
    init_board(board);
    
    /* Keep playing until the game is over or the player runs out of moves */
    while (!is_game_over(board) && num_moves < MAX_MOVES) {
        int x1, y1, x2, y2;
        
        /* Print the board */
        print_board(board);
        
        /* Get user input */
        get_move(board, &x1, &y1, &x2, &y2);
        
        /* Check if the tiles match */
        if (do_tiles_match(board[x1][y1], board[x2][y2])) {
            board[x1][y1].is_matched = 1;
            board[x2][y2].is_matched = 1;
            printf("\nMatch!\n");
        } else {
            printf("\nNo match.\n");
        }
        
        num_moves++;
    }
    
    /* Print the final state of the board */
    print_board(board);
    
    /* Print the game over message */
    if (is_game_over(board)) {
        printf("\nCongratulations! You won in %d moves.\n", num_moves);
    } else {
        printf("\nSorry, you ran out of moves.\n");
    }
    
    return 0;
}