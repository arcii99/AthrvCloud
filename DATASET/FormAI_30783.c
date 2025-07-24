//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int fact(int n) { // factorial function
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

void* threadFunction(void* arg) { // thread function
    int n = *(int*) arg;
    int result = fact(n); // call factorial function
    printf("Factorial of %d is %d\n", n, result);
    pthread_exit(NULL); // exit thread
}

int main() {
    int num1 = 5, num2 = 6, num3 = 7;

    pthread_t threads[3]; // define threads
    int thread_args[3] = {num1, num2, num3}; // arguments for threads

    for (int i = 0; i < 3; i++) {
        int rc = pthread_create(&threads[i], NULL, threadFunction, (void*) &thread_args[i]); // create threads
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            return -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL); // wait for threads to finish
    }

    return 0;
}