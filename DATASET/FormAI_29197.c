//FormAI DATASET v1.0 Category: Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10 // size of the playing board
#define MAX_SHIPS 3 // maximum number of ships
#define SHIP_SIZE 3 // size of each ship

// function prototypes
void init_board(char board[][BOARD_SIZE]);
void print_board(char board[][BOARD_SIZE]);
int is_valid_ship_placement(char board[][BOARD_SIZE], int row, int col, int dir);
void place_ship(char board[][BOARD_SIZE], int row, int col, int dir);
void place_all_ships(char board[][BOARD_SIZE]);

int main() {
    char player_board[BOARD_SIZE][BOARD_SIZE]; // player's playing board
    char computer_board[BOARD_SIZE][BOARD_SIZE]; // computer's playing board
    int player_hits = 0; // number of hits made by player
    int computer_hits = 0; // number of hits made by computer
    srand(time(NULL));

    init_board(player_board);
    init_board(computer_board);

    printf("Welcome to Battleship game!\n");
    printf("You will be playing against the computer.\n");
    printf("You need to sink all the ships of the computer to win.\n");
    printf("Let's start!\n\n");

    place_all_ships(computer_board);

    // game loop
    while (1) {
        int row, col;
        printf("Your turn:\n");
        print_board(computer_board);
        printf("Enter coordinates to hit (row col): ");
        scanf("%d %d", &row, &col);
        if (computer_board[row][col] == 'S') {
            printf("You hit a ship!\n");
            player_hits++;
            computer_board[row][col] = 'H';
            if (player_hits == MAX_SHIPS * SHIP_SIZE) {
                printf("Congratulations! You won!\n");
                break;
            }
        } else if (computer_board[row][col] == 'X' || computer_board[row][col] == 'H') {
            printf("You already hit there. Try again.\n");
        } else {
            printf("You missed!\n");
            computer_board[row][col] = 'X';

            // computer's turn
            printf("Computer's turn:\n");
            while (1) {
                row = rand() % BOARD_SIZE;
                col = rand() % BOARD_SIZE;
                if (player_board[row][col] == 'S') {
                    printf("Computer hit your ship at (%d, %d)!\n", row, col);
                    computer_hits++;
                    player_board[row][col] = 'H';
                    if (computer_hits == MAX_SHIPS * SHIP_SIZE) {
                        printf("Sorry, computer won. Better luck next time!\n");
                        break;
                    }
                    break;
                } else if (player_board[row][col] == 'X' || player_board[row][col] == 'H') {
                    continue;
                } else {
                    printf("Computer missed at (%d, %d).\n", row, col);
                    player_board[row][col] = 'X';
                    break;
                }
            }
        }
    }
    return 0;
}

// initialize playing board with water
void init_board(char board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '~';
        }
    }
}

// print playing board
void print_board(char board[][BOARD_SIZE]) {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// check if given ship placement is valid
int is_valid_ship_placement(char board[][BOARD_SIZE], int row, int col, int dir) {
    if (dir == 0) { // horizontal
        if (col + SHIP_SIZE > BOARD_SIZE) {
            return 0;
        }
        for (int i = col; i < col + SHIP_SIZE; i++) {
            if (board[row][i] == 'S') {
                return 0;
            }
        }
    } else if (dir == 1) { // vertical
        if (row + SHIP_SIZE > BOARD_SIZE) {
            return 0;
        }
        for (int i = row; i < row + SHIP_SIZE; i++) {
            if (board[i][col] == 'S') {
                return 0;
            }
        }
    }
    return 1;
}

// place ship on board
void place_ship(char board[][BOARD_SIZE], int row, int col, int dir) {
    if (dir == 0) { // horizontal
        for (int i = col; i < col + SHIP_SIZE; i++) {
            board[row][i] = 'S';
        }
    } else if (dir == 1) { // vertical
        for (int i = row; i < row + SHIP_SIZE; i++) {
            board[i][col] = 'S';
        }
    }
}

// place all ships randomly on board
void place_all_ships(char board[][BOARD_SIZE]) {
    int num_ships = 0;
    while (num_ships < MAX_SHIPS) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;
        int dir = rand() % 2;
        if (is_valid_ship_placement(board, row, col, dir)) {
            place_ship(board, row, col, dir);
            num_ships++;
        }
    }
}