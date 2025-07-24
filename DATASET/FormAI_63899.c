//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <string.h>

typedef enum {
    OFF = 0,
    ON = 1,
    DIMMED = 2
} LightState;

typedef struct {
    char* name;
    LightState state;
    int brightness;
} Light;

typedef struct {
    int numLights;
    Light* lights;
} Room;

void printRoom(Room room) {
    printf("Room has %d lights:\n", room.numLights);
    for (int i = 0; i < room.numLights; i++) {
        Light light = room.lights[i];
        printf("%s: ", light.name);
        if (light.state == OFF) {
            printf("off\n");
        } else if (light.state == ON) {
            printf("on\n");
        } else if (light.state == DIMMED) {
            printf("dimmed to %d%%\n", light.brightness);
        }
    }
}

void turnOn(Room room, char* lightName) {
    for (int i = 0; i < room.numLights; i++) {
        Light light = room.lights[i];
        if (strcmp(light.name, lightName) == 0) {
            light.state = ON;
            room.lights[i] = light;
            printf("%s has been turned on.\n", lightName);
            return;
        }
    }
    printf("Could not find light '%s'.\n", lightName);
}

void turnOff(Room room, char* lightName) {
    for (int i = 0; i < room.numLights; i++) {
        Light light = room.lights[i];
        if (strcmp(light.name, lightName) == 0) {
            light.state = OFF;
            room.lights[i] = light;
            printf("%s has been turned off.\n", lightName);
            return;
        }
    }
    printf("Could not find light '%s'.\n", lightName);
}

void dim(Room room, char* lightName, int percent) {
    for (int i = 0; i < room.numLights; i++) {
        Light light = room.lights[i];
        if (strcmp(light.name, lightName) == 0) {
            if (percent < 0 || percent > 100) {
                printf("Invalid brightness level '%d'. Must be between 0 and 100.\n", percent);
                return;
            }
            light.state = DIMMED;
            light.brightness = percent;
            room.lights[i] = light;
            printf("%s has been dimmed to %d%%.\n", lightName, percent);
            return;
        }
    }
    printf("Could not find light '%s'.\n", lightName);
}

int main() {
    Light livingRoomLights[] = {
        { .name = "couch lamp", .state = OFF, .brightness = 0 },
        { .name = "overhead light", .state = OFF, .brightness = 0 }
    };
    Room livingRoom = { .numLights = 2, .lights = livingRoomLights };
    
    turnOn(livingRoom, "couch lamp");
    dim(livingRoom, "overhead light", 50);
    turnOff(livingRoom, "couch lamp");
    
    printRoom(livingRoom);

    return 0;
}