//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>

/* Function to check if a character is non-alphanumeric */
int isNonAlphaNumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
        return 0;
    }
    return 1;
}

/* Function to remove non-alphanumeric characters from a string */
void removeNonAlphaNumeric(char* string) {
    int len = strlen(string);
    int i, j = 0;
    for (i = 0; i < len; i++) {
        if (!isNonAlphaNumeric(string[i])) {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0';
}

/* Function to convert string to lowercase */
void toLowercase(char* string) {
    int i;
    int len = strlen(string);
    for (i = 0; i < len; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32;
        }
    }
}

/* Function to sanitize a URL */
void sanitizeURL(char* url) {
    /* Convert to lowercase */
    toLowercase(url);

    /* Remove non-alphanumeric characters */
    removeNonAlphaNumeric(url);
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, 100, stdin);

    /* Remove newline character at the end */
    url[strcspn(url, "\n")] = '\0';

    /* Sanitize URL */
    sanitizeURL(url);

    printf("Sanitized URL: %s\n", url);

    return 0;
}