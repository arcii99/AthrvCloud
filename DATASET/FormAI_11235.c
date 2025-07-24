//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_LUGGAGE 500
#define MAX_THREADS 50

sem_t conveyor_mutex; // semaphore for conveyor protection
sem_t scanner_mutex; // semaphore for scanner protection
sem_t counter_mutex; // semaphore for counter protection

sem_t conveyor_full; // semaphore for conveyor full state
sem_t scanner_empty; // semaphore for scanner empty state
sem_t counter_empty; // semaphore for counter empty state

int conveyor_jobs = 0; // counter for jobs on conveyor belt
int counter_jobs = 0; // counter for jobs at counter
int scanner_jobs = 0; // counter for jobs on scanner

void* scanner(void* arg){
    while(1){
        sem_wait(&scanner_empty); //wait for a job to arrive on the scanner
        sem_wait(&scanner_mutex); //get access to scanner

        //process job
        printf("Scanning job %d\n",scanner_jobs);
        scanner_jobs++;

        sem_post(&scanner_mutex); // release scanner
        sem_post(&conveyor_full); // signal the arrival of a new job on the conveyor belt
    }
}

void* counter(void* arg){
    while(1){
        sem_wait(&counter_empty); //wait for a job to arrive at the counter
        sem_wait(&counter_mutex); //get access to counter

        //process job
        printf("Counting job %d\n",counter_jobs);
        counter_jobs++;

        sem_post(&counter_mutex); //release counter
    }
}

void* conveyor_belt(void* arg){

    int* luggage = (int*)arg; // assign arrgument to and array of luggage

    int i=0;

    while(luggage[i] != -1){ // while we have luggage in the array
        sem_wait(&conveyor_full); //wait for space on the conveyor

        sem_wait(&conveyor_mutex); // get access to the conveyor

        //process job
        printf("Moving luggage %d on conveyor\n",luggage[i]);

        sem_post(&conveyor_mutex); // release the conveyor
        sem_post(&scanner_empty);  // signal the arrival of a new job on the scanner
        sem_post(&counter_empty);  // signal the arrival of a new job on the counter

        i++; // move to the next luggage item
    }

    pthread_exit(NULL); // exit thread on completion
}

int main(){

    sem_init(&conveyor_mutex,0,1); // init mutex
    sem_init(&scanner_mutex,0,1); // init mutex
    sem_init(&counter_mutex,0,1); // init mutex

    sem_init(&conveyor_full,0,MAX_LUGGAGE); // init semaphore
    sem_init(&scanner_empty,0,0); // init semaphore
    sem_init(&counter_empty,0,0); // init semaphore

    int luggage[MAX_LUGGAGE]; // array of luggage items

    for(int i=0;i<MAX_LUGGAGE-1;i++){ // fill the array with luggage
        luggage[i] = i+1;
    }

    luggage[MAX_LUGGAGE-1] = -1; // set the last element to be the terminator 

    pthread_t threads[MAX_THREADS]; // array of threads
    
    // create the threads 
    pthread_create(&threads[0],NULL,scanner,NULL);
    pthread_create(&threads[1],NULL,counter,NULL);
    pthread_create(&threads[2],NULL,conveyor_belt,luggage);

    // wait for the threads to terminate
    for(int i=0;i<3;i++){
        pthread_join(threads[i],NULL);
    }

    sem_destroy(&conveyor_mutex); // destroy mutex
    sem_destroy(&scanner_mutex); // destroy mutex
    sem_destroy(&counter_mutex); // destroy mutex

    sem_destroy(&conveyor_full); // destroy semaphore
    sem_destroy(&scanner_empty); // destroy semaphore
    sem_destroy(&counter_empty); // destroy semaphore

    return 0;
}