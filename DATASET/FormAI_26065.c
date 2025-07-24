//FormAI DATASET v1.0 Category: Smart home light control ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for the different modes of the smart home light control system
#define MODE_OFF 0
#define MODE_ON 1
#define MODE_NIGHTLIGHT 2
#define MODE_AUTO 3

// Constants for the different bright level settings of the smart home light control system
#define BRIGHT_LOW 10
#define BRIGHT_MEDIUM 50
#define BRIGHT_HIGH 100

struct LightControlSystem {
    int mode;
    int brightLevel;
    int nightlightStart;
    int nightlightEnd;
    int motionDetected;
};

typedef struct LightControlSystem LightControl;

void setLightControlSystem(LightControl *system); 
void printLightControlSystem(LightControl *system); 
void lightOn(LightControl *system); 
void lightOff(LightControl *system); 
void setNightlightMode(LightControl *system); 
void setAutoMode(LightControl *system); 
void adjustBrightLevel(LightControl *system); 

int main() {
    LightControl system;
    setLightControlSystem(&system); 
    
    printf("Welcome to the smart home light control system.\n");
    printf("The current settings are:\n");
    printLightControlSystem(&system);
    
    while(1) {
        // Check for motion detected
        srand(time(NULL));
        int motion = rand() % 2; // simulate motion detected or not
        system.motionDetected = motion;
        
        if(system.mode == MODE_OFF) {
            printf("\nLight is off.\n");
        }
        else if(system.mode == MODE_ON) {
            printf("\nLight is on.\n");
            adjustBrightLevel(&system);
        }
        else if(system.mode == MODE_NIGHTLIGHT) {
            printf("\nNightlight mode is on.\n");
            if(system.motionDetected == 1) {
                lightOn(&system);
            }
        }
        else if(system.mode == MODE_AUTO) {
            printf("\nAuto mode is on.\n");
            if(system.motionDetected == 1) {
                lightOn(&system);
            }
            else {
                lightOff(&system);
            }
        }
        
        // Delay for animation purposes
        for(int i = 0; i < 100000000; i++) {}
    }
    
    return 0;
}

/**
 * Sets the initial values of the light control system.
 */
void setLightControlSystem(LightControl *system) {
    system->mode = MODE_AUTO;
    system->brightLevel = BRIGHT_LOW;
    system->nightlightStart = 20; // 8:00 pm
    system->nightlightEnd = 8; // 8:00 am
    system->motionDetected = 0;
}

/**
 * Prints the current settings of the light control system.
 */
void printLightControlSystem(LightControl *system) {
    printf("Mode: ");
    if(system->mode == MODE_OFF) {
        printf("Off\n");
    }
    else if(system->mode == MODE_ON) {
        printf("On\n");
    }
    else if(system->mode == MODE_NIGHTLIGHT) {
        printf("Nightlight\n");
        printf("Nightlight Start Time: %d:00 pm\n", system->nightlightStart);
        printf("Nightlight End Time: %d:00 am\n", system->nightlightEnd);
    }
    else if(system->mode == MODE_AUTO) {
        printf("Auto\n");
        printf("Nightlight Start Time: %d:00 pm\n", system->nightlightStart);
        printf("Nightlight End Time: %d:00 am\n", system->nightlightEnd);
    }
    
    printf("Brightness Level: %d%%\n", system->brightLevel);
}

/**
 * Turns on the light.
 */
void lightOn(LightControl *system) {
    printf("Light is turning on.\n");
}

/**
 * Turns off the light.
 */
void lightOff(LightControl *system) {
    printf("Light is turning off.\n");
}

/**
 * Sets the nightlight mode of the light control system.
 */
void setNightlightMode(LightControl *system) {
    printf("Setting nightlight mode.\n");
    system->mode = MODE_NIGHTLIGHT;
}

/**
 * Sets the auto mode of the light control system.
 */
void setAutoMode(LightControl *system) {
    printf("Setting auto mode.\n");
    system->mode = MODE_AUTO;
}

/**
 * Adjusts the brightness level based on the mode and time of day.
 */
void adjustBrightLevel(LightControl *system) {
    if(system->mode == MODE_NIGHTLIGHT) {
        printf("Setting brightness level to low for nightlight mode.\n");
        system->brightLevel = BRIGHT_LOW;
    }
    else if(system->mode == MODE_AUTO) {
        time_t now = time(NULL);
        struct tm *localTime = localtime(&now);
        int hour = localTime->tm_hour;
        
        if(hour >= system->nightlightStart || hour < system->nightlightEnd) {
            printf("Setting brightness level to low for night time.\n");
            system->brightLevel = BRIGHT_LOW;
        }
        else {
            printf("Setting brightness level to high for day time.\n");
            system->brightLevel = BRIGHT_HIGH;
        }
    }
    else {
        printf("Setting brightness level to high for on mode.\n");
        system->brightLevel = BRIGHT_HIGH;
    }
}