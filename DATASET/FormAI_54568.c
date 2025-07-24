//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

bool is_light_on = false;
bool is_power_on = false;
bool is_door_locked = true;

pthread_mutex_t mutex;

void* light_thread(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (is_power_on && is_door_locked) {
            if (is_light_on) {
                printf("Turning off the light\n");
                is_light_on = false;
            } else {
                printf("Turning on the light\n");
                is_light_on = true;
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void* power_thread(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (is_power_on) {
            printf("Turning off power\n");
            is_power_on = false;
        } else {
            printf("Turning on power\n");
            is_power_on = true;
        }
        pthread_mutex_unlock(&mutex);
        sleep(5);
    }
}

void* door_thread(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        if (is_power_on) {
            if (is_door_locked) {
                printf("Unlocking the door\n");
                is_door_locked = false;
            } else {
                printf("Locking the door\n");
                is_door_locked = true;
            }
        }
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

int main() {
    pthread_t light_t, power_t, door_t;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&light_t, NULL, light_thread, NULL);
    pthread_create(&power_t, NULL, power_thread, NULL);
    pthread_create(&door_t, NULL, door_thread, NULL);
    pthread_join(light_t, NULL);
    pthread_join(power_t, NULL);
    pthread_join(door_t, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}