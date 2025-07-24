//FormAI DATASET v1.0 Category: Smart home light control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LIGHTS 10
#define MAX_NAME_LENGTH 20

struct Light {
    char name[MAX_NAME_LENGTH];
    bool isOn;
};

struct Light lights[MAX_LIGHTS];

int numLights = 0;

void turnOnLight(int lightIndex) {
    if (lightIndex >= 0 && lightIndex < numLights) {
        lights[lightIndex].isOn = true;
        printf("%s is now on.\n", lights[lightIndex].name);
    } else {
        printf("Invalid light index.\n");
    }
}

void turnOffLight(int lightIndex) {
    if (lightIndex >= 0 && lightIndex < numLights) {
        lights[lightIndex].isOn = false;
        printf("%s is now off.\n", lights[lightIndex].name);
    } else {
        printf("Invalid light index.\n");
    }
}

void toggleLight(int lightIndex) {
    if (lightIndex >= 0 && lightIndex < numLights) {
        if (lights[lightIndex].isOn) {
            turnOffLight(lightIndex);
        } else {
            turnOnLight(lightIndex);
        }
    } else {
        printf("Invalid light index.\n");
    }
}

int findLightByName(char *name) {
    for (int i = 0; i < numLights; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void addLight(char *name) {
    if (numLights < MAX_LIGHTS) {
        strcpy(lights[numLights].name, name);
        lights[numLights].isOn = false;
        numLights++;
        printf("%s added as a new light.\n", name);
    } else {
        printf("Maximum number of lights reached.\n");
    }
}

void removeLight(int lightIndex) {
    if (lightIndex >= 0 && lightIndex < numLights) {
        for (int i = lightIndex; i < numLights - 1; i++) {
            lights[i] = lights[i + 1];
        }
        numLights--;
        printf("%s removed from the list of lights.\n", lights[lightIndex].name);
    } else {
        printf("Invalid light index.\n");
    }
}

void printCurrentState() {
    printf("Current state:\n");
    for (int i = 0; i < numLights; i++) {
        if (lights[i].isOn) {
            printf("%s is on.\n", lights[i].name);
        } else {
            printf("%s is off.\n", lights[i].name);
        }
    }
}

int main() {
    printf("Welcome to the smart home light control program!\n");

    while (true) {
        printf("Please choose an option: \n");
        printf("1. Add a new light \n");
        printf("2. Remove a light \n");
        printf("3. Turn on a light \n");
        printf("4. Turn off a light \n");
        printf("5. Toggle a light \n");
        printf("6. Print current state \n");
        printf("7. Exit \n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the new light: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                addLight(name);
                break;
            case 2:
                printf("Enter the index of the light to remove: ");
                int removeIndex;
                scanf("%d", &removeIndex);
                removeLight(removeIndex);
                break;
            case 3:
                printf("Enter the name of the light to turn on: ");
                char turnOnName[MAX_NAME_LENGTH];
                scanf("%s", turnOnName);
                int turnOnIndex = findLightByName(turnOnName);
                turnOnLight(turnOnIndex);
                break;
            case 4:
                printf("Enter the name of the light to turn off: ");
                char turnOffName[MAX_NAME_LENGTH];
                scanf("%s", turnOffName);
                int turnOffIndex = findLightByName(turnOffName);
                turnOffLight(turnOffIndex);
                break;
            case 5:
                printf("Enter the name of the light to toggle: ");
                char toggleName[MAX_NAME_LENGTH];
                scanf("%s", toggleName);
                int toggleIndex = findLightByName(toggleName);
                toggleLight(toggleIndex);
                break;
            case 6:
                printCurrentState();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}