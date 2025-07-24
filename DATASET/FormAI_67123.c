//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// This function takes a URL as input and removes any unsafe characters, returns a sanitized URL.
char* sanitize_url(char *url) {
    char *sanitized_url = (char*)malloc(strlen(url)+1); // Allocate memory for the new sanitized URL
    int j = 0; // Used as an index in the sanitized URL

    for (int i = 0; i < strlen(url); i++) {
        // Check if the current character is safe
        if ((url[i] >= 'A' && url[i]<='Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i]<= '9') ||
            url[i] == '.' || url[i] == '_' || url[i] == '-' || url[i] == '~' || url[i] == '/') {
            sanitized_url[j++] = url[i]; // Add the safe character to the sanitized URL
        }
        else if (url[i] == ' ') {
            sanitized_url[j++] = '+'; // Replace spaces with '+'
        }
        else {
            snprintf(&sanitized_url[j], 4, "%%%02X", url[i]); // Convert the unsafe character to hex code and add to the sanitized URL
            j += 3; // Increment j by 3 as the hex code takes up 3 characters
        }
    }
    sanitized_url[j] = '\0'; // Add null terminator to end of the sanitized URL
    return sanitized_url;
}

int main(int argc, char* argv[]) {
    char url[] = "http://example.com/path with spaces/to/file.html?foo=bar&baz=qux"; // Example URL with unsafe characters

    char *sanitized_url = sanitize_url(url);

    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url); // Remember to free the memory used by the sanitized URL
    return 0;
}