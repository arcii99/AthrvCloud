//FormAI DATASET v1.0 Category: Browser Plugin ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct plugin {
    char name[50];
    char description[100];
    char version[10];
} Plugin;

void install_plugin(Plugin plugin) {
    printf("Installing plugin %s...\n", plugin.name);
    printf("Description: %s\n", plugin.description);
    printf("Version: %s\n", plugin.version);
    printf("Plugin installed successfully!\n\n");
}

void uninstall_plugin(Plugin plugin) {
    printf("Uninstalling plugin %s...\n", plugin.name);
    printf("Plugin uninstalled successfully!\n\n");
}

int main() {
    Plugin new_plugin;
    strcpy(new_plugin.name, "MyPlugin");
    strcpy(new_plugin.description, "This is a sample plugin for a C browser.");
    strcpy(new_plugin.version, "1.0");
    
    install_plugin(new_plugin);
    uninstall_plugin(new_plugin);
    
    return 0;
}