//FormAI DATASET v1.0 Category: Browser Plugin ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024
#define MAX_PLUGIN_NAME 50

typedef struct {
    char url[MAX_URL_LENGTH];
} BrowserTab;

typedef struct {
    char name[MAX_PLUGIN_NAME];
    void (*func)(BrowserTab*);
} Plugin;

void defaultPlugin(BrowserTab* tab) {
    printf("This page does not have a plugin attached.\n");
}

void youtubePlugin(BrowserTab* tab) {
    printf("Now playing: %s on YouTube\n", tab->url);
}

void wikipediaPlugin(BrowserTab* tab) {
    printf("Welcome to Wikipedia! You are currently viewing: %s\n", tab->url);
    char searchQuery[100];
    printf("Please enter something you'd like to search for: ");
    fgets(searchQuery, 100, stdin);
    // Remove newline character from input
    searchQuery[strcspn(searchQuery, "\n")] = 0;
    char wikipediaUrl[MAX_URL_LENGTH];
    sprintf(wikipediaUrl, "https://en.wikipedia.org/w/index.php?search=%s", searchQuery);
    printf("Opening url: %s\n", wikipediaUrl);
    // Open new tab with wikipedia url
    BrowserTab newTab;
    strcpy(newTab.url, wikipediaUrl);
    openNewTab(&newTab);
}

Plugin plugins[] = {
    {"Default", defaultPlugin},
    {"YouTube", youtubePlugin},
    {"Wikipedia", wikipediaPlugin}
};

void openNewTab(BrowserTab* tab) {
    printf("Opening url: %s\n", tab->url);
    // Do some fancy stuff to actually open a new browser tab...
    int pluginIndex;
    for (pluginIndex = 0; pluginIndex < 3; pluginIndex++) {
        if (strstr(tab->url, plugins[pluginIndex].name) != NULL) {
            plugins[pluginIndex].func(tab);
            break;
        }
    }
    if (pluginIndex == 3) {
        defaultPlugin(tab);
    }
}

int main() {
    BrowserTab myTab;
    strcpy(myTab.url, "https://www.youtube.com/watch?v=dQw4w9WgXcQ");
    openNewTab(&myTab);
    printf("\n");
    strcpy(myTab.url, "https://en.wikipedia.org/wiki/Great_Pyramid_of_Giza");
    openNewTab(&myTab);
    printf("\n");
    strcpy(myTab.url, "https://www.google.com/");
    openNewTab(&myTab);
    printf("\n");
    return 0;
}