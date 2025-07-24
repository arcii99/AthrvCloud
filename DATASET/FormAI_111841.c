//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    bool enabled;
} Plugin;

int numPlugins = 0;

/**
 * Function to print the status of a plugin
 */
void printPlugin(Plugin plugin) {
    printf("Name: %s - Enabled: %s\n", plugin.name, plugin.enabled ? "true" : "false");
}

/**
 * Function to print the list of plugins
 */
void printPlugins(Plugin plugins[]) {
    printf("List of plugins:\n");
    for (int i = 0; i < numPlugins; i++) {
        printPlugin(plugins[i]);
    }
}

/**
 * Function to enable or disable a plugin by name
 */
void togglePlugin(char name[], Plugin plugins[]) {
    for (int i = 0; i < numPlugins; i++) {
        if (strcmp(name, plugins[i].name) == 0) {
            plugins[i].enabled = !plugins[i].enabled;
            return;
        }
    }
    printf("Error: Plugin with name %s not found.\n", name);
}

int main() {
    Plugin plugins[10];

    // Adding plugins
    strcpy(plugins[0].name, "AdBlock");
    plugins[0].enabled = true;

    strcpy(plugins[1].name, "Cookie Blocker");
    plugins[1].enabled = false;

    numPlugins = 2;

    // Printing list of plugins
    printPlugins(plugins);

    // Enabling Cookie Blocker
    togglePlugin("Cookie Blocker", plugins);

    // Printing list of plugins after disabling Cookie Blocker
    printPlugins(plugins);

    return 0;
}