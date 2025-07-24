//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

int num;
int fib[100];

void *fibonacci(void *arg) {
    int n = *((int *) arg);
    fib[0] = 0;
    fib[1] = 1;
    for (int i=2; i<n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return NULL;
}

void *visualize(void *arg) {
    int n = *((int *) arg);
    for (int i=0; i<n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");
    return NULL;
}

int main() {
    printf("Enter the number of terms to generate: ");
    scanf("%d", &num);
    pthread_t tid1, tid2;
    pthread_attr_t attr1, attr2;

    pthread_attr_init(&attr1);
    pthread_create(&tid1, &attr1, fibonacci, &num);
    pthread_join(tid1, NULL);

    pthread_attr_init(&attr2);
    pthread_create(&tid2, &attr2, visualize, &num);
    pthread_join(tid2, NULL);

    return 0;
}