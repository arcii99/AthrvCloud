//FormAI DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *calculate_average(void *arg);
void *calculate_sum(void *arg);

int arr[5] = {1, 2, 3, 4, 5};
int sum = 0;
float avg;

int main()
{
    pthread_t tid1, tid2;
    
    pthread_create(&tid1, NULL, calculate_sum, NULL);
    pthread_create(&tid2, NULL, calculate_average, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    printf("Sum of array elements: %d\n", sum);
    printf("Average of array elements: %.2f\n", avg);
    
    return 0;
}

void *calculate_sum(void *arg)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        sum += arr[i];
    }
    pthread_exit(NULL);
}

void *calculate_average(void *arg)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        avg += arr[i];
    }
    avg = avg / 5;
    pthread_exit(NULL);
}