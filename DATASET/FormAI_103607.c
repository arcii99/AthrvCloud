//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to remove special characters from string
void sanitize(char *url_string)
{
    int len = strlen(url_string);
    char *new_url = (char*) malloc(len+1);
    int j = 0;
    for(int i=0; i<len; i++)
    {
        if(isalnum(url_string[i]))
        {
            new_url[j++] = url_string[i];
        }
    }
    new_url[j] = '\0';
    strcpy(url_string, new_url);
    free(new_url);
}

int main()
{
    char url[100];
    printf("Enter the URL to sanitize: ");
    scanf("%s",url);

    // check if http or https is included in the URL
    if(strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0)
    {
        printf("Invalid URL. Please enter a valid URL starting with http:// or https://");
        return 0;
    }

    sanitize(url);

    printf("\nSanitized URL: %s\n",url);

    return 0;
}