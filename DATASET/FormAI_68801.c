//FormAI DATASET v1.0 Category: Smart home light control ; Style: light-weight
#include <stdio.h>

#define LIGHT_OFF 0
#define LIGHT_ON 1

int main(){
    int livingRoomLight = LIGHT_OFF;
    int bedroomLight = LIGHT_ON;

    printf("Living Room Light is %s\n", livingRoomLight == LIGHT_ON ? "ON" : "OFF");
    printf("Bedroom Light is %s\n", bedroomLight == LIGHT_ON ? "ON" : "OFF");

    // Turn off Living Room Light
    livingRoomLight = LIGHT_OFF;
    printf("Living Room Light turned %s\n", livingRoomLight == LIGHT_ON ? "ON" : "OFF");

    // Turn on Living Room Light and Bedroom Light
    livingRoomLight = LIGHT_ON;
    bedroomLight = LIGHT_ON;
    printf("Living Room Light turned %s\n", livingRoomLight == LIGHT_ON ? "ON" : "OFF");
    printf("Bedroom Light turned %s\n", bedroomLight == LIGHT_ON ? "ON" : "OFF");
    
    return 0;
}