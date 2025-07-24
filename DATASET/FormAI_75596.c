//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to sanitize URL by removing unwanted characters
void sanitize_url(char* url) {
    int i, j;
    bool found;
    const char* valid_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_.";

    // Replace any space characters with %20
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == ' ') {
            url[i] = '%';
            url[i+1] = '2';
            url[i+2] = '0';
        }
    }

    // Remove any characters that are not in the set of valid characters
    for (i = 0; url[i] != '\0'; i++) {
        found = false;
        for (j = 0; valid_chars[j] != '\0'; j++) {
            if (url[i] == valid_chars[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            strcpy(&url[i], &url[i+1]);
            i--;
        }
    }

    // Remove any double occurrences of the '-' or '.' characters
    for (i = 0; url[i] != '\0'; i++) {
        if (url[i] == '-' && url[i+1] == '-') {
            int k;
            for (k = i+1; url[k] != '\0'; k++) {
                url[k] = url[k+1];
            }
            i--;
        }
        if (url[i] == '.' && url[i+1] == '.') {
            int k;
            for (k = i+1; url[k] != '\0'; k++) {
                url[k] = url[k+1];
            }
            i--;
        }
    }
}

int main() {
    char url[100];
    printf("Enter a URL to sanitize: ");
    fgets(url, 100, stdin);
    url[strcspn(url, "\n")] = 0;  // Remove newline character from input

    printf("\nSanitizing URL...\n");
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}