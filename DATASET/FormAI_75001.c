//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LENGTH 1024

char sanitized_url[MAX_URL_LENGTH];

int sanitize_url(char* url) {
    int i, j;
    char current_char;
    int url_length = strlen(url);

    if (url_length > MAX_URL_LENGTH) {
        perror("Error: URL length exceeds maximum limit!\n");
        return 1;
    }

    // Copy scheme to sanitized URL
    for (i = 0; url[i] != ':'; i++) {
        sanitized_url[i] = url[i];
    }

    i += 3; // Skip "://"

    // Copy domain to sanitized URL
    for (j = i; url[j] != '\0' && url[j] != '/'; j++) {
        sanitized_url[j] = url[j];
    }

    // Append "/" to sanitized URL
    sanitized_url[j] = '/';

    j++;

    // Copy path to sanitized URL
    for (; j < url_length; j++) {
        if (url[j] == '%') {
            // Check if the next two characters are hexadecimal digits
            if (isxdigit(url[j+1]) && isxdigit(url[j+2])) {
                // Append decoded character to sanitized URL
                current_char = (char) strtol(&url[j+1], NULL, 16);
                sanitized_url[i] = current_char;
                i++;
                j += 2;
            } else {
                // If not, append '%'
                sanitized_url[i] = url[j];
                i++;
            }
        } else {
            // Append current character to sanitized URL
            sanitized_url[i] = url[j];
            i++;
        }
    }

    // Terminate sanitized URL string
    sanitized_url[i] = '\0';

    return 0;
}

int main() {
    char url[MAX_URL_LENGTH];
    int status;

    printf("Enter a URL to sanitize:\n");
    fgets(url, MAX_URL_LENGTH, stdin);

    // Remove newline character from input
    url[strcspn(url, "\n")] = '\0';

    status = sanitize_url(url);

    if (status == 0) {
        printf("Sanitized URL:\n%s\n", sanitized_url);
    }

    return 0;
}