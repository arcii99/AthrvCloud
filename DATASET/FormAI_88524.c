//FormAI DATASET v1.0 Category: Browser Plugin ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* This is an example of a browser plugin that blocks certain websites */

/* The website block list */
char blockedWebsites[5][20] = {"facebook.com", "twitter.com", "instagram.com", "youtube.com", "reddit.com"};

/* The plugin initialization function */
bool init(void) {
    /* There is nothing to initialize here */
    return true;
}

/* The plugin blocking function */
bool blockWebsite(char* url) {
    int i;
    bool isBlocked = false;
    /* Check if the website is in the block list */
    for(i = 0; i < 5; i++) {
        if(strcmp(url, blockedWebsites[i]) == 0) {
            isBlocked = true;
            break;
        }
    }
    /* If the website is blocked, print a message and return false */
    if(isBlocked) {
        printf("Website %s is blocked by the browser plugin.\n", url);
        return false;
    }
    /* If the website is not blocked, return true */
    return true;
}

/* The plugin cleanup function */
bool cleanup(void) {
    /* There is nothing to clean up here */
    return true;
}

int main() {
    /* Test the plugin with some example URLs */
    char url1[] = "facebook.com";
    char url2[] = "example.com";
    if(blockWebsite(url1)) {
        printf("Access granted to %s.\n", url1);
    }
    if(blockWebsite(url2)) {
        printf("Access granted to %s.\n", url2);
    }
    return 0;
}