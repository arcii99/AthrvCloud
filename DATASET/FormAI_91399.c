//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *addition(void *arg);
void *subtraction(void *arg);

int main()
{
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Initialize thread ids
    pthread_t tid1, tid2;
    
    // Create threads for addition and subtraction
    pthread_create(&tid1, NULL, addition, (void *) &num1);
    pthread_create(&tid2, NULL, subtraction, (void *) &num2);

    // Wait for threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

void *addition(void *arg)
{
    int num = *((int *) arg);
    int result = num + num;

    printf("The sum of %d and %d is %d\n", num, num, result);

    pthread_exit(NULL);
}

void *subtraction(void *arg)
{
    int num = *((int *) arg);
    int result = num - num;

    printf("The difference of %d and %d is %d\n", num, num, result);

    pthread_exit(NULL);
}