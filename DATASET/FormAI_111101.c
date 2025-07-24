//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
int red, yellow, green;

void *trafficController(void *arg) {
    while(1) {
        pthread_mutex_lock(&mutex);

        if(green) {
            printf("Green Light is ON\n");
            sleep(5);
            green = 0;
            yellow = 1;
        }
        else if(yellow) {
            printf("Yellow Light is ON\n");
            sleep(2);
            yellow = 0;
            red = 1;
        }
        else if(red) {
            printf("Red Light is ON\n");
            sleep(5);
            red = 0;
            green = 1;
        }

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {

    pthread_t t1;

    red = 0, yellow = 0, green = 1;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&t1, NULL, trafficController, NULL);

    pthread_join(t1, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}