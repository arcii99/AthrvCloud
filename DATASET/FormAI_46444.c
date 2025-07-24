//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LIGHTS 10 // maximum number of lights in the smart home system

// Function to randomly generate a brightness level between 0 and 100
int random_brightness() {
    return (rand() % 101);
}

// Function to turn on a light and set its brightness
void turn_on_light(int light_id, int brightness) {
    printf("Turning on Light %d with brightness %d\n", light_id, brightness);
    // Code to turn on the light and set its brightness would be here
}

// Function to turn off a light
void turn_off_light(int light_id) {
    printf("Turning off Light %d\n", light_id);
    // Code to turn off the light would be here
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    
    bool light_status[MAX_LIGHTS] = {false}; // Array to keep track of light status (on/off)
    int brightness_levels[MAX_LIGHTS] = {0}; // Array to keep track of brightness levels for each light
    
    // Simulate a smart home system by turning on and off lights randomly
    for (int i = 0; i < 1000; i++) {
        int light_id = rand() % MAX_LIGHTS;
        bool light_on = light_status[light_id];
        
        // If light is already on, turn it off with 50% probability
        if (light_on) {
            if ((rand() % 2) == 0) {
                light_status[light_id] = false;
                turn_off_light(light_id);
            }
        }
        // If light is off, turn it on with random brightness level
        else {
            int brightness = random_brightness();
            light_status[light_id] = true;
            brightness_levels[light_id] = brightness;
            turn_on_light(light_id, brightness);
        }
    }
    
    return 0;
}