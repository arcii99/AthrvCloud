//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sanitize(char string[])
{
    int i, j = 0;
    char temp[strlen(string)];
    for (i = 0; i < strlen(string); i++)
    {
        if (isalnum(string[i]))
        {
            temp[j] = string[i];
            j++;
        }
    }
    temp[j] = '\0';
    strcpy(string, temp);
}

int main()
{
    char url[100];
    printf("Enter the url to sanitize: ");
    scanf("%s", url);
    printf("Original URL: %s\n", url);
    sanitize(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}