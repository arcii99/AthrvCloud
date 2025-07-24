//FormAI DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_LIGHTS 20

// Struct to represent a Light
typedef struct {
    char name[20];
    int brightness;
    int state;
} Light;

// Struct to represent a Room
typedef struct {
    char name[20];
    Light lights[MAX_LIGHTS];
    int num_lights;
} Room;

// Function to turn ON or OFF a light
void toggle_light(Light* light, int state) {
    if (state) {
        printf("Turning ON light %s\n", light->name);
        light->state = 1;
        light->brightness = 100;
    } else {
        printf("Turning OFF light %s\n", light->name);
        light->state = 0;
        light->brightness = 0;
    }
}

// Function to change brightness of a light
void change_brightness(Light* light, int brightness) {
    printf("Changing brightness of light %s to %d\n", light->name, brightness);
    light->brightness = brightness;
    light->state = (brightness > 0) ? 1 : 0;
}

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 0;

    // Adding a Room
    Room living_room;
    strcpy(living_room.name, "Living Room");

    // Adding Lights to the Room
    Light lr_light1;
    strcpy(lr_light1.name, "Living Room Light 1");
    lr_light1.brightness = 0;
    lr_light1.state = 0;
    
    Light lr_light2;
    strcpy(lr_light2.name, "Living Room Light 2");
    lr_light2.brightness = 0;
    lr_light2.state = 0;
    
    living_room.lights[0] = lr_light1;
    living_room.lights[1] = lr_light2;
    living_room.num_lights = 2;

    // Adding Room to Home
    rooms[num_rooms++] = living_room;

    // Turning ON Light
    toggle_light(&living_room.lights[0], 1);
    toggle_light(&living_room.lights[1], 1);

    // Changing Brightness of Light
    change_brightness(&living_room.lights[0], 50);
    change_brightness(&living_room.lights[1], 75);

    // Turning OFF Light
    toggle_light(&living_room.lights[0], 0);
    toggle_light(&living_room.lights[1], 0);

    return 0;
}