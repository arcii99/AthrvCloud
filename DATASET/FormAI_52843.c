//FormAI DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the browser plugin
#define MAX_SIZE 1024

// Define the browser plugin struct
typedef struct {
    char name[64];
    char description[256];
    char author[64];
    bool enabled;
} BrowserPlugin;

// Define a function to check if a plugin is enabled
bool isPluginEnabled(BrowserPlugin plugin) {
    return plugin.enabled;
}

// Define a function to enable a plugin
void enablePlugin(BrowserPlugin *plugin) {
    plugin->enabled = true;
}

// Define a function to disable a plugin
void disablePlugin(BrowserPlugin *plugin) {
    plugin->enabled = false;
}

// Define the main function
int main() {
    // Initialize the list of plugins
    BrowserPlugin pluginList[MAX_SIZE];
    int numPlugins = 0;

    // Add a new plugin to the list
    BrowserPlugin newPlugin;
    strcpy(newPlugin.name, "Example Plugin");
    strcpy(newPlugin.description, "This is an example plugin.");
    strcpy(newPlugin.author, "John Smith");
    newPlugin.enabled = false;
    pluginList[numPlugins] = newPlugin;
    numPlugins++;

    // Print the list of plugins
    printf("List of Plugins:\n");
    for (int i = 0; i < numPlugins; i++) {
        printf("%d. %s - %s\n", i+1, pluginList[i].name, pluginList[i].description);
    }

    // Enable the plugin
    enablePlugin(&pluginList[0]);

    // Print the list of enabled plugins
    printf("List of Enabled Plugins:\n");
    for (int i = 0; i < numPlugins; i++) {
        if (isPluginEnabled(pluginList[i])) {
            printf("%d. %s - %s\n", i+1, pluginList[i].name, pluginList[i].description);
        }
    }

    // Disable the plugin
    disablePlugin(&pluginList[0]);

    // Print the list of enabled plugins again
    printf("List of Enabled Plugins:\n");
    for (int i = 0; i < numPlugins; i++) {
        if (isPluginEnabled(pluginList[i])) {
            printf("%d. %s - %s\n", i+1, pluginList[i].name, pluginList[i].description);
        }
    }

    // Exit the program
    return 0;
}