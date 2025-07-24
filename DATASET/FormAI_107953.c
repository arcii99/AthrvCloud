//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char url[1000];
    printf("Enter a URL to be sanitized: ");
    fgets(url, 1000, stdin);
    url[strcspn(url, "\n")] = '\0'; // Remove the trailing newline character

    printf("Sanitized URL: ");

    // Remove any spaces before or after the URL
    char *start = url, *end = url + strlen(url) - 1;
    while (isspace(*start)) start++;
    while (isspace(*end) && end >= start) end--;
    *(end + 1) = '\0';

    // Check if the URL starts with "http://" or "https://"
    char *prefix = "http://";
    if (strncmp(url, prefix, strlen(prefix)) != 0) {
        prefix = "https://";
        if (strncmp(url, prefix, strlen(prefix)) != 0) {
            printf("Invalid URL - must start with 'http://' or 'https://'\n");
            return 0;
        }
    }

    // Remove the prefix from the URL
    char *new_url = url + strlen(prefix);

    // Remove any trailing '/' characters
    end = new_url + strlen(new_url) - 1;
    while (*end == '/') end--;
    *(end + 1) = '\0';

    // Print the sanitized URL
    printf("%s%s\n", prefix, new_url);

    return 0;
}