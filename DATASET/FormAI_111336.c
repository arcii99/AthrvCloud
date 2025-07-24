//FormAI DATASET v1.0 Category: Smart home automation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define LIVING_ROOM 1
#define BEDROOM 2
#define KITCHEN 3
#define BATHROOM 4

bool isMotionDetected(int room) {
    // simulate random motion detection
    int rand_num = rand() % 10;
    return (rand_num > 5);
}

bool isLightOn(int room) {
    // simulate getting light status from smart home system
    return (rand() % 2 == 0);
}

void turnOnLight(int room) {
    // simulate sending command to turn on light
    printf("Turning on light in room %d\n", room);
    sleep(2);
}

void turnOffLight(int room) {
    // simulate sending command to turn off light
    printf("Turning off light in room %d\n", room);
    sleep(2);
}

int main() {
    srand(time(NULL));
    int timer = 0;
    bool isLivingRoomOccupied = false;
    bool isBedRoomOccupied = false;
    bool isKitchenOccupied = false;
    bool isBathroomOccupied = false;
    bool isLightLivingRoomOn = false;
    bool isLightBedRoomOn = false;
    bool isLightKitchenOn = false;
    bool isLightBathroomOn = false;
    while (1) {
        printf("Timer: %d\n", timer);
        if (isMotionDetected(LIVING_ROOM)) {
            isLivingRoomOccupied = true;
        } else {
            isLivingRoomOccupied = false;
        }
        if (isMotionDetected(BEDROOM)) {
            isBedRoomOccupied = true;
        } else {
            isBedRoomOccupied = false;
        }
        if (isMotionDetected(KITCHEN)) {
            isKitchenOccupied = true;
        } else {
            isKitchenOccupied = false;
        }
        if (isMotionDetected(BATHROOM)) {
            isBathroomOccupied = true;
        } else {
            isBathroomOccupied = false;
        }
        if (isLivingRoomOccupied && !isLightLivingRoomOn) {
            turnOnLight(LIVING_ROOM);
            isLightLivingRoomOn = true;
        } else if (!isLivingRoomOccupied && isLightLivingRoomOn) {
            turnOffLight(LIVING_ROOM);
            isLightLivingRoomOn = false;
        }

        if (isBedRoomOccupied && !isLightBedRoomOn) {
            turnOnLight(BEDROOM);
            isLightBedRoomOn = true;
        } else if (!isBedRoomOccupied && isLightBedRoomOn) {
            turnOffLight(BEDROOM);
            isLightBedRoomOn = false;
        }

        if (isKitchenOccupied && !isLightKitchenOn) {
            turnOnLight(KITCHEN);
            isLightKitchenOn = true;
        } else if (!isKitchenOccupied && isLightKitchenOn) {
            turnOffLight(KITCHEN);
            isLightKitchenOn = false;
        }

        if (isBathroomOccupied && !isLightBathroomOn) {
            turnOnLight(BATHROOM);
            isLightBathroomOn = true;
        } else if (!isBathroomOccupied && isLightBathroomOn) {
            turnOffLight(BATHROOM);
            isLightBathroomOn = false; 
        }
        timer++;
        sleep(1);
    }
    return 0;
}