//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_LENGTH 256

void sanitize_url(char url[]) {
    int i, j, len;
    char new_url[URL_LENGTH];
    len = strlen(url);

    // Check if URL has HTTP or HTTPS before the domain
    if (strncasecmp(url, "http://", 7) != 0) {
        if (strncasecmp(url, "https://", 8) != 0) {
            // If there is no HTTP or HTTPS, add HTTP:// to the beginning
            strncpy(new_url, "http://", 7);
            j = 7;
        } else {
            j = 8;
        }
    } else {
        j = 7;
    }

    // Traverse the URL character by character
    for (i = j; i < len; i++) {
        // If character is a valid URL character, store it in new_url
        if ((url[i] >= 'a' && url[i] <= 'z') ||
            (url[i] >= 'A' && url[i] <= 'Z') ||
            (url[i] >= '0' && url[i] <= '9') ||
            url[i] == '.' || url[i] == '/' ||
            url[i] == ':' || url[i] == '?' || url[i] == '=') {
            
            new_url[j] = url[i];
            j++;

            // If new_url is at maximum capacity, break the loop
            if (j == URL_LENGTH - 1) {
                break;
            }
        }
    }

    // Add null terminator to end of new_url
    new_url[j] = '\0';

    // Copy sanitized URL to original URL variable
    strcpy(url, new_url);
}

int main() {
    // Example URLs to sanitize
    char url1[] = "example.com";
    char url2[] = "https://www.example.com/test/page?var1=abc&var2=123";
    char url3[] = "http://www.example.com/subdirectory:test?var1=abc";

    // Sanitize each URL
    sanitize_url(url1);
    sanitize_url(url2);
    sanitize_url(url3);

    // Print sanitized URLs
    printf("Sanitized URL 1: %s\n", url1);
    printf("Sanitized URL 2: %s\n", url2);
    printf("Sanitized URL 3: %s\n", url3);

    return 0;
}