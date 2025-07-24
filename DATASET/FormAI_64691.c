//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *recursive_fibonacci(void *param)
{
    int num = *(int *)param;
    int result;
    pthread_t tid1, tid2;
    int num1 = num-1, num2 = num-2;

    if(num == 0 || num == 1)
    {
        result = num;
    }
    else
    {
        pthread_create(&tid1, NULL, recursive_fibonacci, &num1);
        pthread_create(&tid2, NULL, recursive_fibonacci, &num2);

        void *res1, *res2;
        pthread_join(tid1, &res1);
        pthread_join(tid2, &res2);

        int fib1 = *(int *)res1;
        int fib2 = *(int *)res2;

        result = fib1 + fib2;
    }

    int *result_ptr = malloc(sizeof(int));
    *result_ptr = result;

    pthread_exit(result_ptr);
}

int main()
{
    int num;
    printf("Enter a number to calculate fibonacci series up to: ");
    scanf("%d", &num);

    printf("\nCalculating fibonacci series up to %d...\n", num);

    pthread_t tid;

    pthread_create(&tid, NULL, recursive_fibonacci, &num);

    void *res;
    pthread_join(tid, &res);

    int fib_num = *(int *)res;
    printf("\nThe %dth number in fibonacci series is %d.", num, fib_num);

    return 0;
}