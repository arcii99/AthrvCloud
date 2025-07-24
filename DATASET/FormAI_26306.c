//FormAI DATASET v1.0 Category: Browser Plugin ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A struct to store the information about the plugin
struct Plugin {
    char name[50];
    char author[50];
    bool isActive;
};

// function to activate the plugin 
void activatePlugin(struct Plugin *p) {
    p->isActive = true;
    printf("\n%s plugin activated.\n\n", p->name);
}

// function to deactivate the plugin 
void deactivatePlugin(struct Plugin *p) {
    p->isActive = false;
    printf("\n%s plugin deactivated.\n\n", p->name);
}

// function to display the plugin details
void displayPlugin(struct Plugin *p) {
    printf("\nName: %s\n", p->name);
    printf("Author: %s\n", p->author);
    printf("Status: %s\n", p->isActive ? "Activated" : "Deactivated");
    printf("\n");
}

int main() {
    // creating an instance of the Plugin struct
    struct Plugin myPlugin = {"My Unique Plugin", "Me", false};
    
    // displaying the details of the plugin
    displayPlugin(&myPlugin);
    
    // activating the plugin
    activatePlugin(&myPlugin);
    
    // displaying the details of the plugin again
    displayPlugin(&myPlugin);
    
    // deactivating the plugin
    deactivatePlugin(&myPlugin);
    
    // displaying the details of the plugin again
    displayPlugin(&myPlugin);
    
    return 0;
}