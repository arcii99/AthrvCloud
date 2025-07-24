//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multi-threaded
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>

#define MAX_BUFF_SIZE 50
#define MAX_THREADS 5

char buffer[MAX_BUFF_SIZE]; // Shared buffer
int readIndex = 0; 
int writeIndex = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t bufferNotFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t bufferNotEmpty = PTHREAD_COND_INITIALIZER;

bool isAttackDetected = false;
int attackCounter = 0;

/* Function to detect intrusion */
bool detectIntrusion(char* str) {
    if (strstr(str, "attack")) {
        return true;
    }
    return false;
}

/* Function for the writer thread */
void* writerThread(void* arg) {
    while (true) {
        /* Critical section */
        pthread_mutex_lock(&mutex);
        if (writeIndex < MAX_BUFF_SIZE) {
            printf("Enter message to be logged: ");
            fgets(&buffer[writeIndex], MAX_BUFF_SIZE - writeIndex, stdin);
            writeIndex += strlen(&buffer[writeIndex]);
            if (detectIntrusion(&buffer[writeIndex - strlen(&buffer[writeIndex])])) {
                isAttackDetected = true;
                printf("------------------------\n");
                printf("Intrusion Detected!\n");
                printf("------------------------\n");
                attackCounter++;
            }
            pthread_cond_signal(&bufferNotEmpty);
        } else {
            printf("Buffer Full - No writing\n");
            pthread_cond_wait(&bufferNotFull, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        usleep(100000); // Sleep for 100 ms
    }
    return NULL;
}

/* Function for the reader thread */
void* readerThread(void* arg) {
    while (true) {
        /* Critical section */
        pthread_mutex_lock(&mutex);
        if (readIndex != writeIndex) {
            printf("Log Message: %s", &buffer[readIndex]);
            readIndex += strlen(&buffer[readIndex]);
            pthread_cond_signal(&bufferNotFull);
        } else {
            if (isAttackDetected) {
                printf("Attacks Detected: %d\n", attackCounter);
                isAttackDetected = false;
            }
            pthread_cond_wait(&bufferNotEmpty, &mutex);
        }
        pthread_mutex_unlock(&mutex);
        usleep(100000); // Sleep for 100 ms
    }
    return NULL;
}

int main(void) {
    pthread_t threadID[MAX_THREADS];
    int i;

    /* Create threads */
    if(pthread_create(&threadID[0], NULL, writerThread, NULL)!= 0){
        fprintf(stderr, "Error in creating thread 0\n");
        return EXIT_FAILURE;
    }
    if(pthread_create(&threadID[1], NULL, readerThread, NULL)!= 0){
        fprintf(stderr, "Error in creating thread 1\n");
        return EXIT_FAILURE;
    }

    /* Join threads */
    for(i=0; i<MAX_THREADS; i++){
        if(pthread_join(threadID[i], NULL)!=0){
            fprintf(stderr, "Error in joining thread %d\n", i);
        }
    }
    return EXIT_SUCCESS;
}