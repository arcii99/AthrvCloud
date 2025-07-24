//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

// traffic light status
enum LightStatus {
    GREEN,
    YELLOW,
    RED
};

// traffic light structure
struct TrafficLight {
    enum LightStatus status;
    int duration;
};

// function to initialize traffic light
void initTrafficLight(struct TrafficLight* light, enum LightStatus status, int duration) {
    light->status = status;
    light->duration = duration;
}

// function to update traffic light status and duration
void updateTrafficLight(struct TrafficLight* light, enum LightStatus newStatus, int newDuration) {
    light->status = newStatus;
    light->duration = newDuration;
}

int main() {
    // initialize traffic lights
    struct TrafficLight northLight, southLight, eastLight, westLight;
    initTrafficLight(&northLight, RED, 30);
    initTrafficLight(&southLight, RED, 30);
    initTrafficLight(&eastLight, GREEN, 20);
    initTrafficLight(&westLight, GREEN, 20);
    
    // loop to simulate traffic light control
    while (true) {
        printf("North-South: ");
        switch (northLight.status) {
            case GREEN:
                printf("Green\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case RED:
                printf("Red\n");
                break;
        }
        printf("East-West: ");
        switch (eastLight.status) {
            case GREEN:
                printf("Green\n");
                break;
            case YELLOW:
                printf("Yellow\n");
                break;
            case RED:
                printf("Red\n");
                break;
        }
        
        // update traffic light status and duration based on current status
        sleep(1); // pause for 1 second
        switch (northLight.status) {
            case GREEN:
                if (northLight.duration == 0) {
                    updateTrafficLight(&northLight, YELLOW, 5);
                    updateTrafficLight(&southLight, YELLOW, 5);
                    updateTrafficLight(&eastLight, RED, 1);
                    updateTrafficLight(&westLight, RED, 1);
                } else {
                    northLight.duration--;
                    southLight.duration--;
                }
                break;
            case YELLOW:
                if (northLight.duration == 0) {
                    updateTrafficLight(&northLight, RED, 30);
                    updateTrafficLight(&southLight, RED, 30);
                    updateTrafficLight(&eastLight, GREEN, 20);
                    updateTrafficLight(&westLight, GREEN, 20);
                } else {
                    northLight.duration--;
                    southLight.duration--;
                }
                break;
            case RED:
                if (northLight.duration == 0) {
                    updateTrafficLight(&northLight, GREEN, 20);
                    updateTrafficLight(&southLight, GREEN, 20);
                    updateTrafficLight(&eastLight, RED, 1);
                    updateTrafficLight(&westLight, RED, 1);
                } else {
                    northLight.duration--;
                    southLight.duration--;
                }
                break;
        }
        
        switch (eastLight.status) {
            case GREEN:
                if (eastLight.duration == 0) {
                    updateTrafficLight(&eastLight, YELLOW, 5);
                    updateTrafficLight(&westLight, YELLOW, 5);
                    updateTrafficLight(&northLight, RED, 1);
                    updateTrafficLight(&southLight, RED, 1);
                } else {
                    eastLight.duration--;
                    westLight.duration--;
                }
                break;
            case YELLOW:
                if (eastLight.duration == 0) {
                    updateTrafficLight(&eastLight, RED, 30);
                    updateTrafficLight(&westLight, RED, 30);
                    updateTrafficLight(&northLight, GREEN, 20);
                    updateTrafficLight(&southLight, GREEN, 20);
                } else {
                    eastLight.duration--;
                    westLight.duration--;
                }
                break;
            case RED:
                if (eastLight.duration == 0) {
                    updateTrafficLight(&eastLight, GREEN, 20);
                    updateTrafficLight(&westLight, GREEN, 20);
                    updateTrafficLight(&northLight, RED, 1);
                    updateTrafficLight(&southLight, RED, 1);
                } else {
                    eastLight.duration--;
                    westLight.duration--;
                }
                break;
        }
    }
    
    return 0;
}