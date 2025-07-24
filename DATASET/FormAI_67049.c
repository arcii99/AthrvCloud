//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int fibo(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

void *thread_function_one(void *arg) {
    int *input = (int *) arg;
    printf("Thread 1 started...\n");
    int fibonacci = fibo(*input);
    printf("The %dth fibonacci number is: %d\n", *input, fibonacci);
    pthread_exit(NULL);
}

void *thread_function_two(void *arg) {
    int *input = (int *) arg;
    printf("Thread 2 started...\n");
    int result = 1;
    for (int i = 1; i <= *input; i++) {
        result *= i;
    }
    printf("The factorial of %d is: %d\n", *input, result);
    pthread_exit(NULL);
}

int main() {
    int input[SIZE] = {3, 5, 7, 10, 15, 20, 25, 30, 35, 40};
    pthread_t threads[SIZE];
    for (int i = 0; i < SIZE; i++) {
        int *ptr = &input[i];
        pthread_create(&threads[i], NULL, thread_function_one, (void *) ptr);
    }
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int i = 0; i < SIZE; i++) {
        int *ptr = &input[i];
        pthread_create(&threads[i], NULL, thread_function_two, (void *) ptr);
    }
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}