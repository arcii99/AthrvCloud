//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 15
#define MAZE_HEIGHT 15
#define PLAYER_START_X 7
#define PLAYER_START_Y 12
#define GHOST_START_X 7
#define GHOST_START_Y 2

char maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    "+-------------+",
    "|.....|.......|",
    "|--+-|+-+-----|",
    "|..|.....|..--|",
    "|-.|-.|.|.-|..|",
    "|....+-+....|--|",
    "|-|.|.....|....|",
    "|.|.+--.--|.|+-|",
    "|.|.|....|....|",
    "|-|.+-+-.|.-|--|",
    "|..|.....|...--|",
    "|--|+---+|.|...|",
    "|........|.|.-|",
    "|--|-----+.|..|",
    "+-------------+",
};

int player_x = PLAYER_START_X;
int player_y = PLAYER_START_Y;
int ghost_x = GHOST_START_X;
int ghost_y = GHOST_START_Y;

int score = 0;
int lives = 3;

int move_ghost() {
    int dx = player_x - ghost_x;
    int dy = player_y - ghost_y;

    if (dx > 0) {
        ghost_x++;
    } else if (dx < 0) {
        ghost_x--;
    }

    if (dy > 0) {
        ghost_y++;
    } else if (dy < 0) {
        ghost_y--;
    }

    if (maze[ghost_y][ghost_x] == '.') {
        ghost_x = rand() % MAZE_WIDTH;
        ghost_y = rand() % MAZE_HEIGHT;
    }

    if (ghost_x == player_x && ghost_y == player_y) {
        score -= 100;
        lives--;
        player_x = PLAYER_START_X;
        player_y = PLAYER_START_Y;
        ghost_x = GHOST_START_X;
        ghost_y = GHOST_START_Y;
        return 0;
    }

    return 1;
}

int main() {
    srand(time(NULL));

    while (lives > 0) {
        move_ghost();

        system("clear");

        printf("Score: %d Lives: %d\n", score, lives);

        for (int i = 0; i < MAZE_HEIGHT; i++) {
            for (int j = 0; j < MAZE_WIDTH; j++) {
                if (i == player_y && j == player_x) {
                    printf("P");
                } else if (i == ghost_y && j == ghost_x) {
                    printf("G");
                } else {
                    printf("%c", maze[i][j]);
                }
            }

            printf("\n");
        }

        char move = getchar();

        if (move == 'w') {
            if (maze[player_y-1][player_x] == '-' || maze[player_y-1][player_x] == '|' || maze[player_y-1][player_x] == '+') {
                continue;
            }

            player_y--;
        } else if (move == 'a') {
            if (maze[player_y][player_x-1] == '-' || maze[player_y][player_x-1] == '|' || maze[player_y][player_x-1] == '+') {
                continue;
            }

            player_x--;
        } else if (move == 's') {
            if (maze[player_y+1][player_x] == '-' || maze[player_y+1][player_x] == '|' || maze[player_y+1][player_x] == '+') {
                continue;
            }

            player_y++;
        } else if (move == 'd') {
            if (maze[player_y][player_x+1] == '-' || maze[player_y][player_x+1] == '|' || maze[player_y][player_x+1] == '+') {
                continue;
            }

            player_x++;
        }

        if (maze[player_y][player_x] == '.') {
            score += 10;
        }
    }

    printf("Game over\n");

    return 0;
}