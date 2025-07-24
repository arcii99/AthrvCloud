//FormAI DATASET v1.0 Category: Browser Plugin ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the shape-shifting plugin structure
struct shape_shifter_plugin {
    char name[50];
    bool active_state;
    void (*transform)(void);
};

// Define the transform functions
void transform_to_reverse_case(void) {
    printf("Plugin is now transforming text to reverse case.\n");
}

void transform_to_upper_case(void) {
    printf("Plugin is now transforming text to upper case.\n");
}

void transform_to_lower_case(void) {
    printf("Plugin is now transforming text to lower case.\n");
}

void transform_to_leet_speak(void) {
    printf("Plugin is now transforming text to leet speak.\n");
}

int main(void) {
    // Create an array of plugins
    struct shape_shifter_plugin plugins[4];
    
    // Set the name and transform functions for each plugin
    strcpy(plugins[0].name, "Reverse Case");
    plugins[0].active_state = false;
    plugins[0].transform = transform_to_reverse_case;
    
    strcpy(plugins[1].name, "Upper Case");
    plugins[1].active_state = false;
    plugins[1].transform = transform_to_upper_case;
    
    strcpy(plugins[2].name, "Lower Case");
    plugins[2].active_state = false;
    plugins[2].transform = transform_to_lower_case;
    
    strcpy(plugins[3].name, "Leet Speak");
    plugins[3].active_state = false;
    plugins[3].transform = transform_to_leet_speak;
    
    // Loop through the plugins and activate each one
    for (int i = 0; i < 4; i++) {
        printf("Activating plugin: %s\n", plugins[i].name);
        plugins[i].active_state = true;
        plugins[i].transform();
        printf("Plugin %s has finished transforming.\n", plugins[i].name);
    }
    
    return 0;
}