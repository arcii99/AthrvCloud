//FormAI DATASET v1.0 Category: Browser Plugin ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold plugin information
typedef struct {
    char* name;
    char* description;
    char* author;
    char* version;
} Plugin;

// function to display plugin information
void display_plugin_info(Plugin* plugin) {
    printf("Name: %s\n", plugin->name);
    printf("Description: %s\n", plugin->description);
    printf("Author: %s\n", plugin->author);
    printf("Version: %s\n", plugin->version);
}

int main() {
    // create a new plugin
    Plugin* my_plugin = (Plugin*) malloc(sizeof(Plugin));
    my_plugin->name = "My Plugin";
    my_plugin->description = "A sample plugin";
    my_plugin->author = "John Doe";
    my_plugin->version = "1.0";

    // display plugin information
    display_plugin_info(my_plugin);

    // free memory
    free(my_plugin);

    return 0;
}