//FormAI DATASET v1.0 Category: Smart home light control ; Style: shape shifting
#include <stdio.h>
#include <string.h>

enum light_state {
    OFF,
    ON
};

struct light {
    char location[20];
    enum light_state state;
};

int main() {
    struct light kitchen_light;
    struct light living_room_light;
    struct light bedroom_light;

    // Initialize all lights to off
    kitchen_light.state = OFF;
    living_room_light.state = OFF;
    bedroom_light.state = OFF;

    // Display the current state of all lights
    printf("Current light state:\n");
    printf("Kitchen: %s\n", kitchen_light.state == OFF ? "Off" : "On");
    printf("Living room: %s\n", living_room_light.state == OFF ? "Off" : "On");
    printf("Bedroom: %s\n", bedroom_light.state == OFF ? "Off" : "On");

    // Turn on the kitchen light
    strcpy(kitchen_light.location, "Kitchen");
    kitchen_light.state = ON;
    printf("\n%s light turned on.\n\n", kitchen_light.location);

    // Display the current state of all lights
    printf("Current light state:\n");
    printf("Kitchen: %s\n", kitchen_light.state == OFF ? "Off" : "On");
    printf("Living room: %s\n", living_room_light.state == OFF ? "Off" : "On");
    printf("Bedroom: %s\n", bedroom_light.state == OFF ? "Off" : "On");

    // Turn off the kitchen light and turn on the living room light
    kitchen_light.state = OFF;
    strcpy(living_room_light.location, "Living room");
    living_room_light.state = ON;
    printf("%s light turned on, and %s light turned off.\n\n", living_room_light.location, kitchen_light.location);

    // Display the current state of all lights
    printf("Current light state:\n");
    printf("Kitchen: %s\n", kitchen_light.state == OFF ? "Off" : "On");
    printf("Living room: %s\n", living_room_light.state == OFF ? "Off" : "On");
    printf("Bedroom: %s\n", bedroom_light.state == OFF ? "Off" : "On");

    // turn on all the lights
    kitchen_light.state = ON;
    living_room_light.state = ON;
    strcpy(bedroom_light.location, "Bedroom");
    bedroom_light.state = ON;
    printf("All lights turned on.\n\n");

    // Display the current state of all lights
    printf("Current light state:\n");
    printf("Kitchen: %s\n", kitchen_light.state == OFF ? "Off" : "On");
    printf("Living room: %s\n", living_room_light.state == OFF ? "Off" : "On");
    printf("Bedroom: %s\n", bedroom_light.state == OFF ? "Off" : "On");

    return 0;
}