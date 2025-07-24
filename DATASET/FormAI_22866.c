//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

bool lights_on = false;
bool fan_on = false;
bool ac_on = false;

void* checkTemp(void* arg) {
    while(true) {
        int temp = rand() % 50 + 50;
        if(temp > 75 && !ac_on) {
            printf("Temperature above 75 degrees celsius. Turning on AC.\n");
            ac_on = true;
        }
        else if(temp <= 75 && ac_on) {
            printf("Temperature below 75 degrees celsius. Turning off AC.\n");
            ac_on = false;
        }
        sleep(1);
    }
}

void* checkLight(void* arg) {
    while(true) {
        int light = rand() % 1000 + 1;
        if(light < 500 && !lights_on) {
            printf("Light intensity below 500 units. Turning on lights.\n");
            lights_on = true;
        }
        else if(light >= 500 && lights_on) {
            printf("Light intensity above 500 units. Turning off lights.\n");
            lights_on = false;
        }
        sleep(1);
    }
}

void* checkFan(void* arg) {
    while(true) {
        int temp = rand() % 50 + 50;
        int fan_speed = rand() % 4 + 1;
        if(temp > 70 && !fan_on) {
            printf("Temperature above 70 degrees celsius. Turning on fan at speed %d.\n", fan_speed);
            fan_on = true;
        }
        else if(temp <= 70 && fan_on) {
            printf("Temperature below 70 degrees celsius. Turning off fan.\n");
            fan_on = false;
        }
        sleep(1);
    }
}

int main() {

    pthread_t temp_thread, light_thread, fan_thread;

    srand(time(NULL));  // For random temperature, light and fan speed values

    pthread_create(&temp_thread, NULL, checkTemp, NULL);
    pthread_create(&light_thread, NULL, checkLight, NULL);
    pthread_create(&fan_thread, NULL, checkFan, NULL);

    pthread_join(temp_thread, NULL);
    pthread_join(light_thread, NULL);
    pthread_join(fan_thread, NULL);

    return 0;
}