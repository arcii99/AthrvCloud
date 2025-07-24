//FormAI DATASET v1.0 Category: Smart home automation ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// The number of rooms in the house
#define NUM_ROOMS 5

// Structure for a room in the house
typedef struct {
    int roomID;
    bool lightOn;
    bool doorOpen;
    int temperature;
} Room;

// Function to randomly generate room data
Room generateRoomData(int roomID) {
    Room newRoom;
    newRoom.roomID = roomID;
    newRoom.lightOn = rand() % 2 == 0 ? true : false;
    newRoom.doorOpen = rand() % 2 == 0 ? true : false;
    newRoom.temperature = rand() % 30 + 10; // Temperature between 10 and 40 degrees Celsius
    return newRoom;
}

// Function to print the current state of the house
void printHouse(Room house[], int numRooms) {
    printf("Current state of the house:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d:\n", house[i].roomID + 1);
        printf("   Light: %s\n", house[i].lightOn ? "On" : "Off");
        printf("   Door: %s\n", house[i].doorOpen ? "Open" : "Closed");
        printf("   Temperature: %d degrees Celsius\n", house[i].temperature);
    }
}

// Function to turn the lights on or off in a room
void toggleLights(Room *room) {
    room->lightOn = !room->lightOn;
    printf("Lights in Room %d are now %s\n", room->roomID + 1, room->lightOn ? "On" : "Off");
}

// Function to open or close the door in a room
void toggleDoor(Room *room) {
    room->doorOpen = !room->doorOpen;
    printf("Door in Room %d is now %s\n", room->roomID + 1, room->doorOpen ? "Open" : "Closed");
}

// Function to adjust the temperature in a room
void adjustTemperature(Room *room, int newTemp) {
    room->temperature = newTemp;
    printf("Temperature in Room %d is now %d degrees Celsius\n", room->roomID + 1, room->temperature);
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Create an array of Room structures and populate with random data
    Room house[NUM_ROOMS];
    for (int i = 0; i < NUM_ROOMS; i++) {
        house[i] = generateRoomData(i);
    }
    
    // Print the initial state of the house
    printHouse(house, NUM_ROOMS);
    
    // Toggle the lights in Room 3 and adjust the temperature in Room 5
    toggleLights(&house[2]);
    adjustTemperature(&house[4], 23);
    
    // Print the updated state of the house
    printHouse(house, NUM_ROOMS);
    
    // Toggle the door in Room 2 and adjust the temperature in Room 1
    toggleDoor(&house[1]);
    adjustTemperature(&house[0], 20);
    
    // Print the final state of the house
    printHouse(house, NUM_ROOMS);
    
    return 0;
}