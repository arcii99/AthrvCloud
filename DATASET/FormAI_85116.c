//FormAI DATASET v1.0 Category: Browser Plugin ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the function to be called by the plugin
void alertUser(char* message) {
    printf("ALERT: %s\n", message);
}

// Create the plugin object
struct BrowserPlugin {
    char* name;
    char* version;
    void (* alertUser)(char*);
};

// Main function to create and use the plugin
int main() {
    // Create a new BrowserPlugin instance
    struct BrowserPlugin myPlugin = {
        "MyPlugin",
        "1.0",
        &alertUser
    };

    // Call the alertUser function on the plugin
    myPlugin.alertUser("Hello world!");

    // Free the memory allocated to myPlugin
    free(myPlugin.name);
    free(myPlugin.version);

    return 0;
}