//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// global variable
volatile int poison_pill = 0;

void* juliet(void* arg) {
    int* num = (int*) arg;
    printf("Juliet: My love, please come to the balcony!\n");
    while (poison_pill != 1) {
        printf("Juliet: Waiting for my love to arrive...\n");
        sleep(3);
    }
    printf("Juliet: My love has arrived! Let's talk!\n");
    pthread_exit(NULL);
}

void* romeo(void* arg) {
    int* num = (int*) arg;
    printf("Romeo: My love, I have arrived at the foot of your balcony!\n");
    sleep(3);
    printf("Romeo: Why are you not responding, my love?\n");
    sleep(3);
    printf("Romeo: Oh no, she must be sleeping!\n");
    printf("Romeo: Leaving a message for my love...\n");
    poison_pill = 1;
    pthread_exit(NULL);
}

int main() {
    pthread_t juliet_thread, romeo_thread;
    int rc;
    printf("Scene 1: Romeo wants to talk to Juliet...\n");

    rc = pthread_create(&juliet_thread, NULL, juliet, NULL);
    if (rc) {
        printf("Error creating Juliet thread! Return code: %d", rc);
        exit(-1);
    }

    rc = pthread_create(&romeo_thread, NULL, romeo, NULL);
    if (rc) {
        printf("Error creating Romeo thread! Return code: %d", rc);
        exit(-1);
    }

    pthread_join(juliet_thread, NULL);
    pthread_join(romeo_thread, NULL);
    
    printf("Scene 2: Romeo leaves...\n");
    return 0;
}