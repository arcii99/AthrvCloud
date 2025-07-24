//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char url[200];
    int i, len;
    printf("Enter URL: ");
    fgets(url, sizeof(url), stdin);  // Read input from user

    len = strlen(url);
    url[len - 1] = '\0';  // Remove newline character

    printf("Sanitized URL: ");

    for(i = 0; i < len; i++) 
    {
        if ((url[i] == '\'') || (url[i] == '\"') || (url[i] == '<') || (url[i] == '>') || (url[i] == '\\') || (url[i] == '`') || ((url[i] == '&') && (url[i+1] == '#'))) 
        {
            // Remove dangerous characters
        }
        else 
        {
            // Output sanitized URL
            putchar(url[i]);
        }
    }
    printf("\n\n");
    return 0;
}