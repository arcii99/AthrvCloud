//FormAI DATASET v1.0 Category: Smart home light control ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIGHTS 10 // Maximum number of lights in the smart home

typedef enum {
    OFF,
    ON,
    DIM
} LightState;

typedef struct {
    char name[20];
    LightState state;
    int brightness;
} Light;

// Method to print the state of all lights in the home
void printState(Light* lights, int numLights) {
    printf("Current light state:\n");
    for(int i=0; i<numLights; i++) {
        printf("%s: ", lights[i].name);
        if(lights[i].state == OFF) {
            printf("Off\n");
        } else if(lights[i].state == ON) {
            printf("On, Brightness: %d\n", lights[i].brightness);
        } else {
            printf("Dim, Brightness: %d\n", lights[i].brightness);
        }
    }
    printf("\n");
}

int main() {
    // Set up smart home light system
    Light lights[MAX_LIGHTS];
    int numLights = 0;
    char input[20];
    char name[20];
    int brightness;
    printf("Welcome to your smart home light system!\n");

    // Add initial lights to the system
    strcpy(lights[numLights].name, "Living Room");
    lights[numLights].state = OFF;
    numLights++;

    strcpy(lights[numLights].name, "Bedroom");
    lights[numLights].state = OFF;
    numLights++;

    // User interface loop
    while(1) {
        printf("Enter command (add, remove, turnon, turnoff, dim, status, quit):\n");
        scanf("%20s", input);
        if(strcmp(input, "add") == 0) {
            // Add a new light to the system
            printf("Enter name of light: ");
            scanf("%20s", name);
            printf("Enter initial brightness (0-100): ");
            scanf("%d", &brightness);
            strcpy(lights[numLights].name, name);
            lights[numLights].brightness = brightness;
            lights[numLights].state = ON;
            numLights++;
            printf("%s added to the system.\n", name);
        } else if(strcmp(input, "remove") == 0) {
            // Remove a light from the system
            printf("Enter name of light to remove: ");
            scanf("%20s", name);
            int index = -1;
            for(int i=0; i<numLights; i++) {
                if(strcmp(lights[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }
            if(index != -1) {
                for(int i=index; i<numLights-1; i++) {
                    // We want to remove the light at the specified index, so we need to shift all the lights array elements
                    // after it one index to the left.
                    lights[i] = lights[i+1];
                }
                printf("%s removed from the system.\n", name);
                numLights--;
            } else {
                printf("%s not found in the system.\n", name);
            }
        } else if(strcmp(input, "turnon") == 0) {
            // Turn a light on
            printf("Enter name of light to turn on: ");
            scanf("%20s", name);
            int index = -1;
            for(int i=0; i<numLights; i++) {
                if(strcmp(lights[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }
            if(index != -1) {
                lights[index].state = ON;
                printf("%s turned on.\n", name);
            } else {
                printf("%s not found in the system.\n", name);
            }
        } else if(strcmp(input, "turnoff") == 0) {
            // Turn a light off
            printf("Enter name of light to turn off: ");
            scanf("%20s", name);
            int index = -1;
            for(int i=0; i<numLights; i++) {
                if(strcmp(lights[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }
            if(index != -1) {
                lights[index].state = OFF;
                printf("%s turned off.\n", name);
            } else {
                printf("%s not found in the system.\n", name);
            }
        } else if(strcmp(input, "dim") == 0) {
            // Dim a light
            printf("Enter name of light to dim: ");
            scanf("%20s", name);
            int index = -1;
            for(int i=0; i<numLights; i++) {
                if(strcmp(lights[i].name, name) == 0) {
                    index = i;
                    break;
                }
            }
            if(index != -1) {
                printf("Enter new brightness (0-100): ");
                scanf("%d", &brightness);
                lights[index].brightness = brightness;
                lights[index].state = DIM;
                printf("%s dimmed.\n", name);
            } else {
                printf("%s not found in the system.\n", name);
            }
        } else if(strcmp(input, "status") == 0) {
            // Print the state of all lights in the home
            printState(lights, numLights);
        } else if(strcmp(input, "quit") == 0) {
            // Exit the program
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }
    return 0;
}