//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* sum_thread(void* arg){
    int* arr = (int*) arg;
    int local_sum = 0;

    // Calculate the local sum
    for (int i = 0; i < 5; i++){
        local_sum += arr[i];
    }

    // Lock the mutex before updating the global sum
    pthread_mutex_lock(&mutex);

    // Update the global sum
    sum += local_sum;

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main(){
    // Create an array of integers
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create two threads
    pthread_t thread1, thread2;

    // Create arguments for the threads
    int arg1[5] = {1, 2, 3, 4, 5};
    int arg2[5] = {6, 7, 8, 9, 10};

    // Calculate the sum of the first half of the array in thread 1
    pthread_create(&thread1, NULL, sum_thread, (void*)arg1);

    // Calculate the sum of the second half of the array in thread 2
    pthread_create(&thread2, NULL, sum_thread, (void*)arg2);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the final sum
    printf("The sum of the array is %d\n", sum);

    return 0;
}