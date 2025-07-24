//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 150

void sanitize(char* url) {
    const char* blacklist[] = {"script", "alert", "onload", "onclick", "onerror", "document", "eval", "expression", "javascript"};
    const int NUM_BLACKLIST = sizeof(blacklist)/sizeof(blacklist[0]);

    char* sanitized_url = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    sanitized_url[0] = '\0';

    for (int i = 0; i < strlen(url); i++) {
        int match_found = 0;

        for (int j = 0; j < NUM_BLACKLIST; j++) {
            int length = strlen(blacklist[j]);

            if (strncmp(&url[i], blacklist[j], length) == 0) {
                match_found = 1;
                i += length;
                break;
            }
        }

        if (match_found == 0) {
            strncat(sanitized_url, &url[i], 1);
        }
    }

    strncpy(url, sanitized_url, MAX_URL_LENGTH);
    free(sanitized_url);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter URL: ");
    scanf("%s", url);

    sanitize(url);

    printf("Sanitized URL: %s\n", url);
    return 0;
}