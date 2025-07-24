//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to check if character is valid in a URL
bool isValid(char ch)
{
    return (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') ||
            (ch == '-') || (ch == '_') || (ch == '.');
}

// Function to sanitize the input URL
void sanitize(char *url)
{
    int len = strlen(url);
    char prev = '\0';
    for(int i=0; i<len; i++)
    {
        if(isValid(url[i]))
        {
            prev = url[i];
        }
        else
        {
            if(prev != '-')
            {
                url[i] = '-';
                prev = '-';
            }
        }
    }
}

int main()
{
    char url[1000];
    printf("Enter a URL to sanitize: ");
    scanf("%s", url);
    
    sanitize(url);
    
    printf("Sanitized URL: %s", url);
    
    return 0;
}