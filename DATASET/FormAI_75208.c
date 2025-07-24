//FormAI DATASET v1.0 Category: Browser Plugin ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our plugin structure
typedef struct Plugin {
    char name[50];
    char description[100];
    void (*callback)();
} Plugin;

void greetingPlugin() {
    printf("Hello from the Greeting Plugin!\n");
}

void counterPlugin() {
    static int count = 0;
    printf("The counter value is %d\n", ++count);
}

// Define our plugins
Plugin plugins[] = {
    {"greeting", "Greets the user.", greetingPlugin},
    {"counter", "Counts the number of times it is invoked.", counterPlugin}
};

int numPlugins = sizeof(plugins) / sizeof(Plugin);

// Entry point for the plugin
void pluginMain(char* message) {
    int i;
    for (i = 0; i < numPlugins; i++) {
        if (strstr(message, plugins[i].name) != NULL) {
            printf("Plugin found: %s - %s\n", plugins[i].name, plugins[i].description);
            plugins[i].callback();
            return;
        }
    }
    printf("No plugin found for %s\n", message);
}

// Entry point for the browser
int main() {
    char message[50];
    printf("Enter a command: ");
    scanf("%s", message);
    pluginMain(message);
    return 0;
}