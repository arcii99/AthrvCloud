//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// function to print the pattern asynchronously
void *print_pattern(void *arg) {
    int i, j;

    // iterate through each row of the pattern
    for (i = 1; i <= 5; i++) {
        // print the spaces before the pattern
        for (j = 1; j <= 5 - i; j++) {
            printf(" ");
        }

        // print the pattern
        for (j = 1; j <= i; j++) {
            printf("* ");
            fflush(stdout);
            sleep(1);
        }

        // move to the next line
        printf("\n");
    }

    return NULL;
}

int main() {
    pthread_t tid;

    // create the thread to print the pattern asynchronously
    if (pthread_create(&tid, NULL, print_pattern, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // wait for the thread to finish
    pthread_join(tid, NULL);

    return 0;
}