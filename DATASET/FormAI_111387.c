//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4 //Number of threads to be created

//Threads will execute this function that prints the thread number
void *printThreadNumber(void *threadNumber){
    int tn = *(int*)threadNumber; //Cast the thread number to an int

    //Print the thread number
    printf("Thread %d executing...\n", tn);

    pthread_exit(NULL); //Exit the thread
}

int main(){
    pthread_t threads[NUM_THREADS]; //Array to hold thread IDs
    int thread_args[NUM_THREADS]; //Array to hold thread arguments
    int result_code, i;

    //Create all threads
    for(i=0; i<NUM_THREADS; i++){
        thread_args[i] = i; //Store thread number in argument array
        result_code = pthread_create(&threads[i], NULL, printThreadNumber, &thread_args[i]); //Create thread
        if(result_code){
            printf("Error creating thread %d. Return code: %d\n", i, result_code);
            exit(EXIT_FAILURE);
        }
    }
    
    //Join all threads
    for(i=0; i<NUM_THREADS; i++){
        result_code = pthread_join(threads[i], NULL); //Join thread
        if(result_code){
            printf("Error joining thread %d. Return code: %d\n", i, result_code);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads executed successfully. Exiting program...\n");

    pthread_exit(NULL); //Exit main thread
}