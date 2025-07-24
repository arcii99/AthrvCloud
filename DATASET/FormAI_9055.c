//FormAI DATASET v1.0 Category: Smart home automation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main() {
    int living_room_temp = 70; // temperature in Fahrenheit
    int bedroom_temp = 65; // temperature in Fahrenheit
    int kitchen_lights = 0; // indicates if the lights in the kitchen are on or off
    int living_room_lights = 0; // indicates if the lights in the living room are on or off
    int bedroom_lights = 0; // indicates if the lights in the bedroom are on or off

    printf("Welcome to your smart home!\n");

    // turning on the lights in the living room
    printf("\nTurning on the lights in the living room...\n");
    living_room_lights = 1;
    printf("Living room lights are now on\n");

    // turning on the lights in the kitchen if it's dark outside and nobody is in
    int dark_outside = 1; // boolean, 1 if it's dark outside, 0 if it's light outside
    int nobody_home = 1; // boolean, 1 if nobody is home, 0 if somebody is home
    
    if (dark_outside && nobody_home) {
        printf("\nTurning on the lights in the kitchen...\n");
        kitchen_lights = 1;
        printf("Kitchen lights are now on\n");
    } else {
        printf("\nNo need to turn on the lights in the kitchen\n");
    }

    // turning on the lights in the bedroom if the temperature is below 68 degrees Fahrenheit
    if (bedroom_temp < 68) {
        printf("\nTurning on the lights in the bedroom...\n");
        bedroom_lights = 1;
        printf("Bedroom lights are now on\n");
    } else {
        printf("\nNo need to turn on the lights in the bedroom\n");
    }

    // increasing the temperature in the living room by 5 degrees Fahrenheit
    printf("\nIncreasing the temperature in the living room...\n");
    living_room_temp += 5;
    printf("Living room temperature is now %d degrees Fahrenheit\n", living_room_temp);

    return 0;
}