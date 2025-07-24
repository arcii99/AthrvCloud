//FormAI DATASET v1.0 Category: Browser Plugin ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the browser plugin structure
struct browser_plugin {
    char *name;
    char *description;
    char *version;
    int api_version;
};

// Declare a function to create a new browser plugin object
struct browser_plugin* create_browser_plugin(char *name, char *description, char *version, int api_version) {
    struct browser_plugin *plugin = malloc(sizeof(struct browser_plugin));
    plugin->name = name;
    plugin->description = description;
    plugin->version = version;
    plugin->api_version = api_version;
    return plugin;
}

// Declare a function to display the plugin information
void display_plugin_info(struct browser_plugin *plugin) {
    printf("Name: %s\n", plugin->name);
    printf("Description: %s\n", plugin->description);
    printf("Version: %s\n", plugin->version);
    printf("API Version: %d\n", plugin->api_version);
}

int main() {
    // Create a new browser plugin object
    struct browser_plugin *my_plugin = create_browser_plugin("My Plugin", "This is a test plugin", "1.0.0", 1);
    
    // Display the plugin information
    display_plugin_info(my_plugin);
    
    // Free the memory allocated for the plugin object
    free(my_plugin);
    
    return 0;
}