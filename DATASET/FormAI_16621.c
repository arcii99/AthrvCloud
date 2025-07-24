//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int factorial(int n);

int main()
{
    pthread_t thread_id;
    int num, result;
    
    printf("Enter a number to find its factorial: ");
    scanf("%d", &num);

    printf("\nCreating the thread...\n");

    if(pthread_create(&thread_id, NULL, (void *)factorial, (void *)&num) != 0)
    {
        printf("\nThread creation error!\n");
        exit(1);
    }

    printf("\nThe thread has been created successfully.\n");

    printf("\nWaiting for the factorial calculation to complete...\n");

    if(pthread_join(thread_id, (void **)&result) != 0)
    {
        printf("\nError joining the thread.\n");
        exit(1);
    }

    printf("\nFactorial of %d is: %d\n", num, result);

    return 0;
}

int factorial(int n)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}