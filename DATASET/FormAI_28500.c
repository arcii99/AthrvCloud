//FormAI DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIGHTS 10
#define MAX_CHARS 20

// Struct to represent a single light
typedef struct {
    int id;
    int brightness;
    char name[MAX_CHARS];
    int is_on;
} Light;

// Function to turn a light on or off
void toggle_light(Light *l) {
    if (l->is_on) {
        l->is_on = 0;
        printf("Light '%s' turned off\n", l->name);
    } else {
        l->is_on = 1;
        printf("Light '%s' turned on\n", l->name);
    }
}

// Function to change the brightness of a light
void set_brightness(Light *l, int brightness) {
    if (brightness < 0) {
        brightness = 0;
    } else if (brightness > 100) {
        brightness = 100;
    }
    l->brightness = brightness;
    printf("Brightness of light '%s' set to %d%%\n", l->name, brightness);
}

int main() {
    Light lights[MAX_LIGHTS];
    int num_lights = 0;

    // Initiate all lights to off
    for (int i = 0; i < MAX_LIGHTS; i++) {
        lights[i].id = i;
        lights[i].is_on = 0;
        lights[i].brightness = 0;
    }

    // Add a few example lights
    strcpy(lights[0].name, "Living Room");
    num_lights++;

    strcpy(lights[1].name, "Kitchen");
    num_lights++;

    strcpy(lights[2].name, "Bedroom");
    num_lights++;
    
    // Loop for user interaction
    while (1) {
        printf("Available Lights:\n");
        for (int i = 0; i < num_lights; i++) {
            printf("%d) %s\n", lights[i].id, lights[i].name);
        }
        printf("Enter a command:\n");

        char input[MAX_CHARS];
        fgets(input, MAX_CHARS, stdin);

        // Split user input into words
        char *word;
        word = strtok(input, " ");
        char **tokens = (char **) malloc(MAX_CHARS * sizeof(char *));
        int num_tokens = 0;
        while (word != NULL) {
            tokens[num_tokens] = word;
            num_tokens++;
            word = strtok(NULL, " ");
        }

        // Check what command was entered
        if (strcmp(tokens[0], "exit\n") == 0) {
            printf("Exiting...\n");
            break;

        } else if (strcmp(tokens[0], "add") == 0) {
            if (num_lights >= MAX_LIGHTS) {
                printf("Max lights exceeded\n");
                continue;
            }
            // Prompt user for name of new light
            printf("Enter name of new light:\n");
            fgets(lights[num_lights].name, MAX_CHARS, stdin);
            // Remove '\n' character from input
            lights[num_lights].name[strcspn(lights[num_lights].name, "\n")] = 0;
            // Set brightness to 0 and turn light off
            lights[num_lights].brightness = 0;
            lights[num_lights].is_on = 0;
            lights[num_lights].id = num_lights;
            num_lights++;

        } else if (strcmp(tokens[0], "toggle") == 0) {
            int id = atoi(tokens[1]);
            if (id >= num_lights) {
                printf("Invalid Light ID\n");
                continue;
            }
            toggle_light(&lights[id]);

        } else if (strcmp(tokens[0], "brightness") == 0) {
            int id = atoi(tokens[1]);
            if (id >= num_lights) {
                printf("Invalid Light ID\n");
                continue;
            }
            int brightness = atoi(tokens[2]);
            if (brightness < 0 || brightness > 100) {
                printf("Brightness must be between 0 and 100\n");
                continue;
            }
            set_brightness(&lights[id], brightness);

        } else {
            printf("Invalid command\n");
        }

        // Free memory used for tokens array
        free(tokens);
    }

    return 0;
}