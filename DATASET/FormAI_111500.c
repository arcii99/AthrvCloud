//FormAI DATASET v1.0 Category: Smart home light control ; Style: Ada Lovelace
#include <stdio.h>
#include <stdbool.h>

// Function to turn on the lights
void turnOnLights() {
    printf("Lights turned on!\n");
}

// Function to turn off the lights
void turnOffLights() {
    printf("Lights turned off!\n");
}

// Function to check if it's daytime
bool isDaytime(int time) {
    return (time >= 6 && time < 18);
}

// Function to check if the room is occupied
bool isRoomOccupied(bool sensor) {
    return sensor;
}

int main() {
    int time = 12; // Current time in hours (24-hour format)
    bool roomOccupied = true; // True if someone is in the room, false otherwise
    bool lightOn = false; // True if the light is on, false otherwise

    printf("Smart home light control program\n");
    printf("Current time: %d:00\n", time);

    // Check if it's daytime and the room is occupied
    if (isDaytime(time) && isRoomOccupied(roomOccupied)) {
        if (!lightOn) {
            turnOnLights();
            lightOn = true;
        }
    } else { // It's either nighttime or the room is unoccupied
        if (lightOn) {
            turnOffLights();
            lightOn = false;
        }
    }

    return 0;
}