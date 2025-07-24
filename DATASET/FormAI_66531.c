//FormAI DATASET v1.0 Category: Browser Plugin ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

// Configurable settings
#define MAX_KEYWORDS 100
const char *KEYWORDS[MAX_KEYWORDS] = {"apple", "banana", "cherry", "orange", "pear"};

// Function to check if the given URL contains any of the keywords
bool check_url(const char* url) {
    int i, j;
    char url_copy[500];
    strcpy(url_copy, url);
    char *token = strtok(url_copy, "://.-");
    while (token != NULL) {
        for (i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        for (j = 0; j < MAX_KEYWORDS; j++) {
            if (strcmp(token, KEYWORDS[j]) == 0) {
                return true;
            }
        }
        token = strtok(NULL, "://.-");
    }
    return false;
}

// Function to modify HTML content to add a custom message to the page
void modify_html(const char* url, char* html) {
    char message[1000];
    sprintf(message, "<h1>This page contains the keyword '%s'</h1>", KEYWORDS[rand() % MAX_KEYWORDS]);
    char *head = strstr(html, "<head>");
    if (head != NULL) {
        head += strlen("<head>");
        char *insertion_point = strstr(head, "</head>");
        if (insertion_point != NULL) {
            memmove(insertion_point + strlen(message), insertion_point, strlen(insertion_point) + 1);
            strncpy(insertion_point, message, strlen(message));
        }
    }
}

// Function to be called when the browser loads a new page
void on_page_load(const char* url, char* html) {
    if (check_url(url)) {
        modify_html(url, html);
    }
}

// Function to be called when the plugin is initialized
void plugin_init() {
    printf("Plugin initialized\n");
}

// Function to be called when the plugin is shut down
void plugin_shutdown() {
    printf("Plugin shut down\n");
}

// Entry point
int main() {
    // Simulate browser behavior by loading some example pages and passing them to on_page_load
    char html1[10000] = "<html><head><title>Example page</title></head><body><p>This page is an example.</p></body></html>";
    on_page_load("https://www.example.com/page1", html1);
    char html2[10000] = "<html><head><title>Another page</title></head><body><p>This page is different.</p></body></html>";
    on_page_load("https://www.example.com/page2", html2);
    char html3[10000] = "<html><head><title>Contains keyword</title></head><body><p>This page contains the word apple.</p></body></html>";
    on_page_load("https://www.example.com/page3", html3);
    
    // Initialize and shut down the plugin
    plugin_init();
    plugin_shutdown();

    return 0;
}