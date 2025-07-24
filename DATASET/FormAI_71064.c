//FormAI DATASET v1.0 Category: Smart home light control ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS_PER_ROOM 10

typedef struct {
    int room_id;
    int light_id;
} Light;

int current_brightness[MAX_ROOMS][MAX_LIGHTS_PER_ROOM];
int current_on_state[MAX_ROOMS][MAX_LIGHTS_PER_ROOM];

void set_brightness(Light light, int brightness) {
    current_brightness[light.room_id][light.light_id] = brightness;
    printf("Light %d in room %d set to brightness %d\n", light.light_id, light.room_id, brightness);
}

void turn_on(Light light) {
    current_on_state[light.room_id][light.light_id] = 1;
    printf("Light %d in room %d turned on\n", light.light_id, light.room_id);
}

void turn_off(Light light) {
    current_on_state[light.room_id][light.light_id] = 0;
    printf("Light %d in room %d turned off\n", light.light_id, light.room_id);
}

int main() {
    // Initialize all lights to off and brightness 0
    memset(current_on_state, 0, sizeof(current_on_state));
    memset(current_brightness, 0, sizeof(current_brightness));

    // Example usage
    Light bedroom_lamp = {0, 0};
    turn_on(bedroom_lamp);
    set_brightness(bedroom_lamp, 50);

    Light kitchen_lamp = {1, 2};
    turn_on(kitchen_lamp);
    set_brightness(kitchen_lamp, 100);

    Light living_room_lamp = {2, 1};
    turn_on(living_room_lamp);
    set_brightness(living_room_lamp, 75);

    Light bathroom_lamp = {3, 6};
    turn_on(bathroom_lamp);
    set_brightness(bathroom_lamp, 25);

    Light office_lamp = {4, 5};
    turn_on(office_lamp);
    set_brightness(office_lamp, 90);

    // Turn off all lights
    for(int r = 0; r < MAX_ROOMS; r++) {
        for(int l = 0; l < MAX_LIGHTS_PER_ROOM; l++) {
            if(current_on_state[r][l]) {
                Light light = {r, l};
                turn_off(light);
            }
        }
    }

    return 0;
}