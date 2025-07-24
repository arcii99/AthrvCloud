//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char url[100], sanitized_url[100];
    int i, j = 0, len;

    printf("Enter the URL you want to sanitize: ");
    scanf("%s", url);

    len = strlen(url);

    /* Remove any whitespace from the user input */
    for (i = 0; i < len; i++) {
        if (isspace(url[i])) {
            continue;
        } else {
            sanitized_url[j] = url[i];
            j++;
        }
    }
    sanitized_url[j] = '\0';

    /* Check if the URL starts with "http://" or "https://" */
    if (strncmp(sanitized_url, "http://", 7) != 0 && strncmp(sanitized_url, "https://", 8) != 0) {
        printf("Invalid URL! Please make sure the URL starts with 'http://' or 'https://'.\n");
        return 0;
    }

    /* Remove any trailing slashes in the URL */
    len = strlen(sanitized_url);
    if (sanitized_url[len - 1] == '/') {
        sanitized_url[len - 1] = '\0';
    }

    /* Print the sanitized URL */
    printf("The sanitized URL is: %s\n", sanitized_url);

    return 0;
}