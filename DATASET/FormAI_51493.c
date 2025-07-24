//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_url[500], sanitized_url[500];
    int i, j = 0;

    printf("Welcome to the URL Sanitizer program!\n\nPlease enter a URL to be sanitized:\n");
    scanf("%s", input_url);

    // Check if URL starts with "http://" or "https://", add if it doesn't
    if (strstr(input_url, "http://") == NULL && strstr(input_url, "https://") == NULL) {
        strcpy(sanitized_url, "http://");
        j += 7;
    }

    // Loop through the input URL and remove any invalid characters
    for (i = 0; i < strlen(input_url); i++) {
        if (isalnum(input_url[i]) || input_url[i] == '.' || input_url[i] == '/' || input_url[i] == ':') {
            sanitized_url[j] = input_url[i];
            j++;
        }
    }

    // Add terminating character
    sanitized_url[j] = '\0';

    printf("\nSanitized URL: %s\n", sanitized_url);

    return 0;
}