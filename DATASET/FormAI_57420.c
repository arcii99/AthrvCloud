//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: satisfied
#include<stdio.h>
#include<string.h>

int main()
{
    char url[1000];

    printf("Enter URL: ");
    scanf("%[^\n]", url);

    int len = strlen(url);

    // Removing protocol if present
    if(strncmp(url, "http://", 7) == 0)
        strcpy(url, url + 7);
    
    if(strncmp(url, "https://", 8) == 0)
        strcpy(url, url + 8);

    // Removing www if present
    if(strncmp(url, "www.", 4) == 0)
        strcpy(url, url + 4);

    // Sanitizing special characters
    for(int i=0; i<len; i++)
    {
        if(url[i]==' ' || url[i]=='<' || url[i]=='>' || url[i]=='#' || url[i]=='%' || url[i]=='{' || url[i]=='}' || url[i]=='|' || url[i]=='\\' || url[i]=='^' || url[i]=='~' || url[i]=='[' || url[i]==']' || url[i]=='`')
        {
            url[i] = '-';
        }
    }

    printf("Sanitized URL: %s", url);

    return 0;
}