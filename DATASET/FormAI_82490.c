//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 10

int buffer[MAX_BUFFER_SIZE];
int index = 0;
int readIndex = 0;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; // initialize mutex lock variable

void* writer(void* arg){
    int num = *(int*)arg;
    for(int i=0; i<5; i++){
        pthread_mutex_lock(&lock);
        if(index < MAX_BUFFER_SIZE){
            buffer[index++] = num; // add to buffer
            printf("Writing %d to buffer...\n", num);
        } else{
            printf("Buffer full, cannot write.\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // wait for 1 second
    }
    return NULL;
}

void* reader(void* arg){
    int id = *(int*)arg;
    int readBuffer[MAX_BUFFER_SIZE]; // create a temp buffer
    int tempIndex = 0; // initialize temp buffer index
    for(int i=0; i<5; i++){
        pthread_mutex_lock(&lock);
        if(readIndex < index){
            readBuffer[tempIndex++] = buffer[readIndex++]; // read from buffer
            printf("Reader %d read value %d from buffer.\n", id, readBuffer[tempIndex-1]);
        } else{
            printf("Buffer empty, cannot read.\n");
        }
        pthread_mutex_unlock(&lock);
        sleep(2); // wait for 2 seconds
    }
    printf("Reader %d read values: ", id);
    for(int i=0; i<tempIndex; i++){
        printf("%d ", readBuffer[i]); // print values read from buffer
    }
    printf("\n");
    return NULL;
}

int main(){
    pthread_t writerThreads[3], readerThreads[2];
    int writerIds[3] = {1, 2, 3};
    int readerIds[2] = {1, 2};
    for(int i=0; i<3; i++){
        pthread_create(&writerThreads[i], NULL, writer, &writerIds[i]); // create writer threads
    }
    for(int i=0; i<2; i++){
        pthread_create(&readerThreads[i], NULL, reader, &readerIds[i]); // create reader threads
    }
    for(int i=0; i<3; i++){
        pthread_join(writerThreads[i], NULL); // wait for writer threads to finish
    }
    for(int i=0; i<2; i++){
        pthread_join(readerThreads[i], NULL); // wait for reader threads to finish
    }
    return 0;
}