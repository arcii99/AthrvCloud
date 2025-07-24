//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: accurate
#include<stdio.h>
#include<string.h>
int main()
{
    char url[100], sanitizedUrl[100]="", temp[10];
    int i, j, len;

    // Taking input from user
    printf("Enter the URL to be sanitized: ");
    scanf("%s", url);

    // Appending https:// if not present
    if(strncmp(url, "https://", 8) != 0 && strncmp(url, "http://", 7) != 0)
        strcat(sanitizedUrl, "https://");

    // Checking for invalid characters in the URL
    for(i=0; i<strlen(url); i++)
    {
        if((url[i]>='A' && url[i]<='Z') || (url[i]>='a' && url[i]<='z') || 
           (url[i]>='0' && url[i]<='9') || (url[i]=='-') || (url[i]=='_'))
            strncat(sanitizedUrl, &url[i], 1);
        else if(url[i] == '.')
            strncat(sanitizedUrl, &url[i], 1);
        else
        {
            sprintf(temp, "%x", url[i]);
            strcat(sanitizedUrl, "%");
            strcat(sanitizedUrl, temp);
        }
    }

    // Removing any trailing slashes or dots
    len = strlen(sanitizedUrl);
    if(sanitizedUrl[len-1] == '/' || sanitizedUrl[len-1] == '.')
        sanitizedUrl[len-1] = '\0';

    // Printing the sanitized URL
    printf("\nSanitized URL: %s\n", sanitizedUrl);

    return 0;
}