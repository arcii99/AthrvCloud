//FormAI DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Definition for the appliances in the smart home
typedef struct {
    char* name;
    bool is_on; // whether the appliance is currently on or not
} Appliance;

// Function to turn on or off an appliance
void toggle_appliance(Appliance* appliance) {
    appliance->is_on = !appliance->is_on;
    printf("%s has been turned %s.\n", appliance->name, appliance->is_on ? "on" : "off");
}

int main() {
    const int MAX_APPLIANCES = 10;
    Appliance appliances[MAX_APPLIANCES];

    // Initialize the appliances
    appliances[0].name = "Living room light";
    appliances[0].is_on = false;
    appliances[1].name = "Bedroom light";
    appliances[1].is_on = false;
    appliances[2].name = "Kitchen light";
    appliances[2].is_on = false;

    int num_appliances = 3;

    // Print out the current state of all appliances
    printf("Current state of all appliances:\n");
    for (int i = 0; i < num_appliances; i++) {
        printf("%s is turned %s.\n", appliances[i].name, appliances[i].is_on ? "on" : "off");
    }

    // Main loop for the user interface
    char input[50];
    bool exit_program = false;
    while (!exit_program) {
        printf("Enter a command (type 'help' for options): ");
        fgets(input, 50, stdin);
        input[strlen(input) - 1] = '\0'; // remove the newline character

        // Parse the command
        if (strcmp(input, "exit") == 0) {
            exit_program = true;
        }
        else if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("    exit: exit the program\n");
            printf("    help: print this help message\n");
            printf("    list: list all appliances\n");
            printf("    turn [appliance name] [on/off]: turn an appliance on or off\n");
        }
        else if (strcmp(input, "list") == 0) {
            printf("List of all appliances:\n");
            for (int i = 0; i < num_appliances; i++) {
                printf("- %s\n", appliances[i].name);
            }
        }
        else if (strncmp(input, "turn ", 5) == 0) {
            // Parse the appliance name and desired state from the command
            char* appliance_name = strtok(&input[5], " ");
            char* state = strtok(NULL, " ");

            // Find the appliance with the given name
            Appliance* appliance = NULL;
            for (int i = 0; i < num_appliances; i++) {
                if (strcmp(appliances[i].name, appliance_name) == 0) {
                    appliance = &appliances[i];
                    break;
                }
            }

            // Toggle the appliance if found
            if (appliance != NULL) {
                if (strcmp(state, "on") == 0) {
                    if (!appliance->is_on) {
                        toggle_appliance(appliance);
                    }
                    else {
                        printf("%s is already turned on.\n", appliance->name);
                    }
                }
                else if (strcmp(state, "off") == 0) {
                    if (appliance->is_on) {
                        toggle_appliance(appliance);
                    }
                    else {
                        printf("%s is already turned off.\n", appliance->name);
                    }
                }
                else {
                    printf("Invalid state '%s'. Must be either 'on' or 'off'.\n", state);
                }
            }
            else {
                printf("Appliance '%s' not found.\n", appliance_name);
            }
        }
        else {
            printf("Invalid command. Type 'help' for options.\n");
        }
    }

    return 0;
}