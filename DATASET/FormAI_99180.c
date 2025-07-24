//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int first = 0, second = 1, count = 0;

void *fibonacci(void *arg) {
    int limit = *(int *) arg;
    int next, i;

    for (i = 0; i < limit; i++) {
        if (i <= 1) {
            next = i;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d\n", next);
        fflush(stdout);
        count++;
        usleep(2000000); // sleep for 2 seconds for visual effect
    }
    return NULL;
}

int main() {

    int limit;
    printf("Enter the limit of the Fibonacci Sequence: ");
    scanf("%d", &limit);

    pthread_t thread;
    pthread_create(&thread, NULL, fibonacci, &limit);

    while(count < limit) {
        char spinner[4] = { '|', '/', '-', '\\' }; // Spinner animation
        printf("\r%c", spinner[count%4]);
        fflush(stdout);
        usleep(100000);
    }

    pthread_join(thread, NULL); // Wait for thread to finish
    printf("\nFibonacci sequence generated successfully\n");

    return 0;
}