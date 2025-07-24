//FormAI DATASET v1.0 Category: Browser Plugin ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char url[100];
} Website;

typedef struct {
    Website websites[10];
    int count;
} WebsiteList;

WebsiteList websitesList;

void initializeList() {
    websitesList.count = 0;
}

void addWebsite(char* name, char* url) {
    if (websitesList.count < 10) {
        Website newWebsite;
        strcpy(newWebsite.name, name);
        strcpy(newWebsite.url, url);
        websitesList.websites[websitesList.count] = newWebsite;
        websitesList.count++;
    }
}

void displayList() {
    printf("List of Favorite Websites: \n");
    for(int i = 0; i < websitesList.count; i++) {
        Website website = websitesList.websites[i];
        printf("%d. %s: %s\n", i+1, website.name, website.url);
    }
}

int main() {
    initializeList();

    addWebsite("Google", "https://www.google.com/");
    addWebsite("YouTube", "https://www.youtube.com/");
    addWebsite("Facebook", "https://www.facebook.com/");
    addWebsite("GitHub", "https://github.com/");
    addWebsite("Twitter", "https://twitter.com/");

    displayList();

    return 0;
}