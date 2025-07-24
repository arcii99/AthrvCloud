//FormAI DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to hold plugin information
typedef struct {
    char* name;
    char* description;
    bool enabled;
} Plugin;

// Simple function to enable a given plugin
void enablePlugin(Plugin* plugin) {
    plugin->enabled = true;
}

// Simple function to disable a given plugin
void disablePlugin(Plugin* plugin) {
    plugin->enabled = false;
}

// Our main function
int main() {
    // Create some example plugins
    Plugin flashPlugin = {"Flash Player", "Plays Flash videos and animations", true};
    Plugin adBlockerPlugin = {"Ad Blocker", "Blocks ads on webpages", false};
    Plugin grammarPlugin = {"Grammar Checker", "Checks grammar on text input fields", true};

    // Enable the Flash Player plugin
    enablePlugin(&flashPlugin);

    // Toggle the Ad Blocker plugin
    if (adBlockerPlugin.enabled) {
        disablePlugin(&adBlockerPlugin);
    }
    else {
        enablePlugin(&adBlockerPlugin);
    }

    // Print out the status of all plugins
    printf("%s: %s - %s\n", flashPlugin.name, flashPlugin.description, flashPlugin.enabled ? "Enabled" : "Disabled");
    printf("%s: %s - %s\n", adBlockerPlugin.name, adBlockerPlugin.description, adBlockerPlugin.enabled ? "Enabled" : "Disabled");
    printf("%s: %s - %s\n", grammarPlugin.name, grammarPlugin.description, grammarPlugin.enabled ? "Enabled" : "Disabled");

    return 0;
}