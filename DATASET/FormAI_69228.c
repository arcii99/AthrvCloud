//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 10
#define INITIAL_SHIPS 3

typedef struct {
    int x;
    int y;
    bool hit;
} Cell;

typedef struct {
    Cell cells[BOARD_SIZE][BOARD_SIZE];
    int num_ships;
} Board;

void init_board(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->cells[i][j].x = i;
            board->cells[i][j].y = j;
            board->cells[i][j].hit = false;
        }
    }
    board->num_ships = 0;
}

void place_ship(Board *board) {
    bool valid_position = false;
    int x, y;
    do {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
        if (!board->cells[x][y].hit) {
            valid_position = true;
            board->cells[x][y].hit = true;
            board->num_ships++;
        }
    } while (!valid_position);
}

void print_board(Board *board) {
    printf("  ");
    for (int i = 1; i <= BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(board->cells[i][j].hit ? "X " : "- ");
        }
        printf("\n");
    }
}

bool game_over(Board *board) {
    return board->num_ships == 0;
}

void play_game(Board *board) {
    int num_guesses = 0;
    int x, y;
    while (!game_over(board)) {
        num_guesses++;
        printf("Guess %d: ", num_guesses);
        scanf("%d %d", &x, &y);
        x--;
        y--;
        if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE) {
            if (board->cells[x][y].hit) {
                printf("You already guessed this cell.\n");
            } else {
                board->cells[x][y].hit = true;
                if (board->num_ships == 0) {
                    printf("You sank the last ship. You win!\n");
                } else if (board->cells[x][y].hit) {
                    printf("Hit!\n");
                    board->num_ships--;
                } else {
                    printf("Miss.\n");
                }
            }
        } else {
            printf("Invalid guess.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    Board board;
    init_board(&board);
    for (int i = 0; i < INITIAL_SHIPS; i++) {
        place_ship(&board);
    }
    printf("Welcome to Battleship!\n");
    printf("You have %d ships to sink.\n", board.num_ships);
    print_board(&board);
    play_game(&board);
    return 0;
}