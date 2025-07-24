//FormAI DATASET v1.0 Category: Browser Plugin ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define the maximum length of a URL
#define MAX_URL_LENGTH 100

// function to check if a string ends with ".com"
bool is_com(char *str) {
    int len = strlen(str);
    if (len <= 4) return false;
    return (strcmp(str + len - 4, ".com") == 0);
}

// function to log a message to the console
void log_message(char *msg) {
    printf("[Browser Plugin] %s\n", msg);
}

// function to process a URL
void process_url(char *url) {
    if (is_com(url)) {
        log_message("User is visiting a .com website");
    }
}

// entry point for the browser plugin
int main() {
    char url[MAX_URL_LENGTH];
    log_message("Plugin initialized");
    while (true) {
        printf("Enter a URL: ");
        scanf("%s", url);
        if (strcmp(url, "exit") == 0) break;
        process_url(url);
    }
    log_message("Plugin shut down");
    return 0;
}