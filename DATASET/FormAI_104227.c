//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_SHIPS 5
#define SHIP_SIZE 3

typedef enum {EMPTY, SHIP, HIT, MISS} Cell;

void initialize_board(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; ++i) {
        for(j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void place_ship(Cell board[BOARD_SIZE][BOARD_SIZE], int size) {
    int i, j;
    int x, y;
    int dir = rand() % 2;
    if(dir == 0) {
        x = rand() % BOARD_SIZE;
        y = rand() % (BOARD_SIZE - size);
        for(i = 0; i < size; ++i) {
            board[x][y + i] = SHIP;
        }
    } else {
        x = rand() % (BOARD_SIZE - size);
        y = rand() % BOARD_SIZE;
        for(i = 0; i < size; ++i) {
            board[x + i][y] = SHIP;
        }
    }
}

void place_ships(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < MAX_SHIPS; ++i) {
        int size = SHIP_SIZE;
        place_ship(board, size);
    }
}

void display_board(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    printf("\n ");
    for(i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
    }
    printf("\n");
    for(i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i);
        for(j = 0; j < BOARD_SIZE; ++j) {
            if(board[i][j] == EMPTY) {
                printf(". ");
            } else if(board[i][j] == SHIP) {
                printf("S ");
            } else if(board[i][j] == HIT) {
                printf("X ");
            } else if(board[i][j] == MISS) {
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int get_move() {
    int x, y;
    printf("Enter coordinates: ");
    scanf("%d%d", &x, &y);
    return x * BOARD_SIZE + y;
}

int check_hit(Cell board[BOARD_SIZE][BOARD_SIZE], int move) {
    int x = move / BOARD_SIZE;
    int y = move % BOARD_SIZE;
    if(board[x][y] == SHIP) {
        board[x][y] = HIT;
        return 1;
    } else if(board[x][y] == EMPTY) {
        board[x][y] = MISS;
    }
    return 0;
}

int check_win(Cell board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for(i = 0; i < BOARD_SIZE; ++i) {
        for(j = 0; j < BOARD_SIZE; ++j) {
            if(board[i][j] == SHIP) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    Cell board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);

    place_ships(board);

    while(1) {
        display_board(board);
        int move = get_move();
        int hit = check_hit(board, move);
        if(hit) {
            printf("Hit!\n");
        } else {
            printf("Miss!\n");
        }
        if(check_win(board)) {
            printf("You win!\n");
            break;
        }
    }

    return 0;
}