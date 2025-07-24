//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Constants
#define ROWS 20
#define COLS 20

// Global Variables
char pattern[ROWS][COLS];

// Function Prototypes
void initializePattern();
void printPattern();
void fillPattern();
void fillRow(int row);
void *printAsync(void *param);

int main() {
    initializePattern();
    fillPattern();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, printAsync, NULL);

    fillRow(0);

    pthread_join(thread_id, NULL);
    printf("Pattern printing completed.\n");

    return 0;
}

void initializePattern() {
    memset(pattern, '.', sizeof(pattern));
}

void printPattern() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", pattern[i][j]);
        }
        printf("\n");
    }
}

void fillPattern() {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            pattern[i][j] = (rand() % 2) ? '.' : '*';
        }
    }
}

void fillRow(int row) {
    for (int j = 0; j < COLS; j++) {
        pattern[row][j] = (j % 2) ? '*' : '.';
    }
}

void *printAsync(void *param) {
    for (int i = 0; i < ROWS; i++) {
        printPattern();
        usleep(500 * 1000); // sleep for 0.5 seconds
        printf("\n");
    }
    return NULL;
}