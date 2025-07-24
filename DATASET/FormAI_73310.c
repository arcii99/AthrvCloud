//FormAI DATASET v1.0 Category: Date and time ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

void *print_date(void *args);

int main() {
    pthread_t tid; // thread ID
    int rc; // return code
    struct timeval tv;

    rc = pthread_create(&tid, NULL, print_date, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    while (1) {
        gettimeofday(&tv, NULL);
        printf("Asynchronous time: %ld.%ld\n", tv.tv_sec, tv.tv_usec);
        sleep(1);
    }

    pthread_exit(NULL);
}

void *print_date(void *args) {
    while (1) {
        time_t current_time = time(NULL);
        char* c_time_string = ctime(&current_time);

        printf("Asynchronous date: %s", c_time_string);
        sleep(5);
    }
}