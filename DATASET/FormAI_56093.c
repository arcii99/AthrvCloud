//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_SHIPS 5
#define SHIP_SIZES {2, 2, 3, 4, 5}

// Define the ship struct
typedef struct {
    int size;
    int hits;
    bool vertical;
    int row;
    int col;
} Ship;

// Define the board struct
typedef struct {
    char grid[BOARD_SIZE][BOARD_SIZE];
    Ship ships[NUM_SHIPS];
} Board;

// Function prototypes
void init_board(Board *board);
void place_ships(Board *board);
void print_board(Board *board);
void play_game(Board *board);
bool fire(int row, int col, Board *board);
bool has_won(Board *board);

int main() {
    srand(time(NULL));
    Board board;
    init_board(&board);
    place_ships(&board);
    play_game(&board);
    return 0;
}

// Function to initialize the board
void init_board(Board *board) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            board->grid[i][j] = '.';
        }
    }
}

// Function to randomly place the ships on the board
void place_ships(Board *board) {
    int i, j, s;
    int shipSizes[NUM_SHIPS] = SHIP_SIZES;
    for(s = 0; s < NUM_SHIPS; s++) {
        Ship ship = {shipSizes[s], 0, rand() % 2 == 0, 0, 0};
        if(ship.vertical) {
            ship.row = rand() % (BOARD_SIZE - ship.size + 1);
            ship.col = rand() % BOARD_SIZE;
        } else {
            ship.row = rand() % BOARD_SIZE;
            ship.col = rand() % (BOARD_SIZE - ship.size + 1);
        }
        board->ships[s] = ship;
    }
}

// Function to print the board
void print_board(Board *board) {
    int i, j, s;
    printf("  ");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to play the game
void play_game(Board *board) {
    int row, col;
    while(!has_won(board)) {
        print_board(board);
        printf("Enter row and column to fire (example: A3): ");
        scanf("%c%d", &row, &col);
        row = row - 'A';
        col--;
        if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
            if(fire(row, col, board)) {
                printf("Hit!\n");
            } else {
                printf("Miss!\n");
            }
        } else {
            printf("Invalid coordinates.\n");
        }
    }
    print_board(board);
    printf("You win!\n");
}

// Function to fire at a board location
bool fire(int row, int col, Board *board) {
    int s;
    for(s = 0; s < NUM_SHIPS; s++) {
        Ship *ship = &board->ships[s];
        if(ship->vertical) {
            if(ship->col == col && row >= ship->row && row < ship->row + ship->size) {
                ship->hits++;
                board->grid[row][col] = 'X';
                if(ship->hits == ship->size) {
                    printf("You sank a ship!\n");
                }
                return true;
            }
        } else {
            if(ship->row == row && col >= ship->col && col < ship->col + ship->size) {
                ship->hits++;
                board->grid[row][col] = 'X';
                if(ship->hits == ship->size) {
                    printf("You sank a ship!\n");
                }
                return true;
            }
        }
    }
    board->grid[row][col] = 'O';
    return false;
}

// Function to check if all ships have been sunk
bool has_won(Board *board) {
    int s;
    for(s = 0; s < NUM_SHIPS; s++) {
        if(board->ships[s].hits < board->ships[s].size) {
            return false;
        }
    }
    return true;
}