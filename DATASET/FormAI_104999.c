//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ada Lovelace
// A multi-threaded program that calculates the factorial of a number.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *factorial(void *num) {
    int n = *(int*)num;
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
    }
    printf("Factorial of %d is %d\n", n, fact);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];
    int numbers[5] = {10, 8, 6, 4, 2};
    int rc;

    for (int i = 0; i < 5; i++) {
        rc = pthread_create(&threads[i], NULL, factorial, &numbers[i]);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}