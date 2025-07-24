//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* This function will remove all non-alphanumeric characters
 * except for a few special characters that are allowed in URLs
 * (i.e. '.', '-', '_', and '~').
 *
 * It will also convert all alphabetic characters to lowercase.
 */
char *sanitize_url(char *url) {
    int i, j, len;
    char *sanitized;

    // Count the number of allowed special characters
    int special_chars[] = {'.', '-', '_', '~'};
    int num_special_chars = sizeof(special_chars) / sizeof(special_chars[0]);
    int num_allowed_chars = num_special_chars + 26 + 10;

    // Allocate space for the sanitized string
    len = strlen(url);
    sanitized = (char *) malloc(len + 1);
    if (sanitized == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    // Copy the original string and convert to lowercase
    for (i = 0; url[i] != '\0'; i++) {
        sanitized[i] = tolower(url[i]);
    }
    sanitized[i] = '\0';

    // Remove non-alphanumeric characters
    for (i = 0, j = 0; sanitized[j] != '\0'; j++) {
        if (isalnum(sanitized[j]) || strchr(special_chars, sanitized[j])) {
            sanitized[i++] = sanitized[j];
        }
    }
    sanitized[i] = '\0';

    return sanitized;
}

int main() {
    char *url = "https://www.Example.com/Data?size=10&offset=20";
    char *sanitized;

    printf("Original URL:\n%s\n\n", url);

    sanitized = sanitize_url(url);

    printf("Sanitized URL:\n%s\n", sanitized);

    free(sanitized);

    return 0;
}