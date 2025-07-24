//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* addition(void* arg);

int main()
{
    int num1, num2, *res;
    pthread_t thread;
    
    printf("Enter two numbers to add: ");
    scanf("%d %d", &num1, &num2);
    
    if(pthread_create(&thread, NULL, addition, &num1)) //Check for thread creation error
    {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }
    
    if(pthread_join(thread, (void**)&res)) //Check for thread join error
    {
        fprintf(stderr, "Error joining thread\n");
        return 2;
    }

    printf("The sum is: %d\n", *res);
    free(res);
    
    return 0;
}

void* addition(void* arg)
{
    int num = *(int*)arg;
    int *result = malloc(sizeof(int));
    if(result == NULL) //Check for memory allocation error
    {
        fprintf(stderr, "Error allocating memory\n");
        exit(EXIT_FAILURE);
    }
    *result = num + 5;
    pthread_exit(result);
}