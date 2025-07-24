//FormAI DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdbool.h>

void turnOnLight(int lightID) {
    printf("Light %d turned on.\n", lightID);
}

void turnOffLight(int lightID) {
    printf("Light %d turned off.\n", lightID);
}

void lockDoor(int doorID) {
    printf("Door %d locked.\n", doorID);
}

void unlockDoor(int doorID) {
    printf("Door %d unlocked.\n", doorID);
}

void playMusic(const char* musicTitle) {
    printf("Playing %s...\n", musicTitle);
}

void stopMusic() {
    printf("Music stopped.\n");
}

int main() {
    bool isHome = false;
    bool isDaylight = true;
    bool isBurglarDetected = false;
    int light1ID = 1;
    int light2ID = 2;
    int doorID = 1;
    const char* welcomeMusic = "Welcome to my home!";
    
    printf("Smart home automation\n");
    printf("=====================\n");
    
    // Going home
    printf("Going home...\n");
    isHome = true;
    if(isDaylight) {
        turnOffLight(light1ID);
        turnOnLight(light2ID);
    } else {
        turnOnLight(light1ID);
        turnOffLight(light2ID);
    }
    playMusic(welcomeMusic);
    
    // Leaving home
    printf("Leaving home...\n");
    isHome = false;
    stopMusic();
    if(isBurglarDetected) {
        lockDoor(doorID);
        turnOnLight(light1ID);
        turnOnLight(light2ID);
    } else {
        unlockDoor(doorID);
        turnOffLight(light1ID);
        turnOffLight(light2ID);
    }
    
    return 0;
}