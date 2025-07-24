//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;  // Variable to store the sum

void *calculate_sum(void *arg)
{
    int *arr = (int *)arg; // Typecasting the void* argument to integer pointer
    for(int i=0; i<5; i++)
    {
        sum += arr[i];  // Adding the values of the array to the sum
    }
    pthread_exit(NULL);  // Exiting the thread
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    pthread_t thread_id; // Creating a thread object

    pthread_create(&thread_id, NULL, calculate_sum, (void *)arr); // Creating a thread and passing the integer array as argument

    pthread_join(thread_id, NULL);  // Joining the thread to the main thread

    printf("The sum of the array is: %d", sum); // Printing the sum

    return 0;
}