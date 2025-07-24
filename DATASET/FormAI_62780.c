//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

void sanitize_url(char *url) {
    // Remove any trailing whitespaces
    int len = strlen(url);
    while (len > 0 && url[len - 1] == ' ') {
        url[--len] = '\0';
    }

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0) {
        // If not, add "http://" to the beginning
        char *new_url = malloc(len + 8);
        strcpy(new_url, "http://");
        strcat(new_url, url);
        free(url);
        url = new_url;
    }

    // Replace any occurences of " " with "%20"
    char *space = strstr(url, " ");
    while (space != NULL) {
        *space = '%';
        url = realloc(url, len + 3);
        memmove(space + 3, space + 1, len - (space - url) + 1);
        strncpy(space + 1, "20", 2);
        len += 2;
        space = strstr(url + (space - url) + 3, " ");
    }
}

int main() {
    char url1[] = "www.example.com";
    sanitize_url(url1);
    printf("%s\n", url1);

    char url2[] = "www.example.com/test page";
    sanitize_url(url2);
    printf("%s\n", url2);

    char url3[] = "https://www.example.com";
    sanitize_url(url3);
    printf("%s\n", url3);

    char url4[] = "http://www.example.com/test page";
    sanitize_url(url4);
    printf("%s\n", url4);

    return 0;
}