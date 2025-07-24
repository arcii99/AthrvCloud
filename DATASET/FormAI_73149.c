//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValidURLChar(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.';
}

bool isValidProtocol(char* start, char* end) {
    if (end - start != 4) {
        return false;
    }

    return strncmp(start, "http", 4) == 0;
}

bool isDifferentHost(char* url1, char* url2) {
    char* host1 = strchr(url1, '/') + 2;
    char* host2 = strchr(url2, '/') + 2;

    return strcmp(host1, host2) != 0;
}

char* sanitizeURL(char* url) {
    char* start = url;
    char* end = url + strlen(url) - 1;

    // step 1: remove trailing slashes
    while (end >= start && *end == '/') {
        end--;
    }

    *(end + 1) = '\0';

    // step 2: validate protocol (http only)
    char* colon = strchr(start, ':');
    if (colon != NULL && colon < strchr(start, '/')) {
        if (!isValidProtocol(start, colon)) {
            printf("Error: invalid protocol\n");
            exit(1);
        }

        start = colon + 3; // move past protocol and colon
    }

    // step 3: remove default port numbers
    char* port = strchr(start, ':');
    char* slash = strchr(start, '/');
    if (port != NULL && (slash == NULL || port < slash)) {
        char* endPort = port + 1;
        while (*endPort >= '0' && *endPort <= '9') {
            endPort++;
        }

        int portNum = atoi(port + 1);
        if (portNum == 80) { // HTTP port
            start = slash + 1;
        } else {
            memmove(port, slash, strlen(slash) + 1);
        }
    }

    // step 4: remove fragments
    char* fragment = strchr(start, '#');
    if (fragment != NULL) {
        *fragment = '\0';
    }

    // step 5: remove query strings
    char* query = strchr(start, '?');
    if (query != NULL) {
        *query = '\0';
    }

    // step 6: remove duplicate slashes
    char* curr = start;
    char* prev = start;
    while (*curr != '\0') {
        if (*curr == '/') {
            if (prev == start || *(prev - 1) != '/') {
                *prev = '/';
                prev++;
            }
        } else if (isValidURLChar(*curr)) {
            *prev = *curr;
            prev++;
        }

        curr++;
    }
    *prev = '\0';

    // step 7: remove leading "www."
    char www[] = "www.";
    if (strncmp(start, www, 4) == 0) {
        char* newStart = start + 4;
        if (isDifferentHost(newStart, start)) {
            start = newStart;
        }
    }

    return start;
}

int main() {
    char* url = "http://www.google.com///search?q=example#results";

    char* sanitizedURL = sanitizeURL(url);

    printf("Sanitized URL: %s\n", sanitizedURL);

    return 0;
}