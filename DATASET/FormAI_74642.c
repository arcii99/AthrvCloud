//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define MAX_MOVE 100

typedef struct {
    int x, y;
} location;

location player_pos, ghost_pos;

char board[BOARD_SIZE][BOARD_SIZE];

void init_game() {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE-1 || j == 0 || j== BOARD_SIZE-1) {
                board[i][j] = '#';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    player_pos.x = BOARD_SIZE / 2;
    player_pos.y = BOARD_SIZE / 2;
    board[player_pos.x][player_pos.y] = 'P';
    ghost_pos.x = rand() % (BOARD_SIZE-2) + 1;
    ghost_pos.y = rand() % (BOARD_SIZE-2) + 1;
    board[ghost_pos.x][ghost_pos.y] = 'G';
}

void move_ghost() {
    int dx = 0, dy = 0;
    int r = rand() % 4;
    if (r == 0) dx = 1;
    if (r == 1) dx = -1;
    if (r == 2) dy = 1;
    if (r == 3) dy = -1;
    int nx = ghost_pos.x + dx;
    int ny = ghost_pos.y + dy;
    if (board[nx][ny] == ' ') {
        board[ghost_pos.x][ghost_pos.y] = ' ';
        ghost_pos.x = nx;
        ghost_pos.y = ny;
        board[ghost_pos.x][ghost_pos.y] = 'G';
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    init_game();
    int moves = 0;
    while (moves < MAX_MOVE) {
        char input = getchar();
        if (input == 'w') {
            int nx = player_pos.x - 1;
            if (nx > 0 && board[nx][player_pos.y] != '#') {
                board[player_pos.x][player_pos.y] = ' ';
                player_pos.x = nx;
                board[player_pos.x][player_pos.y] = 'P';
            }
        } else if (input == 's') {
            int nx = player_pos.x + 1;
            if (nx < BOARD_SIZE-1 && board[nx][player_pos.y] != '#') {
                board[player_pos.x][player_pos.y] = ' ';
                player_pos.x = nx;
                board[player_pos.x][player_pos.y] = 'P';
            }
        } else if (input == 'a') {
            int ny = player_pos.y - 1;
            if (ny > 0 && board[player_pos.x][ny] != '#') {
                board[player_pos.x][player_pos.y] = ' ';
                player_pos.y = ny;
                board[player_pos.x][player_pos.y] = 'P';
            }
        } else if (input == 'd') {
            int ny = player_pos.y + 1;
            if (ny < BOARD_SIZE-1 && board[player_pos.x][ny] != '#') {
                board[player_pos.x][player_pos.y] = ' ';
                player_pos.y = ny;
                board[player_pos.x][player_pos.y] = 'P';
            }
        }
        move_ghost();
        print_board();
        moves++;
    }
    printf("Game Over!\n");
    return 0;
}