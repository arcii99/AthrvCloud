//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

#define NUM_OF_LIGHTS 10
#define MAX_NAME_LENGTH 25

struct Light {
    char name[MAX_NAME_LENGTH];
    bool status;
    int brightness;
};

struct SmartHome {
    struct Light lights[NUM_OF_LIGHTS];
};

void turn_on(struct SmartHome* home, char* name) {
    for(int i = 0; i < NUM_OF_LIGHTS; i++) {
        if(strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].status = true;
            printf("%s turned on\n", name);
            return;
        }
    }
    printf("%s not found\n", name);
}

void turn_off(struct SmartHome* home, char* name) {
    for(int i = 0; i < NUM_OF_LIGHTS; i++) {
        if(strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].status = false;
            printf("%s turned off\n", name);
            return;
        }
    }
    printf("%s not found\n", name);
}

void set_brightness(struct SmartHome* home, char* name, int brightness) {
    for(int i = 0; i < NUM_OF_LIGHTS; i++) {
        if(strcmp(home->lights[i].name, name) == 0) {
            home->lights[i].brightness = brightness;
            printf("%s brightness set to %d\n", name, home->lights[i].brightness);
            return;
        }
    }
    printf("%s not found\n", name);
}

int main() {
    struct Light living_room = {"Living Room Light", true, 50};
    struct Light kitchen = {"Kitchen Light", false, 0};
    struct Light bedroom = {"Bedroom Light", true, 75};
    struct Light bathroom = {"Bathroom Light", true, 25};
    struct Light hallway = {"Hallway Light", false, 0};

    struct SmartHome home = {{living_room, kitchen, bedroom, bathroom, hallway}};

    turn_on(&home, "Living Room Light");
    turn_on(&home, "Bathroom Light");
    turn_off(&home, "Hallway Light");
    set_brightness(&home, "Bedroom Light", 100);
    set_brightness(&home, "Bathroom Light", 50);

    return 0;
}