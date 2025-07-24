//FormAI DATASET v1.0 Category: Browser Plugin ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the browser plugin structure
typedef struct {
    char* name;
    char* description;
    void (*init)();
    void (*execute)();
    void (*cleanup)();
} plugin_t;

// Define the plugin functions
void initPluginA() { printf("Plugin A initialized\n"); }
void executePluginA() { printf("Plugin A executed\n"); }
void cleanupPluginA() { printf("Plugin A cleaned up\n"); }

void initPluginB() { printf("Plugin B initialized\n"); }
void executePluginB() { printf("Plugin B executed\n"); }
void cleanupPluginB() { printf("Plugin B cleaned up\n"); }

// Define the list of available plugins
const plugin_t plugins[] = {
    {"Plugin A", "Description of Plugin A.", &initPluginA, &executePluginA, &cleanupPluginA},
    {"Plugin B", "Description of Plugin B.", &initPluginB, &executePluginB, &cleanupPluginB}
};

// Define the number of available plugins
const size_t num_plugins = sizeof(plugins) / sizeof(plugin_t);

// Define the plugin selection function
void selectPlugin(const char* name) {
    // Find the plugin with the given name
    for (size_t i = 0; i < num_plugins; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            // Initialize the plugin
            plugins[i].init();

            // Execute the plugin
            plugins[i].execute();

            // Clean up the plugin
            plugins[i].cleanup();

            return;
        }
    }

    // If no plugin was found, print an error message
    printf("Error: plugin '%s' not found\n", name);
}

// Main function for testing the plugin system
int main() {
    // Select the Plugin A
    selectPlugin("Plugin A");

    // Select the Plugin B
    selectPlugin("Plugin B");

    return 0;
}