//FormAI DATASET v1.0 Category: Browser Plugin ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare function prototype
void printPluginInfo(char* pluginName, char* version, char* author);

int main() {
    char pluginName[100];
    char version[20];
    char author[50];

    // Get plugin information from user
    printf("Enter plugin name: ");
    fgets(pluginName, 100, stdin);
    printf("Enter plugin version: ");
    fgets(version, 20, stdin);
    printf("Enter plugin author: ");
    fgets(author, 50, stdin);

    // Remove newline character from input
    pluginName[strcspn(pluginName, "\n")] = 0;
    version[strcspn(version, "\n")] = 0;
    author[strcspn(author, "\n")] = 0;

    // Call function to print plugin information
    printPluginInfo(pluginName, version, author);

    return 0;
}

// Define function to print plugin information
void printPluginInfo(char* pluginName, char* version, char* author) {
    printf("\n%s %s\n", pluginName, version);
    printf("Created by: %s", author);
    printf("\nScalable style!\n");
}