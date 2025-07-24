//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char url[100];
    int i, j = 0;
    
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    
    for (i = 0; i < strlen(url); i++)
    {
        if (isalnum(url[i]) || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '?' || url[i] == '&' || url[i] == '=') 
        {
            url[j] = url[i];
            j++;
        }
    }
    
    url[j] = '\0';
    
    printf("Sanitized URL: %s\n", url);
    
    return 0;
}