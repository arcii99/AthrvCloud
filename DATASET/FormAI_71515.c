//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_SHIPS 3
#define SHIP_LENGTH 3
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define HIT 'X'
#define MISS '0'

typedef struct {
    int x, y, is_horizontal, length;
} Ship;

void clear_screen() {
    printf("\033[2J\033[1;1H");
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", i + 'A');
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d|", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int is_valid_position(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int is_valid_ship(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, int is_horizontal, int length) {
    if (is_horizontal) {
        for (int i = x; i < x + length; i++) {
            if (!is_valid_position(i, y) || board[i][y] != '-') {
                return 0;
            }
        }
    } else {
        for (int i = y; i < y + length; i++) {
            if (!is_valid_position(x, i) || board[x][i] != '-') {
                return 0;
            }
        }
    }
    return 1;
}

void place_ship(char board[BOARD_SIZE][BOARD_SIZE], Ship ship) {
    if (ship.is_horizontal) {
        for (int i = ship.x; i < ship.x + ship.length; i++) {
            board[i][ship.y] = 'S';
        }
    } else {
        for (int i = ship.y; i < ship.y + ship.length; i++) {
            board[ship.x][i] = 'S';
        }
    }
}

void place_ships(char board[BOARD_SIZE][BOARD_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < MAX_SHIPS; i++) {
        Ship ship;
        ship.length = SHIP_LENGTH;
        ship.is_horizontal = rand() % 2;
        if (ship.is_horizontal) {
            ship.x = rand() % BOARD_SIZE;
            ship.y = rand() % (BOARD_SIZE - ship.length + 1);
        } else {
            ship.x = rand() % (BOARD_SIZE - ship.length + 1);
            ship.y = rand() % BOARD_SIZE;
        }
        if (is_valid_ship(board, ship.x, ship.y, ship.is_horizontal, ship.length)) {
            place_ship(board, ship);
        } else {
            i--;
        }
    }
}

void update_board(char board[BOARD_SIZE][BOARD_SIZE], int x, int y, char symbol) {
    board[x][y] = symbol;
}

void get_user_input(int *x, int *y, char *direction) {
    printf("Enter x coordinate (1-%d): ", BOARD_SIZE);
    scanf("%d", x);
    printf("Enter y coordinate (A-%c): ", BOARD_SIZE + 'A' - 1);
    scanf(" %c", direction);
    *y = *direction - 'A';
    *direction = '\0';
    (*x)--;
}

void play_game(char board[BOARD_SIZE][BOARD_SIZE]) {
    int num_guesses = 0;
    while (1) {
        clear_screen();
        print_board(board);
        int x, y;
        char direction, move;
        get_user_input(&x, &y, &direction);
        if (board[x][y] == 'S') {
            update_board(board, x, y, HIT);
            num_guesses++;
            if (num_guesses == MAX_SHIPS * SHIP_LENGTH) {
                clear_screen();
                print_board(board);
                printf("Congratulations, you won!\n");
                break;
            }
        } else {
            update_board(board, x, y, MISS);
        }
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    place_ships(board);
    play_game(board);
    return 0;
}