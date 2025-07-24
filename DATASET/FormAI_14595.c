//FormAI DATASET v1.0 Category: System boot optimizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_THREADS 8

void *optimize(void *arg); // optimize function prototype
void reboot(); // reboot function prototype

int main() {
    pthread_t threads[MAX_THREADS]; // threads array
    int i;

    srand(time(NULL)); // seed the random number generator

    printf("Starting system boot optimizer...\n");

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, optimize, NULL); // create threads
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL); // wait for threads to finish
    }

    printf("System boot optimized successfully!\n");

    reboot(); // reboot the system

    return 0;
}

void *optimize(void *arg) {
    int sleep_time = rand() % 5 + 1; // generate random sleep time between 1 and 5 seconds

    printf("Thread %ld is optimizing system boot (%d seconds)...\n", pthread_self(), sleep_time);

    sleep(sleep_time); // sleep for random time

    printf("Thread %ld has finished optimizing system boot.\n", pthread_self());

    pthread_exit(NULL);
}

void reboot() {
    printf("Rebooting system...\n");

    // code to reboot the system

    printf("System rebooted successfully!\n");
}