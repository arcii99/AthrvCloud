//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <pthread.h>

// A structure to hold data that will be passed to threads
typedef struct {
    char* message;
    int number;
} ThreadData;

// Function to be executed by threads
void* printThreadData(void* data) {
    ThreadData* threadData = (ThreadData*) data;
    printf("%d: %s\n", threadData->number, threadData->message);
    pthread_exit(NULL);
}

int main() {
    // Create an array of thread data
    ThreadData threadDataArr[3] = {
        {"Hello", 1},
        {"world", 2},
        {"!", 3}
    };
    
    // Create an array of threads
    pthread_t threadArr[3];
    
    // Create threads with respective data
    for (int i = 0; i < 3; i++) {
        pthread_create(&threadArr[i], NULL, printThreadData, (void*) &threadDataArr[i]);
    }
    
    // Wait for threads to complete
    for (int i = 0; i < 3; i++) {
        pthread_join(threadArr[i], NULL);
    }
    
    return 0;
}