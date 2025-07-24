//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Define browser plugin structure
typedef struct plugin {
    char name[50];
    char description[100];
    char author[50];
    char version[10];
    bool enabled;
} Plugin;

// Define an array to hold all plugins
Plugin plugins[10];

// Function to initialize plugins
void init_plugins() {
    // Plugin 1
    strcpy(plugins[0].name, "Facebook");
    strcpy(plugins[0].description, "Adds Facebook integration to the browser");
    strcpy(plugins[0].author, "John Smith");
    strcpy(plugins[0].version, "1.0");
    plugins[0].enabled = true;
    // Plugin 2
    strcpy(plugins[1].name, "Twitter");
    strcpy(plugins[1].description, "Adds Twitter integration to the browser");
    strcpy(plugins[1].author, "Jane Doe");
    strcpy(plugins[1].version, "2.0");
    plugins[1].enabled = false;
}

// Function to enable a plugin
void enable_plugin(int index) {
    plugins[index].enabled = true;
}

// Function to disable a plugin
void disable_plugin(int index) {
    plugins[index].enabled = false;
}

// Function to get the number of enabled plugins
int get_num_enabled_plugins() {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (plugins[i].enabled) {
            count++;
        }
    }
    return count;
}

int main() {
    // Initialize the plugins
    init_plugins();

    // Enable the Twitter plugin
    enable_plugin(1);

    // Disable the Facebook plugin
    disable_plugin(0);

    // Get the number of enabled plugins
    int num_enabled_plugins = get_num_enabled_plugins();

    // Print the number of enabled plugins
    printf("Number of enabled plugins: %d\n", num_enabled_plugins);

    return 0;
}