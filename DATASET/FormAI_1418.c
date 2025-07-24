//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool on;
    int brightness;
    int temperature;
} Light;

void turn_on(Light* light) {
    light->on = true;
}

void turn_off(Light* light) {
    light->on = false;
}

void set_brightness(Light* light, int brightness) {
    if (brightness < 0) {
        printf("Error: brightness cannot be negative\n");
    } else if (brightness > 100) {
        printf("Error: brightness cannot be greater than 100\n");
    } else {
        light->brightness = brightness;
    }
}

void set_temperature(Light* light, int temperature) {
    if (temperature < 2000) {
        printf("Error: temperature cannot be less than 2000K\n");
    } else if (temperature > 7000) {
        printf("Error: temperature cannot be greater than 7000K\n");
    } else {
        light->temperature = temperature;
    }
}

void print_status(Light* light) {
    printf("Light is %s\n", light->on ? "on" : "off");
    printf("Brightness is %d%%\n", light->brightness);
    printf("Temperature is %dK\n", light->temperature);
}

int main() {
    Light kitchen_light = {false, 0, 3000};
    Light living_room_light = {false, 0, 3500};
    Light bedroom_light = {false, 0, 4000};

    turn_on(&kitchen_light);
    set_brightness(&kitchen_light, 80);
    set_temperature(&kitchen_light, 3200);
    print_status(&kitchen_light);

    turn_on(&living_room_light);
    set_brightness(&living_room_light, 50);
    set_temperature(&living_room_light, 4000);
    print_status(&living_room_light);

    turn_on(&bedroom_light);
    set_brightness(&bedroom_light, 100);
    set_temperature(&bedroom_light, 4500);
    print_status(&bedroom_light);

    turn_off(&kitchen_light);
    turn_off(&living_room_light);
    turn_off(&bedroom_light);
    
    return 0;
}