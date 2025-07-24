//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void recursive_function(int n)
{
    if(n<=1)
        printf("%d ",n);
    else
    {
        printf("%d ",n);
        pthread_t thread_id1, thread_id2;
        pthread_create(&thread_id1, NULL, (void *)recursive_function, (void *)(n-1));
        pthread_create(&thread_id2, NULL, (void *)recursive_function, (void *)(n-2));
        pthread_join(thread_id1, NULL);
        pthread_join(thread_id2, NULL);
    }
}

int main()
{
    int n;
    printf("Enter a positive number: ");
    scanf("%d",&n);
    if(n<0)
    {
        printf("Invalid input. Please enter a positive integer.");
        return 0;
    }
    printf("Series of numbers: ");
    recursive_function(n);
    return 0;
}