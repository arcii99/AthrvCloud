//FormAI DATASET v1.0 Category: Smart home automation ; Style: optimized
#include <stdio.h>
#include <string.h>

#define ROOMS 3
#define DEVICES 4

int main() {
    int i, j, state[ROOMS][DEVICES];
    char room_names[ROOMS][20] = {"Living Room", "Bedroom", "Kitchen"};
    char device_names[DEVICES][20] = {"Lights", "AC", "TV", "Music System"};

    // Initialize all devices to be turned off
    for (i = 0; i < ROOMS; i++) {
        for (j = 0; j < DEVICES; j++) {
            state[i][j] = 0;
        }
    }

    // Display initial state of devices
    printf("Initial state:\n");
    for (i = 0; i < ROOMS; i++) {
        printf("%s:\n", room_names[i]);
        for (j = 0; j < DEVICES; j++) {
            printf("%s: %s\n", device_names[j], (state[i][j] == 1) ? "On" : "Off");
        }
        printf("\n");
    }

    // Turn on all lights in the living room
    int living_room = 0;
    int lights_device = 0;
    state[living_room][lights_device] = 1;

    // Turn on AC in the bedroom
    int bedroom = 1;
    int ac_device = 1;
    state[bedroom][ac_device] = 1;

    // Turn on music system and TV in the living room
    int music_system_device = 3;
    int tv_device = 2;
    state[living_room][music_system_device] = 1;
    state[living_room][tv_device] = 1;

    // Display final state of devices
    printf("Final state:\n");
    for (i = 0; i < ROOMS; i++) {
        printf("%s:\n", room_names[i]);
        for (j = 0; j < DEVICES; j++) {
            printf("%s: %s\n", device_names[j], (state[i][j] == 1) ? "On" : "Off");
        }
        printf("\n");
    }

    return 0;
}