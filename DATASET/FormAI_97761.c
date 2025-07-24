//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for our plugin
typedef struct browser_plugin {
    char name[50];
    char description[100];
    int version;
} browser_plugin;

int main() {
    // Allocate memory for our plugin
    browser_plugin *plugin = (browser_plugin *) malloc(sizeof(browser_plugin));

    // Get user input for plugin name and description
    printf("Enter plugin name: ");
    fgets(plugin->name, 50, stdin);
    printf("Enter plugin description: ");
    fgets(plugin->description, 100, stdin);

    // Set plugin version to 1
    plugin->version = 1;

    // Print plugin details
    printf("\nPlugin name: %s", plugin->name);
    printf("Plugin description: %s", plugin->description);
    printf("Plugin version: %d", plugin->version);

    // Free allocated memory
    free(plugin);

    return 0;
}