//FormAI DATASET v1.0 Category: Temperature monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 100
#define TEMP_THRESHOLD 25.0

struct Room {
    int id;
    float temp;
};

struct Room rooms[MAX_ROOMS];

void initRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].id = i + 1;
        rooms[i].temp = 0.0;
    }
}

void updateRoomTemps() {
    srand(time(NULL)); // Seed the random number generator with current time
    for (int i = 0; i < MAX_ROOMS; i++) {
        float tempChange = (rand() % 11) / 10.0 - 0.5; // Generate a random float between -0.5 and 0.5
        rooms[i].temp += tempChange;
    }
}

void checkTempThreshold() {
    int numOfRoomsExceedingThreshold = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].temp > TEMP_THRESHOLD) {
            numOfRoomsExceedingThreshold++;
            printf("Room %d exceeded temperature threshold with temperature %f.\n", rooms[i].id, rooms[i].temp);
        }
    }
    if (numOfRoomsExceedingThreshold == 0) {
        printf("All rooms are within safe temperature levels.\n");
    }
}

int main() {
    initRooms();
    int numOfUpdates = 5;
    for (int i = 1; i <= numOfUpdates; i++) {
        printf("Temperature Update #%d\n", i);
        updateRoomTemps();
        checkTempThreshold();
        printf("\n");
    }
    return 0;
}