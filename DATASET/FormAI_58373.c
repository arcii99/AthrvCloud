//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct light {
    bool state;         // ON/OFF boolean value
    char room[20];      // Room the light belongs to
};
 
void initialize_lights(struct light house[], int num_lights) {
    for (int i=0; i<num_lights; i++) {
        strcpy(house[i].room, "");
        house[i].state = false;
    }
}

void print_lights(struct light house[], int num_lights) {
    for (int i=0; i<num_lights; i++) {
        if (house[i].state)
            printf("The %s light is ON\n", house[i].room);
        else
            printf("The %s light is OFF\n", house[i].room);
    }
}

void change_light(struct light house[], int num_lights, char* room, bool newstate) {
    for (int i=0; i<num_lights; i++) {
        if (strcmp(house[i].room, room) == 0) {
            house[i].state = newstate;
            return;
        }
    }
}

int main(void) {
    int num_lights = 4;
    struct light house[4];

    initialize_lights(house, num_lights);

    strcpy(house[0].room, "Living Room");
    strcpy(house[1].room, "Bedroom");
    strcpy(house[2].room, "Kitchen");
    strcpy(house[3].room, "Bathroom");

    house[0].state = true;
    house[3].state = true;

    printf("Initial state of lights:\n");
    print_lights(house, num_lights);
 
    // Turn off Living Room light
    printf("\nTurning off the Living Room light...\n");
    change_light(house, num_lights, "Living Room", false);

    printf("State of lights after change:\n");
    print_lights(house, num_lights);

    // Turn on Bedroom light
    printf("\nTurning on the Bedroom light...\n");
    change_light(house, num_lights, "Bedroom", true);

    printf("State of lights after change:\n");
    print_lights(house, num_lights);

    // Turn off all lights
    printf("\nTurning off all lights...\n");
    for (int i=0; i<num_lights; i++)
        house[i].state = false;

    printf("State of lights after change:\n");
    print_lights(house, num_lights);

    return 0;
}