//FormAI DATASET v1.0 Category: Browser Plugin ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_URL_LENGTH 256

bool isUnsafe(char c) {
    // These are the characters that we consider unsafe
    char unsafeChars[] = {'<', '>', '[', ']', '{', '}', '(', ')', '`', '\'', '|', '\\', '^', '~', '%', ';',};
    int numChars = sizeof(unsafeChars) / sizeof(unsafeChars[0]);
    for(int i=0; i<numChars; i++) {
        if(c == unsafeChars[i]) {
            return true;
        }
    }
    return false;
}

char* sanitizeUrl(char* url) {
    int urlLength = strlen(url);
    char* sanitizedUrl = (char*) malloc(MAX_URL_LENGTH * sizeof(char));
    int j=0;
    for(int i=0; i<urlLength; i++) {
        if(!isUnsafe(url[i])) {
            sanitizedUrl[j++] = url[i];
        }
    }
    sanitizedUrl[j] = '\0';
    return sanitizedUrl;
}

void logRequest(char* url) {
    FILE *f = fopen("request.log", "a");
    if (f == NULL) {
        printf("Error opening log file!");
        return;
    }
    time_t currentTime;
    time(&currentTime);
    char* sanitizedUrl = sanitizeUrl(url);
    fprintf(f, "%s: %s\n", ctime(&currentTime), sanitizedUrl);
    free(sanitizedUrl);
    fclose(f);
}

int main() {
    char url[MAX_URL_LENGTH];
    printf("Enter the URL:\n");
    scanf("%s", url);

    char* sanitizedUrl = sanitizeUrl(url);
    if(strcmp(url, sanitizedUrl) != 0) {
        printf("Unsafe characters detected in URL. Aborting.\n");
    } else {
        logRequest(url);
        printf("Request logged successfully.\n");
    }

    free(sanitizedUrl);
    return 0;
}