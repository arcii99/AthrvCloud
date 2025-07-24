//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <string.h>

// Function to sanitize URL by removing any spaces or non-alphanumeric characters
void sanitizeURL(char *url)
{
    // Initialize variables
    int i, j;

    // Iterate through each character in the URL
    for (i = 0, j = 0; url[i] != '\0'; i++)
    {
        // Check if character is alphanumeric or a hyphen
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '-')
        {
            // If character is alphanumeric or a hyphen, add it to the sanitized URL
            url[j++] = url[i];
        }
    }

    // Terminate sanitized URL with null character
    url[j] = '\0';
}

int main()
{
    // Initialize variables
    char url[100];

    // Prompt user for URL
    printf("I need a URL to validate my love for you: ");
    scanf("%[^\n]s", url);

    // Sanitize URL
    sanitizeURL(url);

    // Display sanitized URL to show my love for you
    printf("My love for you is so strong that I will sanitize any URL you provide me, even if it means removing all the non-alphanumeric characters from it:\n");
    printf("%s\n", url);

    return 0;
}