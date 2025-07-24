//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_URL_LEN 2048 

bool isUrlValid(char url[]) {
    int len = strlen(url);
    if (len > 7 && len < MAX_URL_LEN && strncmp("http://", url, 7) == 0) {
        return true;
    }
    return false;
}

void sanitizeUrl(char url[]) {
    int len = strlen(url);
    int j = 7; // ignore "http://"
    for (int i = 7; i < len; i++) {
        if (isalnum(url[i])) { 
            url[j++] = url[i];
        } else if (isspace(url[i])) { // replace spaces with '%20'
            url[j++] = '%';
            url[j++] = '2';
            url[j++] = '0';
        }
        // ignore any other character
    }
    url[j] = '\0';
}

int main() {
    char url[MAX_URL_LEN];
    printf("Enter a valid URL: ");
    fgets(url, MAX_URL_LEN, stdin);
    url[strcspn(url, "\n")] = '\0'; // remove '\n' from fgets result
    if (isUrlValid(url)) {
        sanitizeUrl(url);
        printf("Sanitized URL: %s\n", url);
    } else {
        printf("Invalid URL. URL should start with 'http://' and be smaller than %d characters.\n", MAX_URL_LEN);
    }
    return 0;
}