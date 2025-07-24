//FormAI DATASET v1.0 Category: Smart home light control ; Style: brave
#include <stdio.h>
#include <stdbool.h>

#define NUM_LIGHTS 5

bool lights[NUM_LIGHTS] = {false, false, false, false, false};

void printLights() {
    printf("Current light status:\n");
    for (int i = 0; i < NUM_LIGHTS; i++) {
        printf("Light %d is %s\n", i+1, lights[i] ? "ON" : "OFF");
    }
    printf("\n");
}

void toggleLight(int light_index) {
    if (light_index < 1 || light_index > NUM_LIGHTS) {
        printf("Invalid light index!\n");
        return;
    }
    lights[light_index-1] = !lights[light_index-1];
    printf("Light %d is now %s\n", light_index, lights[light_index-1] ? "ON" : "OFF");
}

int main() {
    printf("Brave Smart Home Light Control\n");
    printf("=============================\n\n");
    printf("Welcome to your Smart Home Light Control system!\n\n");

    printLights();

    toggleLight(1);

    toggleLight(3);

    toggleLight(5);

    printLights();
    
    return 0;
}