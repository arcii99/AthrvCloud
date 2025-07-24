//FormAI DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Decentralized Smart Home Automation

// define struct for each room in the home
typedef struct room {
    int light_status; // 0 for off, 1 for on
    int temperature; // temperature in Fahrenheit
    int aircon_status; // 0 for off, 1 for on
    int window_status; // 0 for closed, 1 for open
} Room;

// function to turn on/off lights
void switch_light(Room *r, int status) {
    if (status == 1) {
        printf("Turning on lights...\n");
        r->light_status = 1;
    } else if (status == 0) {
        printf("Turning off lights...\n");
        r->light_status = 0;
    } else {
        printf("Invalid status.\n");
    }
}

// function to set room temperature
void set_temperature(Room *r, int temp) {
    printf("Setting temperature to %d F...\n", temp);
    r->temperature = temp;
}

// function to turn on/off air conditioner
void switch_aircon(Room *r, int status) {
    if (status == 1) {
        printf("Turning on aircon...\n");
        r->aircon_status = 1;
    } else if (status == 0) {
        printf("Turning off aircon...\n");
        r->aircon_status = 0;
    } else {
        printf("Invalid status.\n");
    }
}

// function to open/close window
void switch_window(Room *r, int status) {
    if (status == 1) {
        printf("Opening window...\n");
        r->window_status = 1;
    } else if (status == 0) {
        printf("Closing window...\n");
        r->window_status = 0;
    } else {
        printf("Invalid status.\n");
    }
}

int main() {
    // create rooms
    Room living_room = {0, 72, 0, 0};
    Room kitchen = {0, 68, 1, 1};
    Room bedroom = {1, 70, 1, 0};

    // interact with rooms
    switch_light(&living_room, 1);
    switch_light(&bedroom, 0);
    set_temperature(&kitchen, 72);
    switch_aircon(&living_room, 1);
    switch_window(&bedroom, 1);

    return 0;
}