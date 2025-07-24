//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Sherlock Holmes
// The Adventure of the C Browser Plugin
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Plugin struct
typedef struct {
    char name[20];
    char author[20];
    int version;
} Plugin;

// Define global variable for plugins
Plugin plugins[5];
int numPlugins = 0;

// Function to add a plugin to the array
void addPlugin(char *name, char *author, int version) {
    Plugin newPlugin;
    strcpy(newPlugin.name, name);
    strcpy(newPlugin.author, author);
    newPlugin.version = version;
    plugins[numPlugins] = newPlugin;
    numPlugins++;
}

// Function to list all plugins
void listPlugins() {
    printf("\n----- Available plugins -----\n");
    for (int i = 0; i < numPlugins; i++) {
        printf("%s (v%d) by %s\n", plugins[i].name, plugins[i].version, plugins[i].author);
    }
}

// Function to search for a specific plugin
void searchPlugin(char *name) {
    for (int i = 0; i < numPlugins; i++) {
        if (strcmp(name, plugins[i].name) == 0) {
            printf("\n----- Plugin Found -----\n");
            printf("%s (v%d) by %s\n", plugins[i].name, plugins[i].version, plugins[i].author);
            return;
        }
    }
    printf("\n----- Plugin Not Found -----\n");
}

int main() {
    // Introduction
    printf("Welcome to the C Browser Plugin Program!\n");
    printf("In this program, you will be able to add, list, and search for plugins.\n");
    printf("Let's get started!\n\n");

    // Add some plugins
    addPlugin("AdBlocker", "John Doe", 1);
    addPlugin("AutoFill", "Jane Doe", 2);
    addPlugin("Password Manager", "Alex Smith", 1);

    // List all plugins
    listPlugins();

    // Search for a plugin
    searchPlugin("AutoFill");

    // Search for a plugin that doesn't exist
    searchPlugin("PopUp Blocker");

    // Exit message
    printf("\nThank you for using the C Browser Plugin Program!\n");

    return 0;
}