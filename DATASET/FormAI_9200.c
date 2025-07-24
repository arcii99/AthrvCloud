//FormAI DATASET v1.0 Category: Browser Plugin ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// structure of the browser plugin
typedef struct BrowserPlugin {
    char name[100];
    char version[100];
    bool isEnabled;
} BrowserPlugin;

// function to create a new instance of the browser plugin
BrowserPlugin* createBrowserPlugin(char* name, char* version, bool isEnabled) {
    BrowserPlugin* plugin = (BrowserPlugin*) malloc(sizeof(BrowserPlugin));
    strcpy(plugin->name, name);
    strcpy(plugin->version, version);
    plugin->isEnabled = isEnabled;
    return plugin;
}

// function to enable or disable the plugin
void togglePlugin(BrowserPlugin* plugin) {
    plugin->isEnabled = !plugin->isEnabled;
    printf("%s is now %s\n", plugin->name, plugin->isEnabled ? "enabled" : "disabled");
}

int main() {
    // creating browser plugin instances
    BrowserPlugin* adBlocker = createBrowserPlugin("AdBlocker", "v1.0", true);
    BrowserPlugin* socialMediaBlocker = createBrowserPlugin("Social Media Blocker", "v1.1", false);

    printf("%s %s is %s\n", adBlocker->name, adBlocker->version, adBlocker->isEnabled ? "enabled" : "disabled");
    printf("%s %s is %s\n", socialMediaBlocker->name, socialMediaBlocker->version, socialMediaBlocker->isEnabled ? "enabled" : "disabled");

    togglePlugin(adBlocker);
    togglePlugin(socialMediaBlocker);

    free(adBlocker);
    free(socialMediaBlocker);
    return 0;
}