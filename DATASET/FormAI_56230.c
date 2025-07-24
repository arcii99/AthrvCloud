//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 10
#define COLUMNS 10

bool is_printing = false;
pthread_mutex_t printing_mutex;

typedef struct {
    int i_start;
    int i_end;
    int j_start;
    int j_end;
    char* pattern;
} PatternParams;

void* print_pattern(void* args) {
    PatternParams* params = (PatternParams*) args;
    int i_start = params->i_start;
    int i_end = params->i_end;
    int j_start = params->j_start;
    int j_end = params->j_end;
    char* pattern = params->pattern;

    while (true) {
        pthread_mutex_lock(&printing_mutex);
        if (is_printing) {
            pthread_mutex_unlock(&printing_mutex);
            usleep(100000);
            continue;
        } else {
            is_printing = true;
            pthread_mutex_unlock(&printing_mutex);
        }

        for (int i = i_start; i < i_end; i++) {
            for (int j = j_start; j < j_end; j++) {
                printf("%c ", pattern[(i+j)%strlen(pattern)]);
            }
            printf("\n");
        }

        pthread_mutex_lock(&printing_mutex);
        is_printing = false;
        pthread_mutex_unlock(&printing_mutex);
        break;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];
    PatternParams params[4];

    pthread_mutex_init(&printing_mutex, NULL);

    char pattern[] = "ASYNC C PATTERN PRINTING";
    int pattern_length = strlen(pattern);

    params[0].i_start = 0;
    params[0].i_end = 5;
    params[0].j_start = 0;
    params[0].j_end = 5;
    params[0].pattern = pattern;

    params[1].i_start = 5;
    params[1].i_end = 10;
    params[1].j_start = 0;
    params[1].j_end = 5;
    params[1].pattern = pattern;

    params[2].i_start = 0;
    params[2].i_end = 5;
    params[2].j_start = 5;
    params[2].j_end = 10;
    params[2].pattern = pattern;

    params[3].i_start = 5;
    params[3].i_end = 10;
    params[3].j_start = 5;
    params[3].j_end = 10;
    params[3].pattern = pattern;

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, print_pattern, &params[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&printing_mutex);

    return EXIT_SUCCESS;
}