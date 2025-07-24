//FormAI DATASET v1.0 Category: Browser Plugin ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1024

bool isUrlValid(char *url) {
    // check if url is valid - starting with http:// or https://
    if (strncmp(url, "http://", 7) == 0 || strncmp(url, "https://", 8) == 0) {
        return true;
    }
    return false;
}

char* modifyUrl(char *url) {
    // modify url to include "c-plugin"
    char *modifiedUrl = malloc(strlen(url) + 11);
    strcpy(modifiedUrl, url);
    strcat(modifiedUrl, "?c-plugin");
    return modifiedUrl;
}

void processUrl(char *buffer) {
    char *urlStart = strstr(buffer, "http");
    if (urlStart != NULL) {
        char *urlEnd = strstr(urlStart, "\n");
        if (urlEnd != NULL) {
            char *url = malloc(urlEnd - urlStart + 1);
            strncpy(url, urlStart, urlEnd - urlStart);
            url[urlEnd - urlStart] = '\0';
            if (isUrlValid(url)) {
                char *modifiedUrl = modifyUrl(url);
                // modify buffer to include modifiedUrl
                int offset = urlStart - buffer;
                int lengthDiff = strlen(modifiedUrl) - strlen(url);
                int newLength = strlen(buffer) + lengthDiff;
                char *newBuffer = malloc(newLength + 1);
                memcpy(newBuffer, buffer, offset);
                memcpy(newBuffer + offset, modifiedUrl, strlen(modifiedUrl));
                memcpy(newBuffer + offset + strlen(modifiedUrl), buffer + offset + strlen(url), strlen(buffer) - offset - strlen(url));
                newBuffer[newLength] = '\0';
                printf("%s", newBuffer);
                free(newBuffer);
                free(modifiedUrl);
            } else {
                printf("%s", buffer);
            }
            free(url);
            return;
        }
    }
    printf("%s", buffer);
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, stdin)) {
        processUrl(buffer);
    }
    return 0;
}