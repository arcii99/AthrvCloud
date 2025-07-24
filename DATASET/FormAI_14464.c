//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Ken Thompson
#include <string.h>
#include <stdio.h>

void sanitize_url(char *url) {
    // Remove any leading or trailing spaces
    while (*url == ' ') {
        url++;
    }
    if (*url == '\0') {
        return;
    }
    char *end = url + strlen(url) - 1;
    while (end > url && *end == ' ') {
        end--;
    }
    *(end+1) = '\0';

    // Check if the URL starts with "http://" or "https://"
    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        url += 8;
    }

    // Remove any duplicate slashes (e.g. "http://example//com" becomes "http://example/com")
    char *src = url;
    char *dst = url;
    char last_char = '\0';
    while (*src != '\0') {
        if (*src == '/' && last_char == '/') {
            src++;
        } else {
            *dst++ = *src++;
            last_char = *(dst-1);
        }
    }
    *dst = '\0';

    // Remove any "." and ".." segments from the path (e.g. "http://example.com/../foo/bar" becomes "http://example.com/foo/bar")
    src = url;
    dst = url;
    while (*src != '\0') {
        if (*src == '.' && *(src+1) == '/') {
            // Remove current directory segment ("./")
            src += 2;
        } else if (*src == '.' && *(src+1) == '.' && *(src+2) == '/') {
            // Remove parent directory segment ("../")
            src += 3;
            while (dst > url && *--dst != '/') {}
        } else {
            while (*src != '\0' && *src != '/') {
                *dst++ = *src++;
            }
            if (*src != '\0') {
                *dst++ = *src++;
            }
        }
    }
    *dst = '\0';
}

int main() {
    char url1[] = "  http://example.com/../foo/bar  ";
    printf("Initial url1: %s\n", url1);
    sanitize_url(url1);
    printf("Sanitized url1: %s\n", url1);

    char url2[] = "http://example//com/";
    printf("Initial url2: %s\n", url2);
    sanitize_url(url2);
    printf("Sanitized url2: %s\n", url2);

    char url3[] = "https://example.com/./foo/bar/baz/../";
    printf("Initial url3: %s\n", url3);
    sanitize_url(url3);
    printf("Sanitized url3: %s\n", url3);

    return 0;
}