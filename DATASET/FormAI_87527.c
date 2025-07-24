//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

// Function to remove trailing whitespace from a string
void rtrim(char *str) {
    int len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[--len] = '\0';
    }
}

// Function to sanitize a string (in this case, a URL)
void sanitize(char *url) {
    char *temp = (char *)malloc(MAX_LENGTH * sizeof(char));
    int len = strlen(url);
    int size = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(url[i])) {
            temp[size++] = url[i];
        } else if (url[i] == '.' || url[i] == '/') {
            temp[size++] = url[i];
        }
    }
    temp[size] = '\0';
    rtrim(temp);
    strcpy(url, temp);
    free(temp);
}

int main() {
    char url[MAX_LENGTH];
    printf("Enter a URL: ");
    fgets(url, MAX_LENGTH, stdin);
    rtrim(url);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}