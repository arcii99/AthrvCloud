//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int intrusion_flag = 0; // global flag to indicate intrusion detected or not

void *intrusion_detection(void *arg) {
    int *data_ptr = (int *) arg;
    int current_value = *data_ptr;

    while(1) {
        if(current_value != *data_ptr) {
            printf("Intrusion detected!\n");
            intrusion_flag = 1; // set flag to indicate intrusion detected
            break;
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // seed the random generator

    int data = rand() % 10; // generate a random value between 0 and 9
    
    printf("Starting intrusion detection...\n");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, intrusion_detection, (void *) &data); // create thread for intrusion detection

    sleep(5); // wait for 5 seconds

    if(intrusion_flag == 0) {
        printf("No intrusion detected.\n");
    }

    return 0;
}