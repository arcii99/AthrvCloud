//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to sanitize URL
char* sanitize_url(char *url) {

    char *buffer = (char*) malloc(strlen(url) + 1);
    char *p, *q;

    p = url;
    q = buffer;

    // Loop through each character in the URL
    while(*p != '\0') {
        if((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z') || (*p >= '0' && *p <= '9') ||
        (*p == '.') || (*p == '/') || (*p == '-') || (*p == '_')) {
            *q++ = *p++;
        } else {
            p++;
        }
    }

    *q = '\0';

    return buffer;
}

int main()
{
    char *url = "https://www.google.com//search?q=C URL Sanitizer&sa=X&ved=2ahUKEwiZ78mu3Y_4AhVJzK0KHU9aB5IQ7xYoAXoECBwQEQ";
    char *sanitized_url;

    sanitized_url = sanitize_url(url);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);

    free(sanitized_url);
    return 0;
}