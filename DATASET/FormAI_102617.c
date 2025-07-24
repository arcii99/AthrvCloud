//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <time.h>

#define MAX_THREADS 10
#define DOWNLOAD_SIZE 5000000 //5MB download size

void* download_speed_test(void* thread_id) {
    int id = *((int*) thread_id);
    float download_speed;
    clock_t start_time, end_time;
    
    start_time = clock();
    
    //Simulating a 5MB download
    char* download_data = (char*) malloc(DOWNLOAD_SIZE * sizeof(char));
    memset(download_data, 'A', DOWNLOAD_SIZE);
    end_time = clock();
    
    download_speed = DOWNLOAD_SIZE / ((float)(end_time - start_time) / CLOCKS_PER_SEC);
    
    printf("Download speed for thread %d: %.2f MB/s\n", id, download_speed / pow(10,6));
    free(download_data);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, download_speed_test, &thread_ids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }
    
    pthread_exit(NULL);
}