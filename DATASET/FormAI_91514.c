//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAP_WIDTH 30
#define MAP_HEIGHT 20
#define NUM_GHOSTS 3
#define MAX_SCORE 246

int map[MAP_HEIGHT][MAP_WIDTH];
int pacman_x, pacman_y;
int score;
int ghosts[NUM_GHOSTS][2];
int gameover;

void init_map()
{
    int i, j;

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == 0 || i == MAP_HEIGHT-1 || j == 0 || j == MAP_WIDTH-1) {
                map[i][j] = 1;
            } else {
                map[i][j] = 0;
            }
        }
    }

    for (i = 1; i < MAP_HEIGHT-1; i++) {
        for (j = 1; j < MAP_WIDTH-1; j++) {
            if (i == 3 && (j < 8 || j > 20)) {
                map[i][j] = 1;
            } else if (i == MAP_HEIGHT-4 && (j < 8 || j > 20)) {
                map[i][j] = 1;
            } else if (j == 8 && (i < 6 || i > MAP_HEIGHT-7)) {
                map[i][j] = 1;
            } else if (j == MAP_WIDTH-9 && i > 8 && i < MAP_HEIGHT-4) {
                map[i][j] = 1;
            } else {
                map[i][j] = rand() % 2;
            }
        }
    }

    pacman_x = MAP_WIDTH / 2;
    pacman_y = MAP_HEIGHT / 2;
    score = 0;
    gameover = 0;

    for (i = 0; i < NUM_GHOSTS; i++) {
        ghosts[i][0] = rand() % (MAP_WIDTH-2) + 1;
        ghosts[i][1] = rand() % (MAP_HEIGHT-2) + 1;
    }
}

void print_map()
{
    int i, j;

    printf("\033[2J");

    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            if (i == pacman_y && j == pacman_x) {
                printf("C");
            } else if (map[i][j] == 2) {
                printf(".");
            } else if (map[i][j] == 1) {
                printf("#");
            } else if (map[i][j] == 3) {
                printf("G");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nScore: %d\n", score);
}

void move_pacman(int dx, int dy)
{
    if (map[pacman_y+dy][pacman_x+dx] != 1) {
        pacman_x += dx;
        pacman_y += dy;

        if (map[pacman_y][pacman_x] == 2) {
            map[pacman_y][pacman_x] = 0;
            score++;
        }
    }

    if (score >= MAX_SCORE) {
        gameover = 1;
    }
}

void move_ghosts()
{
    int i, dx, dy;

    for (i = 0; i < NUM_GHOSTS; i++) {
        dx = rand() % 3 - 1;
        dy = rand() % 3 - 1;

        if (map[ghosts[i][1]+dy][ghosts[i][0]+dx] != 1) {
            ghosts[i][0] += dx;
            ghosts[i][1] += dy;
        }

        if (ghosts[i][0] == pacman_x && ghosts[i][1] == pacman_y) {
            gameover = 1;
        }
    }
}

int main()
{
    char ch;

    srand(time(NULL));

    while (1) {
        init_map();

        while (!gameover) {
            print_map();
            ch = getchar();

            switch (ch) {
            case 'w': move_pacman(0, -1); break;
            case 'a': move_pacman(-1, 0); break;
            case 's': move_pacman(0, 1); break;
            case 'd': move_pacman(1, 0); break;
            }

            move_ghosts();
        }

        printf("Game over!\n");
        printf("Press q to quit or any other key to play again.\n");

        ch = getchar();
        if (ch == 'q' || ch == 'Q') {
            break;
        }
    }

    return 0;
}