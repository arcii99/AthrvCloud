//FormAI DATASET v1.0 Category: Smart home automation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* temperature(void* arg) {
    int temp = 75;
    while(1) {
        printf("Temperature: %d\n", temp);
        sleep(5);
    }
    return NULL;
}

void* lights(void* arg) {
    int light = 0;
    while(1) {
        if (light == 0) {
            printf("Lights: Off\n");
            light = 1;
        } else {
            printf("Lights: On\n");
            light = 0;
        }
        sleep(2);
    }
    return NULL;
}

void* security(void* arg) {
    int alarm = 0;
    while(1) {
        if (alarm == 0) {
            printf("Security: Off\n");
            alarm = 1;
        } else {
            printf("Security: On\n");
            alarm = 0;
        }
        sleep(10);
    }
    return NULL;
}

int main() {
    pthread_t temp_thread, light_thread, security_thread;
    pthread_create(&temp_thread, NULL, temperature, NULL);
    pthread_create(&light_thread, NULL, lights, NULL);
    pthread_create(&security_thread, NULL, security, NULL);
    
    pthread_join(temp_thread, NULL);
    pthread_join(light_thread, NULL);
    pthread_join(security_thread, NULL);
    return 0;
}