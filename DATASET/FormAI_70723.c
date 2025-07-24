//FormAI DATASET v1.0 Category: Browser Plugin ; Style: happy
#include <stdio.h>

// Define the plugin API version
#define PLUGIN_API_VERSION 1

// Define custom plugin functions
void greetFriend(char* friendName) {
    printf("Hello, %s! It's great to see you.\n", friendName);
}

void playMusic() {
    printf("♪♫ Let's dance! ♪♫\n");
}

// Define the actual plugin
struct Plugin {
    int apiVersion;
    void (*greet)(char*);
    void (*playMusic)();
};

// Initialize the plugin with our custom functions
struct Plugin MyPlugin = {
    PLUGIN_API_VERSION,
    greetFriend,
    playMusic
};

// Entry point for the plugin
int main() {
    printf("MyPlugin loaded successfully!\n");
    
    // Call plugin functions
    MyPlugin.greet("Alice");
    MyPlugin.playMusic();
    
    return 0;
}