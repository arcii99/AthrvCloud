//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 4

int temperature = 24;
bool light_on = false;
bool alarm_on = false;
pthread_mutex_t mutex;

void *temperature_sensor(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        int random_number = rand() % 3;
        temperature += random_number - 1; 
        printf("Temperature: %d\n", temperature);
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
}

void *light_controller(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (temperature >= 23 && temperature <= 27) {
            light_on = false;
            printf("Light turned off.\n");
        } else {
            light_on = true;
            printf("Light turned on.\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(10);
    }
}

void *motion_detector(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (light_on && !alarm_on) {
            printf("Intruder detected. Alarm turned on.\n");
            alarm_on = true;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *alarm_controller(void *arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (alarm_on) {
            printf("Alarm is ringing.\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    pthread_mutex_init(&mutex, NULL);

    rc = pthread_create(&threads[0], NULL, temperature_sensor, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[1], NULL, light_controller, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[2], NULL, motion_detector, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    rc = pthread_create(&threads[3], NULL, alarm_controller, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }

    pthread_exit(NULL);
    pthread_mutex_destroy(&mutex);
}