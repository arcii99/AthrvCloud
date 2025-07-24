//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to remove invalid characters from the URL
char *sanitizeURL(char *url)
{
    char *dirtyURL = url;
    char *cleanURL = malloc(strlen(dirtyURL) * sizeof(char));
    int indexDirty = 0;
    int indexClean = 0;

    while (dirtyURL[indexDirty] != '\0')
    {
        if (isalnum(dirtyURL[indexDirty]) || dirtyURL[indexDirty] == '.' || dirtyURL[indexDirty] == '/')
        {
            cleanURL[indexClean] = dirtyURL[indexDirty];
            indexClean++;
        }
        indexDirty++;
    }

    cleanURL[indexClean] = '\0';
    free(dirtyURL);
    return cleanURL;
}

int main()
{
    char url[100];
    printf("Enter a URL: ");
    scanf("%s", url);

    // Sanitizing the URL
    char *sanitizedURL = sanitizeURL(url);

    printf("\nSanitized URL: %s\n", sanitizedURL);
    free(sanitizedURL);
    return 0;
}