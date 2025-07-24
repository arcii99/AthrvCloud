//FormAI DATASET v1.0 Category: Smart home light control ; Style: grateful
// Welcome to the Smart Home Light Control program!
// We are grateful to have you here.

#include <stdio.h>
#include <string.h>

// Define the maximum number of lights in the house
#define MAX_LIGHTS 10

// Define the maximum length of the light names
#define MAX_NAME_LENGTH 20

// Define a struct to store each light's information
typedef struct light {
    char name[MAX_NAME_LENGTH];
    int state; // 0 for off, 1 for on
} Light;

// Declare the array of lights
Light lights[MAX_LIGHTS];

// Declare a function to print the current state of all lights
void printLights() {
    printf("Current state of lights:\n");
    for(int i = 0; i < MAX_LIGHTS; i++) {
        if(lights[i].state == 0) {
            printf("%s - off\n", lights[i].name);
        } else {
            printf("%s - on\n", lights[i].name);
        }
    }
    printf("\n");
}

int main() {
    // Initialize the array of lights with default names and states
    strcpy(lights[0].name, "Living Room");
    strcpy(lights[1].name, "Kitchen");
    strcpy(lights[2].name, "Bedroom");
    strcpy(lights[3].name, "Bathroom");
    strcpy(lights[4].name, "Garage");
    strcpy(lights[5].name, "Hallway");
    strcpy(lights[6].name, "Dining Room");
    strcpy(lights[7].name, "Study");
    strcpy(lights[8].name, "Patio");
    strcpy(lights[9].name, "Front Door");

    for(int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].state = 0; // All lights start off
    }

    // Print the current state of all lights
    printLights();

    // Prompt the user for input
    printf("Enter the name of the light you want to turn on/off: ");
    char input[MAX_NAME_LENGTH];
    fgets(input, MAX_NAME_LENGTH, stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // Find the light with the matching name
    int index = -1;
    for(int i = 0; i < MAX_LIGHTS; i++) {
        if(strcmp(lights[i].name, input) == 0) {
            index = i;
            break;
        }
    }

    // Toggle the state of the chosen light
    if(index >= 0) {
        if(lights[index].state == 0) {
            lights[index].state = 1;
        } else {
            lights[index].state = 0;
        }
        printf("%s has been toggled\n", lights[index].name);
    } else {
        printf("Light not found\n");
    }

    // Print the current state of all lights
    printLights();

    return 0;
}