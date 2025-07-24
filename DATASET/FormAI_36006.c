//FormAI DATASET v1.0 Category: Browser Plugin ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    printf("=======================\n");
    printf("| MY BROWSER PLUGIN    |\n");
    printf("=======================\n\n");

    // check if plugin is enabled
    bool isEnabled = true; // assume plugin is enabled
    char* pluginEnabled = getenv("PLUGIN_ENABLED");

    if (pluginEnabled != NULL && strcmp(pluginEnabled, "false") == 0) {
        isEnabled = false;
    }

    if (isEnabled) {
        // get URL from browser
        char* url = getenv("CURRENT_URL");
        if (url != NULL) {
            printf("Current URL: %s\n", url);
        } else {
            printf("No URL found.\n");
        }

        // ask user for input
        printf("Enter some text: ");
        char userInput[100];
        fgets(userInput, sizeof(userInput), stdin);

        // display user input
        printf("You entered: %s\n", userInput);
    } else {
        printf("Plugin is disabled.\n");
    }

    return 0;
}