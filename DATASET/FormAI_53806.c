//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sanitize_url(char*);

int main()
{
    char url[100];
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}

void sanitize_url(char* url)
{
    int len = strlen(url);
    int i, j;
    char temp[len+1];
    for(i=0, j=0; i<len; i++)
    {
        if(url[i] == '.')
        {
            if(i>0 && url[i-1] == '/')
            {
                continue;
            }
            if(i<len-1 && url[i+1] == '/')
            {
                continue;
            }
        }
        temp[j++] = url[i];
    }
    temp[j] = '\0';
    strcpy(url, temp);
    len = strlen(url);
    for(i=0; i<len; i++)
    {
        url[i] = tolower(url[i]);
    }
    if(url[len-1] == '/')
    {
        url[len-1] = '\0';
    }
}