//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define ROWS 25
#define COLUMNS 25

char map[ROWS][COLUMNS] = {
    "*****************",
    "*..............*",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*.*.*.*.*.*.*.*.*",
    "*...............",
    "*****************"
};

typedef struct {
    int x, y;
} Point;

Point pacman, ghost;

pthread_t threads[2];
pthread_mutex_t lock;

void print_map() {
    system("clear");

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void initialize_game() {
    pacman.x = 1;
    pacman.y = 1;

    ghost.x = 21;
    ghost.y = 21;

    print_map();
}

void* move_pacman(void* arg) {
    while (true) {
        char key = getchar();

        pthread_mutex_lock(&lock);

        if (key == 'w' && map[pacman.x-1][pacman.y] == '.') {
            map[pacman.x][pacman.y] = '.';
            pacman.x--;
        }
        else if (key == 's' && map[pacman.x+1][pacman.y] == '.') {
            map[pacman.x][pacman.y] = '.';
            pacman.x++;
        }
        else if (key == 'a' && map[pacman.x][pacman.y-1] == '.') {
            map[pacman.x][pacman.y] = '.';
            pacman.y--;
        }
        else if (key == 'd' && map[pacman.x][pacman.y+1] == '.') {
            map[pacman.x][pacman.y] = '.';
            pacman.y++;
        }

        if (pacman.x == ghost.x && pacman.y == ghost.y) {
            printf("Game Over");
            exit(0);
        }

        map[pacman.x][pacman.y] = 'P';

        pthread_mutex_unlock(&lock);

        print_map();
    }
}

void* move_ghost(void* arg) {
    while (true) {
        pthread_mutex_lock(&lock);

        if (ghost.x > pacman.x && map[ghost.x-1][ghost.y] == '.') {
            map[ghost.x][ghost.y] = '.';
            ghost.x--;
        }
        else if (ghost.x < pacman.x && map[ghost.x+1][ghost.y] == '.') {
            map[ghost.x][ghost.y] = '.';
            ghost.x++;
        }
        else if (ghost.y > pacman.y && map[ghost.x][ghost.y-1] == '.') {
            map[ghost.x][ghost.y] = '.';
            ghost.y--;
        }
        else if (ghost.y < pacman.y && map[ghost.x][ghost.y+1] == '.') {
            map[ghost.x][ghost.y] = '.';
            ghost.y++;
        }

        if (pacman.x == ghost.x && pacman.y == ghost.y) {
            printf("Game Over");
            exit(0);
        }

        map[ghost.x][ghost.y] = 'G';

        pthread_mutex_unlock(&lock);

        print_map();

        usleep(500000);
    }
}

int main() {
    initialize_game();

    pthread_mutex_init(&lock, NULL);

    pthread_create(&threads[0], NULL, move_pacman, NULL);
    pthread_create(&threads[1], NULL, move_ghost, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}