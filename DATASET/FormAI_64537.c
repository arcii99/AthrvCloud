//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Light {
    char* name;
    bool isOn;
    int brightness;
};

struct LightGroup {
    char* name;
    struct Light** lights;
    int numLights;
};

void printLight(struct Light* light) {
    printf("%s is %s and has brightness level %d\n", light->name, light->isOn ? "on" : "off", light->brightness);
}

void printGroup(struct LightGroup* group) {
    printf("Group %s contains:\n", group->name);
    for(int i = 0; i < group->numLights; i++) {
        printLight(group->lights[i]);
    }
}

int main() {

    struct Light* livingRoomLight = (struct Light*) malloc(sizeof(struct Light));
    livingRoomLight->name = "Living Room Light";
    livingRoomLight->isOn = false;
    livingRoomLight->brightness = 0;

    struct Light* kitchenLight = (struct Light*) malloc(sizeof(struct Light));
    kitchenLight->name = "Kitchen Light";
    kitchenLight->isOn = false;
    kitchenLight->brightness = 0;

    struct Light* bedroomLight = (struct Light*) malloc(sizeof(struct Light));
    bedroomLight->name = "Bedroom Light";
    bedroomLight->isOn = false;
    bedroomLight->brightness = 0;

    struct Light* bathroomLight = (struct Light*) malloc(sizeof(struct Light));
    bathroomLight->name = "Bathroom Light";
    bathroomLight->isOn = false;
    bathroomLight->brightness = 0;

    struct Light* garageLight = (struct Light*) malloc(sizeof(struct Light));
    garageLight->name = "Garage Light";
    garageLight->isOn = false;
    garageLight->brightness = 0;

    struct LightGroup* livingRoomGroup = (struct LightGroup*) malloc(sizeof(struct LightGroup));
    livingRoomGroup->name = "Living Room";
    livingRoomGroup->lights = (struct Light**) malloc(sizeof(struct Light*)*1);
    livingRoomGroup->lights[0] = livingRoomLight;
    livingRoomGroup->numLights = 1;

    struct LightGroup* kitchenGroup = (struct LightGroup*) malloc(sizeof(struct LightGroup));
    kitchenGroup->name = "Kitchen";
    kitchenGroup->lights = (struct Light**) malloc(sizeof(struct Light*)*1);
    kitchenGroup->lights[0] = kitchenLight;
    kitchenGroup->numLights = 1;

    struct LightGroup* bedroomGroup = (struct LightGroup*) malloc(sizeof(struct LightGroup));
    bedroomGroup->name = "Bedroom";
    bedroomGroup->lights = (struct Light**) malloc(sizeof(struct Light*)*1);
    bedroomGroup->lights[0] = bedroomLight;
    bedroomGroup->numLights = 1;

    struct LightGroup* bathroomGroup = (struct LightGroup*) malloc(sizeof(struct LightGroup));
    bathroomGroup->name = "Bathroom";
    bathroomGroup->lights = (struct Light**) malloc(sizeof(struct Light*)*1);
    bathroomGroup->lights[0] = bathroomLight;
    bathroomGroup->numLights = 1;

    struct LightGroup* garageGroup = (struct LightGroup*) malloc(sizeof(struct LightGroup));
    garageGroup->name = "Garage";
    garageGroup->lights = (struct Light**) malloc(sizeof(struct Light*)*1);
    garageGroup->lights[0] = garageLight;
    garageGroup->numLights = 1;

    char option[100];
    while(strcmp(option, "exit") != 0) {
        printf("Enter a command (e.g. 'turn on bedroom light'): \n");
        fgets(option, 100, stdin);

        char *ptr = strtok(option, " ");
        char* command = NULL;
        char* groupName = NULL;
        char* lightName = NULL;

        while(ptr != NULL) {
            if(!command) {
                command = ptr;
            } else if(!groupName) {
                groupName = ptr;
            } else if(!lightName) {
                lightName = ptr;
            }
            ptr = strtok(NULL, " ");
        }

        if(strcmp(command, "turn") == 0) {
            ptr = strtok(NULL, " ");
            if(!ptr) {
                printf("Please specify an on/off state\n");
                continue;
            }
            bool value = strcmp(ptr, "on") == 0;
            if(!groupName || !lightName) {
                printf("Please specify group and light names\n");
                continue;
            }

            if(strcmp(groupName, "living") == 0 && strcmp(lightName, "room") == 0) {
                livingRoomLight->isOn = value;
            } else if(strcmp(groupName, "kitchen") == 0 && strcmp(lightName, "light") == 0) {
                kitchenLight->isOn = value;
            } else if(strcmp(groupName, "bedroom") == 0 && strcmp(lightName, "light") == 0) {
                bedroomLight->isOn = value;
            } else if(strcmp(groupName, "bathroom") == 0 && strcmp(lightName, "light") == 0) {
                bathroomLight->isOn = value;
            } else if(strcmp(groupName, "garage") == 0 && strcmp(lightName, "light") == 0) {
                garageLight->isOn = value;
            } else {
                printf("Unknown group or light name\n");
                continue;
            }

        } else if(strcmp(command, "set") == 0) {
            ptr = strtok(NULL, " ");
            if(!ptr) {
                printf("Please specify a brightness level\n");
                continue;
            }
            int value = atoi(ptr);
            if(value < 0 || value > 255) {
                printf("Brightness level should be between 0 and 255\n");
                continue;
            }
            if(!groupName || !lightName) {
                printf("Please specify group and light names\n");
                continue;
            }

            if(strcmp(groupName, "living") == 0 && strcmp(lightName, "room") == 0) {
                livingRoomLight->brightness = value;
            } else if(strcmp(groupName, "kitchen") == 0 && strcmp(lightName, "light") == 0) {
                kitchenLight->brightness = value;
            } else if(strcmp(groupName, "bedroom") == 0 && strcmp(lightName, "light") == 0) {
                bedroomLight->brightness = value;
            } else if(strcmp(groupName, "bathroom") == 0 && strcmp(lightName, "light") == 0) {
                bathroomLight->brightness = value;
            } else if(strcmp(groupName, "garage") == 0 && strcmp(lightName, "light") == 0) {
                garageLight->brightness = value;
            } else {
                printf("Unknown group or light name\n");
                continue;
            }

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "all") == 0) {
            printGroup(livingRoomGroup);
            printGroup(kitchenGroup);
            printGroup(bedroomGroup);
            printGroup(bathroomGroup);
            printGroup(garageGroup);

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "living") == 0 && strcmp(lightName, "room") == 0) {
            printGroup(livingRoomGroup);

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "kitchen") == 0 && strcmp(lightName, "light") == 0) {
            printGroup(kitchenGroup);

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "bedroom") == 0 && strcmp(lightName, "light") == 0) {
            printGroup(bedroomGroup);

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "bathroom") == 0 && strcmp(lightName, "light") == 0) {
            printGroup(bathroomGroup);

        } else if(strcmp(command, "show") == 0 && strcmp(groupName, "garage") == 0 && strcmp(lightName, "light") == 0) {
            printGroup(garageGroup);

        } else {
            printf("Unknown command\n");
        }
    }

    free(livingRoomLight);
    free(kitchenLight);
    free(bedroomLight);
    free(bathroomLight);
    free(garageLight);

    free(livingRoomGroup->lights);
    free(kitchenGroup->lights);
    free(bedroomGroup->lights);
    free(bathroomGroup->lights);
    free(garageGroup->lights);

    free(livingRoomGroup);
    free(kitchenGroup);
    free(bedroomGroup);
    free(bathroomGroup);
    free(garageGroup);

    return 0;
}