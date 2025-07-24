//FormAI DATASET v1.0 Category: Smart home light control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

// Light State
enum LightState {
    LIGHT_OFF,
    LIGHT_ON
};

// Light Data
struct LightData {
    int id;
    char name[50];
    enum LightState state;
};

// Update Light State
void updateLightState(struct LightData* light) {
    if (light->state == LIGHT_ON) {
        light->state = LIGHT_OFF;
        printf("%s turned OFF\n", light->name);
    } else {
        light->state = LIGHT_ON;
        printf("%s turned ON\n", light->name);
    }
}

// Timer Callback
void timerCallback(int signal) {
    srand(time(NULL));
    int randomNum = rand() % 10 + 1;
    if (randomNum % 2 == 0) {
        printf("Error: Failed to communicate with device\n");
    } else {
        struct LightData* light1 = (struct LightData*)malloc(sizeof(struct LightData));
        light1->id = 1;
        sprintf(light1->name, "Living Room Light %d", light1->id);
        light1->state = LIGHT_OFF;
        updateLightState(light1);
        free(light1);

        struct LightData* light2 = (struct LightData*)malloc(sizeof(struct LightData));
        light2->id = 1;
        sprintf(light2->name, "Bedroom Light %d", light2->id);
        light2->state = LIGHT_ON;
        updateLightState(light2);
        free(light2);
    }
}

int main() {
    // Setup Timer
    signal(SIGALRM, timerCallback);
    time_t startTime = time(NULL);
    alarm(5);

    // Loop Forever
    while (1) {
        // Do Nothing
    }
    return 0;
}