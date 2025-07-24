//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Sherlock Holmes
/* The Adventure of the Browser Plugin */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the plugin interface
typedef struct Plugin {
    char* name;
    bool (*init)();
    void (*execute)(char*);
    bool (*cleanup)();
} Plugin;

// Define plugins
bool initGreetings() {
    printf("Greetings plugin initialized.\n");
    return true;
}

void executeGreetings(char* user) {
    printf("Hello, %s!\n", user);
}

bool cleanupGreetings() {
    printf("Greetings plugin cleaned up.\n");
    return true;
}

bool initJokes() {
    printf("Jokes plugin initialized.\n");
    return true;
}

void executeJokes(char* user) {
    printf("Why did the programmer quit his job? He didn't get arrays.\n");
}

bool cleanupJokes() {
    printf("Jokes plugin cleaned up.\n");
    return true;
}

// Define plugin list
Plugin plugins[] = {
    {"Greetings", initGreetings, executeGreetings, cleanupGreetings},
    {"Jokes", initJokes, executeJokes, cleanupJokes},
    {NULL, NULL, NULL, NULL} // Terminate the list
};

// Define plugin loader
void loadPlugin(char* name) {
    // Search plugin list for the named plugin
    for (int i = 0; plugins[i].name != NULL; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            // Initialize plugin if necessary
            if (!plugins[i].init()) {
                printf("%s plugin failed to initialize.\n", name);
                return;
            }
            // Execute plugin
            plugins[i].execute("Sherlock");
            // Cleanup plugin if necessary
            if (!plugins[i].cleanup()) {
                printf("%s plugin failed to cleanup.\n", name);
                return;
            }
            // Exit loop once we have found the named plugin
            return;
        }
    }
    // If the named plugin was not found, print error message
    printf("Error: plugin '%s' not found.\n", name);
}

int main() {
    loadPlugin("Greetings");
    loadPlugin("Jokes");
    loadPlugin("Mystery"); // This plugin doesn't exist
    return 0;
}