//FormAI DATASET v1.0 Category: Browser Plugin ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pluginInit() {
    printf("Plugin initialized!\n");
}

void pluginCleanup() {
    printf("Plugin cleaned up!\n");
}

int main() {
    pluginInit();

    // Do some browser-related operations
    printf("Getting current URL...\n");
    char* currentUrl = "https://www.example.com";
    printf("Current URL: %s\n", currentUrl);

    printf("Checking if plugin is enabled...\n");
    int pluginEnabled = 1; // Assume plugin is enabled
    printf("Plugin is %s\n", pluginEnabled ? "enabled" : "disabled");

    // Run some plugin-specific operations
    printf("Running plugin-specific operations...\n");
    printf("Calculating factorial of 5...\n");
    int fact = 1;
    for(int i=2; i<=5; i++) {
        fact *= i;
    }
    printf("Factorial of 5 is %d\n", fact);

    pluginCleanup();
    return 0;
}