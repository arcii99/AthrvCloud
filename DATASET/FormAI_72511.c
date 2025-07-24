//FormAI DATASET v1.0 Category: Browser Plugin ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the plugin struct
typedef struct Plugin {
    char* name;
    char* description;
    bool enabled;
} Plugin;

// Define the array of available plugins
Plugin plugins[] = {
    {"Example Plugin 1", "This is the first example plugin", true},
    {"Example Plugin 2", "This is the second example plugin", false},
    {"Example Plugin 3", "This is the third example plugin", true}
};

// Define a function to toggle the enabled status of a plugin
void toggle_plugin(int index) {
    plugins[index].enabled = !plugins[index].enabled;
}

int main() {
    int plugin_count = sizeof(plugins) / sizeof(Plugin);

    // Print out the available plugins and their statuses
    printf("%d Plugins Available:\n", plugin_count);
    for (int i = 0; i < plugin_count; i++) {
        printf("%d. %s - %s (%s)\n", i+1, plugins[i].name, plugins[i].description, plugins[i].enabled ? "Enabled" : "Disabled");
    }

    // Prompt the user to toggle the enabled status of a plugin
    int index_to_toggle;
    printf("Enter the number of the plugin you want to toggle: ");
    scanf("%d", &index_to_toggle);

    // Toggle the enabled status of the chosen plugin
    toggle_plugin(index_to_toggle - 1);

    // Print out the new statuses of all plugins
    printf("Updated Plugin Statuses:\n");
    for (int i = 0; i < plugin_count; i++) {
        printf("%d. %s - %s (%s)\n", i+1, plugins[i].name, plugins[i].description, plugins[i].enabled ? "Enabled" : "Disabled");
    }

    return 0;
}