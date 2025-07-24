//FormAI DATASET v1.0 Category: Browser Plugin ; Style: configurable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

typedef struct Url {
    char path[MAX_URL_LENGTH];
    bool isSecure;
    char* query;
} Url;

void printUrl(Url* url) {
    printf("%s\n", url->path);
    printf("Is Secure: %s\n", url->isSecure ? "true" : "false");
    printf("Query: %s\n", url->query);
}

void parseUrl(char* urlStr, Url* url) {
    // Parse path
    char* separator = strstr(urlStr, "://");
    if (separator != NULL) {
        url->isSecure = true;
        separator += 3; // Skip over "://"
    } else {
        url->isSecure = false;
        separator = urlStr; // Assume no protocol in URL
    }
    char* pathEnd = strchr(separator, '/');
    if (pathEnd == NULL) {
        pathEnd = urlStr + strlen(urlStr); // URL consists only of domain name
    }
    int pathLength = pathEnd - separator;
    strncpy(url->path, separator, pathLength);
    url->path[pathLength] = '\0';

    // Parse query string
    char* queryStart = strchr(pathEnd, '?');
    if (queryStart != NULL) {
        url->query = strdup(queryStart + 1);
    } else {
        url->query = NULL;
    }
}

int main() {
    char* urlStr = "https://www.google.com/search?q=chatbot&rlz=1C1GCEU_enUS832US832&oq=chatbot&aqs=chrome.0.35i39l2j0l4j46j69i60l3.2116j1j4&sourceid=chrome&ie=UTF-8";
    Url url;
    parseUrl(urlStr, &url);
    printUrl(&url);
    return 0;
}