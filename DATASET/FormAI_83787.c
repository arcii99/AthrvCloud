//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: statistical
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Function to sanitize URL
void sanitizeURL(char **url)
{
    // Create a new string to hold the sanitized URL
    char *sanitized = (char*) malloc(strlen(*url) + 1);
    memset(sanitized, '\0', strlen(*url) + 1);
    int j = 0;
    for(int i=0; i<strlen(*url); i++)
    {
        // Check to see if character is alphanumeric
        if((*url)[i] >= '0' && (*url)[i] <= '9' || (*url)[i] >= 'a' && (*url)[i] <= 'z' || (*url)[i] >= 'A' && (*url)[i] <= 'Z')
        {
            sanitized[j] = (*url)[i];
            j++;
        }
        // Check to see if character is a special character
        else if((*url)[i] == '.' || (*url)[i] == '/' || (*url)[i] == '-' || (*url)[i] == '_')
        {
            sanitized[j] = (*url)[i];
            j++;
        }
    }
    // Null terminate the sanitized string
    sanitized[j] = '\0';
    // Free the original URL string
    free(*url);
    // Assign the sanitized string to the original URL
    *url = sanitized;
}

// Driver code
int main()
{
    char *url = "https://www.ex@ample.com/home?query=example*";
    printf("Original URL: %s\n", url);
    sanitizeURL(&url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}