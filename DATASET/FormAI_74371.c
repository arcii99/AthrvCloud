//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// define the number of lights in the home
#define MAX_LIGHTS 10

// define the maximum length of a light name
#define MAX_NAME_LENGTH 20

// define the maximum length of a command string
#define MAX_COMMAND_LENGTH 50

// define the struct for a light
typedef struct {
    char name[MAX_NAME_LENGTH];
    bool isOn;
} Light;

// declare the array of lights
Light lights[MAX_LIGHTS];

// declare function prototypes
void initializeLights();
void printLights();
void processCommand(char* command);

int main() {
    // initialize the lights
    initializeLights();
    
    // print the initial state of the lights
    printf("Initial state of the lights:\n");
    printLights();
    
    // loop to process commands
    char command[MAX_COMMAND_LENGTH];
    while (true) {
        // get command from user
        printf("Enter a command (e.g. 'turn on living room light'): ");
        fgets(command, sizeof(command), stdin);
        
        // remove trailing newline from command
        command[strcspn(command, "\n")] = '\0';
        
        // process the command
        processCommand(command);
        
        // print the new state of the lights
        printf("New state of the lights:\n");
        printLights();
    }
    
    return 0;
}

// initialize the lights
void initializeLights() {
    strcpy(lights[0].name, "living room light");
    lights[0].isOn = false;
    strcpy(lights[1].name, "kitchen light");
    lights[1].isOn = false;
    strcpy(lights[2].name, "bedroom light");
    lights[2].isOn = false;
    strcpy(lights[3].name, "bathroom light");
    lights[3].isOn = false;
    strcpy(lights[4].name, "dining room light");
    lights[4].isOn = false;
}

// print the current state of the lights
void printLights() {
    for (int i = 0; i < MAX_LIGHTS; i++) {
        printf("%s is %s\n", lights[i].name, lights[i].isOn ? "on" : "off");
    }
}

// process a command
void processCommand(char* command) {
    // split the command into tokens
    char* token = strtok(command, " ");
    char* action = token;
    token = strtok(NULL, " ");
    char* name = token;
    
    // find the light by name
    int lightIndex = -1;
    for (int i = 0; i < MAX_LIGHTS; i++) {
        if (strcmp(lights[i].name, name) == 0) {
            lightIndex = i;
            break;
        }
    }
    
    // perform the action on the light
    if (lightIndex == -1) {
        printf("Error: light not found\n");
    } else if (strcmp(action, "turn") == 0) {
        token = strtok(NULL, " ");
        if (strcmp(token, "on") == 0) {
            lights[lightIndex].isOn = true;
        } else if (strcmp(token, "off") == 0) {
            lights[lightIndex].isOn = false;
        } else {
            printf("Error: invalid command\n");
        }
    } else {
        printf("Error: invalid command\n");
    }
}