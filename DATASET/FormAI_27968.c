//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10  // Define board size

// Function to initialize board
void initialize_board(char board[][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to print board
void print_board(char board[][BOARD_SIZE]) {
    int i, j;

    printf("    ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("__");
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly place ships on the board
void place_ships(char board[][BOARD_SIZE]) {
    int i, x, y, orientation;

    srand(time(NULL));

    for (i = 1; i <= 5; i++) {
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
            orientation = rand() % 2;
        } while (!check_placement(board, x, y, orientation, i));

        place_ship(board, x, y, orientation, i);
    }
}

// Function to check if a ship can be placed
int check_placement(char board[][BOARD_SIZE], int x, int y, int orientation, int size) {
    int i;

    if (board[x][y] != '-') {
        return 0;
    }

    if (orientation == 0) {
        if (x + size > BOARD_SIZE) {
            return 0;
        }

        for (i = 0; i < size; i++) {
            if (board[x+i][y] != '-') {
                return 0;
            }
        }
    } else {
        if (y + size > BOARD_SIZE) {
            return 0;
        }

        for (i = 0; i < size; i++) {
            if (board[x][y+i] != '-') {
                return 0;
            }
        }
    }

    return 1;
}

// Function to place a ship on the board
void place_ship(char board[][BOARD_SIZE], int x, int y, int orientation, int size) {
    int i;

    if (orientation == 0) {
        for (i = 0; i < size; i++) {
            board[x+i][y] = 'S';
        }
    } else {
        for (i = 0; i < size; i++) {
            board[x][y+i] = 'S';
        }
    }
}

// Function to fire a shot at the board
void fire_shot(char board[][BOARD_SIZE], int *hits, int *misses) {
    int x, y;

    printf("Enter coordinates to fire (x, y): ");
    scanf("%d %d", &x, &y);

    if (board[x][y] == '-') {
        printf("Miss!\n");
        (*misses)++;
        board[x][y] = 'O';
    } else if (board[x][y] == 'S') {
        printf("Hit!\n");
        (*hits)++;
        board[x][y] = 'X';
    } else {
        printf("You already fired there!\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int hits = 0;
    int misses = 0;

    initialize_board(board);
    place_ships(board);

    printf("Welcome to Battleship!\n");
    printf("You have 25 shots to sink all 5 ships!\n");
    printf("Here is the board:\n");

    print_board(board);

    while (hits < 5 && misses < 25) {
        fire_shot(board, &hits, &misses);
        printf("Hits: %d\n", hits);
        printf("Misses: %d\n", misses);
        print_board(board);
    }

    if (hits == 5) {
        printf("Congratulations! You sunk all 5 ships!\n");
    } else {
        printf("You ran out of shots! Game over!\n");
    }

    return 0;
}