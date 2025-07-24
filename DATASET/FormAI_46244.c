//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sanitize_url(char *url) {
    int i, j = 0;
    char san_url[strlen(url) + 1];
    memset(san_url, 0, sizeof(san_url)); // sanitize san_url

    // replace all spaces with '%20'
    for (i = 0; i < strlen(url); i++) {
        if (isspace(url[i]))
            strcat(san_url, "%20");
        else
            san_url[j++] = url[i];
    }
    san_url[j] = '\0'; // null-terminate san_url

    // check if url starts with 'http://' or 'https://'
    char *prefix = strtok(san_url, ":");
    if (strcmp(prefix, "http") != 0 && strcmp(prefix, "https") != 0)
        printf("The URL should start with 'http://' or 'https://'\n");
    else {
        char *rest = strtok(NULL, ""); // get the rest of the url
        printf("%s:%s\n", prefix, rest);
    }
}

int main() {
    char url[100];
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = '\0'; // remove the trailing newline character
    sanitize_url(url);
    return 0;
}