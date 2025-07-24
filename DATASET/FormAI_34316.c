//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *browser_plugin(void *arg) {
    printf("Executing browser plugin...\n");
    sleep(1);
    printf("Browser plugin executed successfully!\n");
    pthread_exit(NULL); // exit current thread
}

int main() {
    pthread_t thread;
    int ret;

    printf("Creating browser plugin...\n");
    ret = pthread_create(&thread, NULL, browser_plugin, NULL); // create new thread
    if (ret != 0) { // check if thread creation failed
        printf("Error creating thread.\n");
        exit(1);
    }

    printf("Waiting for browser plugin to complete...\n");
    pthread_join(thread, NULL); // wait for thread to complete

    printf("Exiting program...\n");
    pthread_exit(NULL); // exit main thread
}