//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 1000 //Size of the array
#define THREADS 5 //Number of threads to use

int array[SIZE]; //Global array to be searched
int target; //Global target to search for
int found = 0; //Global flag to indicate if target found
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //Mutex for critical section

//Thread function to search for target in array
void *search(void *args){
    int index = *(int *)args; //Cast argument to int pointer and dereference
    int start = index*(SIZE/THREADS); //Calculate start index for current thread
    int end = start + (SIZE/THREADS); //Calculate end index for current thread

    pthread_mutex_lock(&mutex); //Lock critical section
    printf("Thread %d searching from index %d to %d\n", index, start, end-1);
    pthread_mutex_unlock(&mutex); //Unlock critical section

    for(int i=start; i<end; i++){
        if(array[i] == target){ //If target found, set found flag and exit thread
            found = 1;
            pthread_mutex_lock(&mutex); //Lock critical section
            printf("Thread %d found target at index %d\n", index, i);
            pthread_mutex_unlock(&mutex); //Unlock critical section
            pthread_exit(NULL);
        }
    }

    pthread_mutex_lock(&mutex); //Lock critical section
    printf("Thread %d did not find target\n", index);
    pthread_mutex_unlock(&mutex); //Unlock critical section
    pthread_exit(NULL);
}

int main(){
    srand(time(NULL)); //Seed random number generator
    for(int i=0; i<SIZE; i++){ //Initialize array with random values
        array[i] = rand() % SIZE;
    }

    printf("Enter target value: ");
    scanf("%d", &target);

    pthread_t threads[THREADS]; //Array to hold thread IDs

    for(int i=0; i<THREADS; i++){ //Create and start threads
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&threads[i], NULL, search, arg);
    }

    for(int i=0; i<THREADS; i++){ //Wait for threads to finish
        pthread_join(threads[i], NULL);
    }

    if(found == 1){ //If target found, print message
        printf("Target found\n");
    }
    else{ //If target not found, print message
        printf("Target not found\n");
    }

    return 0;
}