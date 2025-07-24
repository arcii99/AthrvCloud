//FormAI DATASET v1.0 Category: Game of Life ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

bool world[ROWS][COLUMNS];
bool next_world[ROWS][COLUMNS];

pthread_mutex_t lock;

void display_world() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c ", world[i][j] ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int i, int j) {
    int count = 0;
    for (int a = i - 1; a <= i + 1; a++) {
        for (int b = j - 1; b <= j + 1; b++) {
            if (a >= 0 && a < ROWS && b >= 0 && b < COLUMNS){
                if (a != i || b != j) {
                    count += world[a][b];
                }
            } 
        }
    }
    return count;
}

void update(int i, int j) {
    int neighbors = count_neighbors(i, j);
    if (world[i][j]) {
        if (neighbors < 2 || neighbors > 3) {
            next_world[i][j] = false;
        } else {
            next_world[i][j] = true;
        }
    } else {
        if (neighbors == 3) {
            next_world[i][j] = true;
        } else {
            next_world[i][j] = false;
        }
    }
}

void* run_simulation() {
    while (true) {
        pthread_mutex_lock(&lock);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                update(i, j);
            }
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                world[i][j] = next_world[i][j];
            }
        }
        pthread_mutex_unlock(&lock);
        usleep(1000000); // simulated delay of 1 second
    }
}

int main() {
    pthread_t thread;
    pthread_mutex_init(&lock, NULL);

    // initialize the world
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            world[i][j] = rand() % 2;
        }
    }

    display_world();

    // start the simulation thread
    pthread_create(&thread, NULL, &run_simulation, NULL);

    // main thread will display the updated world
    while(true) {
        pthread_mutex_lock(&lock);
        display_world();
        pthread_mutex_unlock(&lock);
        usleep(500000); // simulated delay of 0.5 seconds
    }

    pthread_join(thread, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}