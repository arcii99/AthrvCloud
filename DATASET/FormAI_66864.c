//FormAI DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_LIGHTS 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    int brightness;
    int temperature;
    int isOn;
} Light;

void printLight(Light light) {
    printf("%s:\n", light.name);
    printf("\tBrightness: %d%%\n", light.brightness);
    printf("\tTemperature: %dK\n", light.temperature);
    printf("\tStatus: %s\n\n", light.isOn ? "ON" : "OFF");
}

void printAllLights(Light lights[], int numLights) {
    printf("All Lights:\n");
    for (int i = 0; i < numLights; i++) {
        printLight(lights[i]);
    }
}

void turnOnLight(Light *light) {
    light->isOn = 1;
    printf("%s turned ON.\n", light->name);
}

void turnOffLight(Light *light) {
    light->isOn = 0;
    printf("%s turned OFF.\n", light->name);
}

void setBrightness(Light *light, int brightness) {
    light->brightness = brightness;
    printf("%s brightness set to %d%%.\n", light->name, light->brightness);
}

void setTemperature(Light *light, int temperature) {
    light->temperature = temperature;
    printf("%s temperature set to %dK.\n", light->name, light->temperature);
}

void controlLight(Light *light) {
    printf("What would you like to do with %s?\n", light->name);
    printf("\t1. Turn On\n");
    printf("\t2. Turn Off\n");
    printf("\t3. Set Brightness\n");
    printf("\t4. Set Temperature\n");
    printf("\t5. Exit\n");

    int choice;
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            turnOnLight(light);
            break;
        case 2:
            turnOffLight(light);
            break;
        case 3:
            int brightness;
            printf("Enter brightness (0-100): ");
            scanf("%d", &brightness);
            setBrightness(light, brightness);
            break;
        case 4:
            int temperature;
            printf("Enter temperature (2000K-6500K): ");
            scanf("%d", &temperature);
            setTemperature(light, temperature);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }
}

int main() {
    Light lights[MAX_LIGHTS];
    int numLights = 0;

    srand(time(NULL)); // seed random number generator

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("\t1. Add Light\n");
        printf("\t2. Control Light\n");
        printf("\t3. Print All Lights\n");
        printf("\t4. Exit\n");

        int choice;
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numLights < MAX_LIGHTS) {
                    printf("Enter name for new light: ");
                    scanf("%s", lights[numLights].name);
                    lights[numLights].brightness = rand() % 101; // set random brightness
                    lights[numLights].temperature = 2000 + rand() % (6501 - 2000); // set random temperature between 2000K and 6500K
                    lights[numLights].isOn = rand() % 2; // randomly turn light on or off
                    printf("%s added to system.\n", lights[numLights].name);
                    numLights++;
                } else {
                    printf("Maximum number of lights reached.\n");
                }
                break;
            case 2:
                if (numLights > 0) {
                    printf("Select light to control:\n");
                    for (int i = 0; i < numLights; i++) {
                        printf("\t%d. %s\n", i+1, lights[i].name);
                    }
                    int lightChoice;
                    printf("Enter choice: ");
                    scanf("%d", &lightChoice);
                    if (lightChoice >= 1 && lightChoice <= numLights) {
                        controlLight(&lights[lightChoice-1]); // pass in pointer to selected light
                    } else {
                        printf("Invalid input.\n");
                    }
                } else {
                    printf("No lights to control.\n");
                }
                break;
            case 3:
                printAllLights(lights, numLights);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }
    }

    return 0;
}