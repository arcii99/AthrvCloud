//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

long long fib[MAX_SIZE];
int size;
int index = 0;

void* fibonacci(void* arg) {
    int i = 0;
    long long curr, prev1 = 1, prev2 = 0;
    while (i < size) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
        fib[i++] = curr;
        index = i;
    }
    pthread_exit(NULL);
}

int main() {
    printf("Enter the size of the Fibonacci sequence: ");
    scanf("%d", &size);
    if (size <= 0 || size > MAX_SIZE) {
        printf("Error: invalid size input\n");
        return 1;
    }

    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int creation_status = pthread_create(&tid, &attr, fibonacci, NULL);
    if (creation_status) {
        printf("Error: unable to create thread, status %d\n", creation_status);
        return 1;
    }

    pthread_join(tid, NULL);

    printf("Fibonacci sequence:\n");
    for (int i = 0; i < index; i++) {
        printf("%lld ", fib[i]);
    }
    printf("\n");

    pthread_attr_destroy(&attr);
    pthread_exit(NULL);
    return 0;
}