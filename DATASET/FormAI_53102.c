//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: curious
#include <stdio.h>
#include <string.h>

// Function to remove any non-alphanumeric characters from a URL
void sanitize_url(char *url) {

    // Loop through each character in the URL
    int i;
    for (i = 0; url[i] != '\0'; i++) {

        // Check if the character is alphanumeric or a forward slash
        if (!(url[i] >= 'a' && url[i] <= 'z') && 
            !(url[i] >= 'A' && url[i] <= 'Z') &&
            !(url[i] >= '0' && url[i] <= '9') &&
            url[i] != '/') {

            // Replace non-alphanumeric characters with a hyphen
            url[i] = '-';
        }
    }
}

int main() {

    // Prompt the user to enter a URL to sanitize
    printf("Please enter a URL to sanitize: ");
    char url[100];
    scanf("%s", url);

    // Sanitize the URL
    sanitize_url(url);

    // Print the sanitized URL
    printf("\nSanitized URL: %s\n", url);

    return 0;
}