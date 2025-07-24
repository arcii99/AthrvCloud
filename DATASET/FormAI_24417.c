//FormAI DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 10
#define COLUMNS 10

void *printC(void *arg);

char cPattern[ROWS][COLUMNS] = {
    {' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '},
    {' ', ' ', '*', '*', '*', '*', '*', '*', ' ', ' '}
};

int main() {
    int i;
    pthread_t thread;

    if (pthread_create(&thread, NULL, printC, NULL)) {
        printf("Error creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);

    return 0;
}

void *printC(void *arg) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%c", cPattern[i][j]);
        }
        printf("\n");
    }
    pthread_exit(NULL);
}