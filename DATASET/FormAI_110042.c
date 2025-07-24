//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to sanitize the URL
void sanitize_url(char* url) {
    char sanitized_url[256] = {0};
    int index = 0;
    int len = strlen(url);
    int i;

    // Loop through all characters in URL
    for(i=0; i<len; i++) {
        char c = url[i];

        // Skip control characters and spaces
        if(!iscntrl(c) && !isspace(c)) {
            // Make sure character is lowercase
            if(isupper(c)) {
                c = tolower(c);
            }

            // Append character to sanitized URL
            sanitized_url[index++] = c;
        }
    }

    // Append null terminator to sanitized URL
    sanitized_url[index] = '\0';

    // Copy the sanitized URL back to the original URL string
    strcpy(url, sanitized_url);
}

int main() {
    char url[256] = "htTPS://wWw.Example.com/paTh/file.php?name=John+Doe&age=39";
    printf("Original URL: %s\n", url);

    // Sanitize the URL
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);

    return 0;
}