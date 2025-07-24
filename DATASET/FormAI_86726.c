//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
 
#define MAX_BAGS 10 // maximum number of bags per passenger
#define MAX_PASSENGERS 5 // maximum number of passengers in line
#define MAX_CONVEYOR 3 // maximum number of bags on the conveyor belt
 
sem_t conveyor_mutex; // semaphore to protect conveyor belt access
sem_t scanner_mutex; // semaphore to protect scanner access
sem_t loader_mutex; // semaphore to protect loader access
 
int conveyor[MAX_CONVEYOR]; // conveyor belt represented as a circular buffer
int head = 0;
int tail = 0;
 
int scanner = 0; // scanner can handle one bag at a time
 
int loader = 0; // loader can load one bag at a time
 
void* passenger(void* arg){
    int id = *(int*)arg;
    int num_bags = rand() % MAX_BAGS + 1;
    int bags[num_bags];
   
    printf("Passenger %d has %d bags\n", id, num_bags);
 
    for(int i = 0; i < num_bags; i++){
        bags[i] = rand() % 100 + 1;
    }
 
    // put bags on conveyor belt
    for(int i = 0; i < num_bags; i++){
        sem_wait(&conveyor_mutex);
       
        while((head + 1) % MAX_CONVEYOR == tail){ // conveyor is full
            printf("Conveyor belt is full, waiting for space...\n");
            sem_post(&conveyor_mutex);
            sleep(1);
            sem_wait(&conveyor_mutex);
        }
       
        conveyor[head] = bags[i];
        printf("Passenger %d puts bag %d on conveyor belt\n", id, bags[i]);
        head = (head + 1) % MAX_CONVEYOR;
       
        sem_post(&conveyor_mutex);
    }
 
    pthread_exit(NULL);
}
 
void* scanner_func(void* arg){
    while(1){
        sem_wait(&scanner_mutex);
       
        if(scanner == 0 && head != tail){ // conveyor not empty and scanner available
            scanner = conveyor[tail];
            printf("Scanner scanned bag %d\n", scanner);
            tail = (tail + 1) % MAX_CONVEYOR;
        }
       
        sem_post(&scanner_mutex);
        sleep(1); // scanning takes time
    }
}
 
void* loader_func(void* arg){
    while(1){
        sem_wait(&loader_mutex);
       
        if(loader == 0 && scanner != 0){ // scanner not empty and loader available
            loader = scanner;
            printf("Loader loaded bag %d onto plane\n", loader);
            scanner = 0;
        }
       
        sem_post(&loader_mutex);
        sleep(1); // loading takes time
    }
}
 
int main(){
    srand(time(NULL)); // seed random number generator with current time
   
    sem_init(&conveyor_mutex, 0, 1); // initialize semaphores
    sem_init(&scanner_mutex, 0, 1);
    sem_init(&loader_mutex, 0, 1);
 
    pthread_t tids[MAX_PASSENGERS];
    int ids[MAX_PASSENGERS];
 
    for(int i = 0; i < MAX_PASSENGERS; i++){
        ids[i] = i + 1;
        pthread_create(&tids[i], NULL, passenger, &ids[i]);
    }
 
    pthread_t scanner_tid;
    pthread_create(&scanner_tid, NULL, scanner_func, NULL);
 
    pthread_t loader_tid;
    pthread_create(&loader_tid, NULL, loader_func, NULL);
 
    for(int i = 0; i < MAX_PASSENGERS; i++){
        pthread_join(tids[i], NULL);
    }
 
    return 0;
}