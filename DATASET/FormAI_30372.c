//FormAI DATASET v1.0 Category: Pattern printing ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_ROWS 7
#define MAX_COLS 7

char C_PATTERN[MAX_ROWS][MAX_COLS] = {
    {'*', '*', '*', '*', '*', '*', '*',},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ',},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ',},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ',},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ',},
    {'*', ' ', ' ', ' ', ' ', ' ', ' ',},
    {'*', '*', '*', '*', '*', '*', '*',}
};

void *printPattern(void *args) {
    int* row = (int*) args;
    int i;
    for (i = 0; i < MAX_COLS; i++) {
        printf("%c ", C_PATTERN[*row][i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_ROWS];
    int row_numbers[MAX_ROWS];
    int i;
    for (i = 0; i < MAX_ROWS; i++) {
        row_numbers[i] = i;
    }
    for (i = 0; i < MAX_ROWS; i++) {
        pthread_create(&threads[i], NULL, printPattern, (void*)&row_numbers[i]);
    }
    for (i = 0; i < MAX_ROWS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}