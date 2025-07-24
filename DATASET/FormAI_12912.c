//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define ROWS 7
#define COLUMNS 7

// global variables
char pattern[ROWS][COLUMNS];

// function prototypes
void initPattern();
void *printPatternAsync(void *arg);

int main() {
    // initialize pattern array
    initPattern();

    // create thread to print pattern asynchronously
    pthread_t thread;
    pthread_create(&thread, NULL, printPatternAsync, NULL);

    // main function continues while thread prints pattern
    printf("Main function continues while pattern is being printed.\n");

    pthread_join(thread, NULL);

    return 0;
}

void initPattern() {
    // initialize pattern array to blank spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            pattern[i][j] = ' ';
        }
    }

    // set pattern values for "C"
    pattern[1][1] = '*';
    pattern[1][2] = '*';
    pattern[1][3] = '*';
    pattern[1][4] = '*';
    pattern[2][1] = '*';
    pattern[3][1] = '*';
    pattern[4][1] = '*';
    pattern[5][2] = '*';
    pattern[6][3] = '*';
    pattern[6][4] = '*';
}

void *printPatternAsync(void *arg) {
    while (true) {
        // clear console
        system("@cls||clear");

        // print pattern array
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                putchar(pattern[i][j]);
            }
            putchar('\n');
        }

        // add delay so pattern doesn't flicker
        usleep(100000);
    }

    // exit thread
    pthread_exit(NULL);
}