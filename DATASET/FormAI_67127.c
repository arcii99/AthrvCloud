//FormAI DATASET v1.0 Category: Smart home automation ; Style: asynchronous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Define the state of the lights
bool livingRoomLightON = true;
bool bedroomLightON = false;
bool bathRoomLightON = false;
bool kitchenLightON = true;

pthread_mutex_t lock;

void toggleLivingRoomLight() {
    if(pthread_mutex_lock(&lock) == 0) {
        livingRoomLightON = !livingRoomLightON;
        printf("Living room light is now %s\n", livingRoomLightON ? "ON" : "OFF");
        pthread_mutex_unlock(&lock);
    }
}

void toggleBedroomLight() {
    if(pthread_mutex_lock(&lock) == 0) {
        bedroomLightON = !bedroomLightON;
        printf("Bedroom light is now %s\n", bedroomLightON ? "ON" : "OFF");
        pthread_mutex_unlock(&lock);
    }
}

void toggleBathRoomLight() {
    if(pthread_mutex_lock(&lock) == 0) {
        bathRoomLightON = !bathRoomLightON;
        printf("Bathroom light is now %s\n", bathRoomLightON ? "ON" : "OFF");
        pthread_mutex_unlock(&lock);
    }
}

void toggleKitchenLight() {
    if(pthread_mutex_lock(&lock) == 0) {
        kitchenLightON = !kitchenLightON;
        printf("Kitchen light is now %s\n", kitchenLightON ? "ON" : "OFF");
        pthread_mutex_unlock(&lock);
    }
}

// Some random code to simulate user actions
void* simulateUserActions(void* arg) {
    int i;
    for (i = 0; i < 10; i++) {
        usleep(500000);
        toggleLivingRoomLight();
        usleep(500000);
        toggleBedroomLight();
        usleep(500000);
        toggleBathRoomLight();
        usleep(500000);
        toggleKitchenLight();
    }
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_mutex_init(&lock, NULL);

    // Spawn a thread to simulate user actions
    pthread_create(&tid, NULL, &simulateUserActions, NULL);

    // Main program loop that runs smart home automation
    while (true) {
        usleep(300000);
        if (livingRoomLightON == true && bedroomLightON == false && bathRoomLightON == false && kitchenLightON == true) {
            printf("Smart automation mode is ON\n");
        } else {
            printf("Smart automation mode is OFF\n");
        }
    }

    // Clean up the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}