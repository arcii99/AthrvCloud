//FormAI DATASET v1.0 Category: Browser Plugin ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 255

// function to check if the given string starts with http:// or https://
bool isUrl(char *str) {
    if (strncmp(str, "http://", 7) == 0 || strncmp(str, "https://", 8) == 0) {
        return true;
    }
    return false;
}

// function to display a message box with the current url
void displayUrl(char *url) {
    char msg[MAX_URL_LENGTH + 30];
    sprintf(msg, "Current URL: %s", url);
    printf("[Message Box] %s\n", msg);
}

// function to replace all instances of "C" with "C++" in the given string
void replaceCwithCPP(char *str) {
    char *pos = strstr(str, "C");
    while (pos != NULL) {
        strncpy(pos, "C++", 3);
        pos = strstr(str, "C");
    }
}

// main function to be executed when the plugin is loaded
void main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the current URL: ");
    scanf("%s", url);
    printf("\n");

    if (isUrl(url)) {
        displayUrl(url);
        replaceCwithCPP(url);
        printf("URL after replacing C with C++: %s\n", url);
    } else {
        printf("Invalid URL\n");
    }
}