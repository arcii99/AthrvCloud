//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define plugin function
void myPluginFunc(){
    printf("Hello from my plugin function!\n");
}

// Define struct for browser plugin
struct BrowserPlugin {
    char* pluginName;
    void (*pluginFunc)();
};

// Define sample browser plugins
struct BrowserPlugin myPlugin = { "My Plugin", myPluginFunc };
struct BrowserPlugin myOtherPlugin = { "My Other Plugin", myPluginFunc };

// Define function to dynamically load browser plugins
void loadPlugins(struct BrowserPlugin plugins[], int numPlugins) {
    printf("Loading plugins...\n");

    // Loop through plugins and call their pluginFunc
    for(int i=0; i<numPlugins; i++){
        printf("   Loading plugin: %s...", plugins[i].pluginName);
        plugins[i].pluginFunc();
    }

    printf("Done loading plugins.\n");
}

int main() {
    // Define an array of plugins
    struct BrowserPlugin allPlugins[] = { myPlugin, myOtherPlugin };

    // Load all plugins
    loadPlugins(allPlugins, 2);

    return 0;
}