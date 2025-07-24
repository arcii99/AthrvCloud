//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants for home devices
#define NUM_ROOMS 3
#define NUM_DOORS 6
#define NUM_LIGHTS 9
#define NUM_THERMOSTATS 3

// Define structure for each room in the house
typedef struct {
    bool isOccupied;
    int numLightsOn;
    int temperature;
    bool hasDoorOpen;
} Room;

// Function to turn on/off a light in a room
void toggleLight(Room* room, int lightNum, bool isOn) {
    if (isOn) {
        // Turn on light
        printf("Turning on light %d in room\n", lightNum);
        room->numLightsOn += 1;
    } else {
        // Turn off light
        printf("Turning off light %d in room\n", lightNum);
        room->numLightsOn -= 1;
    }
}

// Function to check if a room is too hot or cold
void checkTemperature(Room* room) {
    if (room->temperature < 68) {
        printf("Temperature in room is too low, turning up thermostat\n");
    } else if (room->temperature > 78) {
        printf("Temperature in room is too high, turning down thermostat\n");
    } else {
        printf("Temperature in room is just right\n");
    }
}

int main() {
    // Initialize rooms
    Room rooms[NUM_ROOMS];
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].isOccupied = false;
        rooms[i].numLightsOn = 0;
        rooms[i].temperature = 72;
        rooms[i].hasDoorOpen = false;
    }
    
    // Initialize doors
    bool doors[NUM_DOORS];
    for (int i = 0; i < NUM_DOORS; i++) {
        doors[i] = false;
    }
    
    // Initialize lights
    bool lights[NUM_LIGHTS];
    for (int i = 0; i < NUM_LIGHTS; i++) {
        lights[i] = false;
    }
    
    // Initialize thermostats
    int thermostats[NUM_THERMOSTATS];
    for (int i = 0; i < NUM_THERMOSTATS; i++) {
        thermostats[i] = 72;
    }
    
    // Simulation loop
    while (true) {
        // Check each room for occupancy and adjust lights/thermostat accordingly
        for (int i = 0; i < NUM_ROOMS; i++) {
            if (rooms[i].isOccupied) {
                // Turn on all lights in the room
                for (int j = i*3; j < i*3+3; j++) {
                    toggleLight(&rooms[i], j, true);
                    lights[j] = true;
                }
                // Check temperature in the room
                checkTemperature(&rooms[i]);
            } else {
                // Turn off all lights in the room
                for (int j = i*3; j < i*3+3; j++) {
                    toggleLight(&rooms[i], j, false);
                    lights[j] = false;
                }
                // Set thermostat in the room to default
                thermostats[i] = 72;
            }
        }
        
        // Check each door to see if it's open and turn on/off lights accordingly
        for (int i = 0; i < NUM_DOORS; i++) {
            if (doors[i]) {
                // Turn on light in corresponding room
                int roomNum = i / 2;
                int lightNum = (i % 2 == 0) ? (roomNum * 3) + 2 : (roomNum + 1) * 3 - 1;
                lights[lightNum] = true;
                toggleLight(&rooms[roomNum], lightNum, true);
                rooms[roomNum].hasDoorOpen = true;
            } else {
                // Turn off light in corresponding room
                int roomNum = i / 2;
                int lightNum = (i % 2 == 0) ? (roomNum * 3) + 2 : (roomNum + 1) * 3 - 1;
                lights[lightNum] = false;
                toggleLight(&rooms[roomNum], lightNum, false);
                rooms[roomNum].hasDoorOpen = false;
            }
        }
        
        // Check each thermostat and adjust temperature in corresponding room
        for (int i = 0; i < NUM_THERMOSTATS; i++) {
            int roomTemp = rooms[i].temperature;
            if (thermostats[i] > roomTemp) {
                rooms[i].temperature += 1;
            } else if (thermostats[i] < roomTemp) {
                rooms[i].temperature -= 1;
            }
        }
        
        // Wait one minute before continuing simulation
        printf("Simulation updating\n");
        sleep(60);
    }

    return 0;
}