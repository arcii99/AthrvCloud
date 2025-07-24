//FormAI DATASET v1.0 Category: Math exercise ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
#define MAX 1000
 
int sum[4] = {0}; // Sum of elements in each thread
 
// Function to generate random numbers
void *runner(void *param) {
    int start = *((int *) param);
    int end = start + MAX/4;
    int i, s = 0;
    for(i = start; i < end; i++) {
        s += rand() % 10;
    }
    sum[start/250] = s;
    pthread_exit(0);
}
 
int main(int argc, char *argv[]) {
 
    pthread_t thread[4];
    int start[4], i, j, total = 0;
 
    // Initialize random seed
    srand(time(NULL));
 
    // Create four threads
    for(i = 0; i < 4; i++) {
        start[i] = i * MAX/4;
        pthread_create(&thread[i], NULL, runner, &start[i]);
    }
 
    // Join four threads
    for(i = 0; i < 4; i++) {
        pthread_join(thread[i], NULL);
        total += sum[i];
    }
 
    // Print results
    printf("Sum of %d random numbers is: %d\n", MAX, total);
 
    return 0;
}