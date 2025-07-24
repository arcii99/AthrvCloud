//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fibonacci(void *arg)
{
    int n = *(int *)arg;
    int *f = (int*)malloc(sizeof(int));
    if (n == 0)
    {
        *f = 0;
    }
    else if (n == 1)
    {
        *f = 1;
    }
    else
    {  
        pthread_t thread1, thread2;

        int arg1 = n - 1;
        int arg2 = n - 2;

        pthread_create(&thread1, NULL, fibonacci, &arg1);
        pthread_create(&thread2, NULL, fibonacci, &arg2);

        int *f1, *f2;
        pthread_join(thread1, (void **)&f1);
        pthread_join(thread2, (void **)&f2);

        *f = *f1 + *f2;
        free(f1);
        free(f2);
    }

    pthread_exit(f);
}

int main()
{
    int n = 10;
    pthread_t thread;
    pthread_create(&thread, NULL, fibonacci, &n);

    int *fib;
    pthread_join(thread, (void **)&fib);

    printf("Fibonacci(%d) = %d\n", n, *fib);
    free(fib);

    return 0;
}